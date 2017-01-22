#include"Brick.h"

Brick::Brick(sf::Vector2f pos) {
	shape.setPosition(pos);
	start(); // Used for initializing 

			 // Setup brick size
	shape.setFillColor(sf::Color(200, 10, 20));
	shape.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT));

#pragma region Brick State Assign
	// Give the brick a state choosen randomly out of all the brickStates
	int rand_ = rand() % 12;

	if (rand_ >= 0 && rand_ <= 7) {
		state = brickStates::NORMAL;
	}
	if (rand_ >= 8 && rand_ <= 10) {
		state = brickStates::DOUBLE_HIT;
	}
	else if (rand_ == 11) {
		state = brickStates::DIAMOND;
	}

	//state = brickStates::NORMAL;
	if (state == brickStates::DIAMOND) {
		shape.setFillColor(sf::Color::Cyan);
	}
	if (state == brickStates::DOUBLE_HIT) {
		shape.setFillColor(sf::Color::Green);
		life++;
	}
#pragma endregion
}

void Brick::start() {


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
	shape.setPosition(0, 0);
}