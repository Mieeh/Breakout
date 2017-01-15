#include"Scene.h"
#include<iostream>

Scene::Scene() {
	player = new Paddle();
	ball = new Ball();

	if (!font.loadFromFile("arial.ttf")) {}

	scoreText = new ui::TextLabel(font, "Score", 22);

	lifeText = new ui::TextLabel(font, "Life", 22);
	lifeText->setPosition(sf::Vector2f(scoreText->getActualText().getLocalBounds().width*2.2f, 0));

	newBoardSetup();
}

Scene::~Scene() {
	delete player;
	delete ball;
}

void Scene::draw(sf::RenderTarget &target) {
	target.clear(sf::Color(30, 30, 25));

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

void Scene::update(float frameTime) {
	player->update(frameTime);

	ball->bricks_collision(bricks);
	player->collision(*ball); // Pings the ball when collided with the *ball

	#pragma region Game Over Logic
	if (m_life <= 0) {
		m_gameOver = true;
	}
	#pragma endregion

	#pragma region Ball OOB
	if (ball->getShape().getPosition().y > WINDOW_HEIGHT) {
		m_life--;
		ball->freezToPaddle();
	}
	#pragma endregion

	#pragma region Ball to Paddle freeze
	if (!ball->isFroozenToPaddle())
		ball->update(frameTime);
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
				brickParticlePool.create((*it)->getShape().getPosition().x + BRICK_WIDTH/2, (*it)->getShape().getPosition().y + BRICK_HEIGHT/2, ((rand() % 100) -50), ((rand() % 100) -50), 0, 125 + rand() % 100, 250);

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
	if (bricks.size() <= 0)
		levelClear();
	#pragma endregion

	#pragma Update Particles
	brickParticlePool.update(frameTime);
	#pragma endregion
}