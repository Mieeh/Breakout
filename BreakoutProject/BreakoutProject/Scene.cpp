#include"Scene.h"
#include<iostream>

Scene::Scene() {
	player = new Paddle();
	ball = new Ball();

	if (!font.loadFromFile("arial.ttf")) {}

	scoreText = new ui::TextLabel(font, "Score", 22);

	lifeText = new ui::TextLabel(font, "Life", 22);
	lifeText->setPosition(sf::Vector2f(scoreText->getActualText().getLocalBounds().width*2.2f, 0));

	m_shakeTrigger = true;

	newBoardSetup();
}

Scene::~Scene() {
	delete player;
	delete ball;
}

void Scene::draw(sf::RenderTarget &target, sf::RenderWindow &gameWindow) {
	target.clear(sf::Color(30,45,40));

	// Draw ball particles
	ball->draw(target);

	// Draw the Paddle and the Ball
	target.draw(player->getShape());
	target.draw(ball->getShape());

	// Draw brick particles, under the bricks 
	brickParticlePool.drawParticles(target);

	// Draw all the bricks inside the bricks vector
	// The vector contains pointers to the objects
	for (Brick *brick : bricks) {
		target.draw(brick->getShape());
	}

	#pragma region Render UI

	scoreText->setText("Score: " + std::to_string(m_score));
	scoreText->draw(target);

	lifeText->setText("Life: " + std::to_string(m_life));
	lifeText->draw(target);
	 
	#pragma endregion

	#pragma Screen Shaking
	if (m_shakeTrigger) {
		m_posBeforeShake = (gameWindow.getPosition());
		m_shakeTrigger = false;
	}
	if (m_shake) {
		gameWindow.setPosition(sf::Vector2i(m_posBeforeShake.x + rand() % 20, m_posBeforeShake.y + rand() % 20));
	}
	if (!m_shake) {
		gameWindow.setPosition(m_posBeforeShake);
	}
	#pragma endregion
}

void Scene::onEvent(const sf::Event event) {
	player->onEvent((sf::Event&)event);

	#pragma region Raw Input 
	// If space is pressed unfreeze the ball from the paddle
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space)
			ball->unfreezeFromPaddle();
	}
	#pragma endregion
}

void Scene::newBoardSetup() {
	// Init stuff
	m_score = 0;
	m_life = 3;
	m_gameOver = false;

	brickParticlePool.clearParticlePool();

	bricks.clear();
	// Fills the bricks vector with new bricks
	// This loop represents y value
	for (int current_column = 0; current_column < 4; current_column++) {
		// This loop represents x value
		for (int x = 0; x < 6; x++) {
			// Create and fill the bricks vector here
			bricks.push_back(new Brick(sf::Vector2f((x+0.16) * BRICK_OFFSET_X,(current_column+.5) * BRICKS_OFFSET_Y)));
		}
	}
}

void Scene::levelClear() {
	// Freeze ball to paddle 
	ball->freezToPaddle();
	ball->clearParticles();

	// TODO: Create some kind of progression in difficulty here

	bricks.clear();
	// Fills the bricks vector with new bricks
	// This loop represents y value
	for (int current_column = 0; current_column < 4; current_column++) {
		// This loop represents x value
		for (int x = 0; x < 6; x++) {
			// Create and fill the bricks vector here
			bricks.push_back(new Brick(sf::Vector2f((x + 0.16) * BRICK_OFFSET_X, (current_column + .5) * BRICKS_OFFSET_Y)));
		}
	}
}

void Scene::triggerShake()
{
	// Start shaking if we're not already shaking
	if (!m_shake) {
		m_shakeTrigger = true;
		m_shakeTick = 0;
		m_shake = true;
	}
}

bool Scene::boardCleared()
{
	// Checks if there's only diamond bricks left, if that is true then board is cleared
	for (int i = 0; i < bricks.size(); i++) {
		if (bricks.at(i)->getBrickState() != Brick::brickStates::DIAMOND)
			return false;
	}
	return true;
}

void Scene::update(float frameTime) {
	player->update(frameTime);

	ball->bricks_collision(bricks);
	player->collision(*ball); // Pings the ball when collided with the *ball

	#pragma region Game Over Logic
	if (m_life <= 0) {
		/* 
		* LEADERBOARD
		* When leaderborard logic is implemented
		* Here is where m_score will be sent to the database
		*/
		m_gameOver = true;
	}
	#pragma endregion

	#pragma region Ball OOB
	if (ball->getShape().getPosition().y > WINDOW_HEIGHT) {
		ball->clearParticles(); // Remove any remaining particles left when the ball crashes
		m_life--;
		ball->freezToPaddle();
	}
	#pragma endregion

	#pragma region Ball to Paddle freeze
	if (!ball->isFroozenToPaddle()) {
		ball->update(frameTime);
	}
	else
		ball->getShape().setPosition(sf::Vector2f(player->getShape().getPosition().x + (PADDLE_WIDTH / 2) - BALL_RADIUS, player->getShape().getPosition().y - PADDLE_HEIGHT * 1.75));
	#pragma endregion

	#pragma region Bricks vector removal
	// Iterating through bricks to remove the dead ones
	std::vector<Brick*>::iterator it;
	for (it = bricks.begin(); it != bricks.end(); ) {
		if ((*it)->getIsDead()) {
			// Spawn particles at bricks.at(it)->getPosition() here
			for(int i = 0; i < 25; i++)
				brickParticlePool.create((*it)->getShape().getPosition().x + BRICK_WIDTH/2, (*it)->getShape().getPosition().y + BRICK_HEIGHT/2, ((rand() % 100) -50), ((rand() % 100) -50), 0, 125 + rand() % 100, 250, (*it)->getShape().getFillColor());

			triggerShake();
			delete *it;			  
			it = bricks.erase(it);
			m_score+=10;
		}
		else {
			++it;
		}
	}
	#pragma endregion

	#pragma region Level Clear
	if (boardCleared())
		levelClear();
	#pragma endregion

	#pragma Update Particles
	brickParticlePool.update(frameTime);
	#pragma endregion

	#pragma region Camera Shake
	if (m_shake) {
		m_shakeTick += frameTime;
		if (m_shakeTick >= m_shakeLength) {
			m_shake = false;
			m_shakeTick = 0;
		}
	}
	#pragma endregion
}