#include"Scene.h"

Scene::Scene() {
	newBoardSetup();
}

Scene::~Scene() {

}

void Scene::draw(sf::RenderTarget &target) {
	// Draw the Paddle and the Ball
	target.draw(player->getShape());
	target.draw(ball->getShape());

	// Draw all the bricks inside the bricks vector
	// The vector contains pointers to the objects
	for (Brick *brick : bricks) {
		target.draw(brick->getShape());
	}
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
	player = new Paddle();
	ball = new Ball();

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

void Scene::update(float frameTime) {
	player->update(frameTime);

	ball->bricks_collision(bricks);
	player->collision(*ball); // Pings the ball when collided with the *ball

	#pragma region Ball OOB
	if (ball->getShape().getPosition().y > WINDOW_HEIGHT)
		ball->freezToPaddle();
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
			delete *it;			  
			it = bricks.erase(it);
		}
		else {
			++it;
		}
	}
	#pragma endregion
}