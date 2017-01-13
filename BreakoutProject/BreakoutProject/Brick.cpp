#include"Brick.h"

Brick::Brick(sf::Vector2f pos) {
	shape.setPosition(pos);
	start(); // Used for initializing 

			 // Setup brick size
	shape.setFillColor(sf::Color(200, 10, 20));
	shape.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT));

#pragma region Brick State Assign
	// Give the brick a state choosen randomly out of all the brickStates
	srand(time(NULL));
	int rand_ = rand() % 5;

	if (rand_ == 0 || rand_ == 1) {
		state = brickStates::NORMAL;
		printf("Normal Brick");
	}
	if (rand_ == 2 || rand_ == 3) {
		state = brickStates::DOUBLE_HIT;
		printf("Double Brick");
	}
	else if (rand_ == 4) {
		state = brickStates::DIAMOND;
		printf("Diamond Brick");
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