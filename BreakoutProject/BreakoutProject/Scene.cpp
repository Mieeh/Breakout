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
	for (Brick * brick : bricks) {
		target.draw(brick->getShape());
	}
}

void Scene::onEvent(const sf::Event event) {
	player->onEvent((sf::Event&)event);
}

void Scene::newBoardSetup() {
	player = new Paddle();
	ball = new Ball();
	// Fills the bricks vector with new bricks
	// This loop represents y value
	for (int current_column = 0; current_column < 1; current_column++) {
		// This loop represents x value
		for (int x = 0; x < 1; x++) {
			// Create and fill the bricks vector here
			bricks.push_back(new Brick(sf::Vector2f((x+1+7) * BRICK_OFFSET_X,(current_column+.5) * BRICKS_OFFSET_Y)));
		}
	}
}

void Scene::update(float frameTime) {
	player->update(frameTime);
	ball->update(frameTime);

	ball->bricks_collision(bricks);
	player->collision(*ball); // Pings the ball when collided with
}