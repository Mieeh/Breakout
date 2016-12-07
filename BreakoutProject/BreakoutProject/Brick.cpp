#include"Brick.h"

Brick::Brick(sf::Vector2f pos) {
	shape.setPosition(pos);
	start(); // Used for initializing 
}

void Brick::start() {
	// Setup brick size
	shape.setFillColor(sf::Color::Red);
	shape.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT));

	#pragma region Brick State Assign
	// Give the brick a state choosen randomly out of all the brickStates
	srand(time(NULL));
	int rand_ = rand() % 5;
	if (rand_ >= 0 && rand_ <= 2)
		state = brickStates::NORMAL;
	else if (rand_ == 3)
		state = brickStates::DOUBLE_HIT;
	else if (rand_ == 4)
		state = brickStates::DIAMOND;

	if (state == brickStates::DIAMOND) {
		shape.setFillColor(sf::Color::Cyan);
	}
	if (state == brickStates::DOUBLE_HIT) {
		shape.setFillColor(sf::Color::Green);
		life++;
	}
#pragma endregion

}

void Brick::loseLife() {
	if (state != brickStates::DIAMOND) {
		life--;
		if (life == 0) {
			dead = true;
		}
	}
}

void Brick::update(float frameTime) {

}

void Brick::resetPosition() {

}