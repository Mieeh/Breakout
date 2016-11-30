#include"Brick.h"

Brick::Brick(sf::Vector2f pos) {
	shape.setPosition(pos);
	start(); // Used for initializing 
}

Brick::~Brick() {
	delete this;
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
		state = Brick::brickStates::NORMAL;
	else if (rand_ == 3)
		state = Brick::brickStates::DOUBLE_HIT;
	else if (rand_ == 4)
		state = Brick::brickStates::DIAMOND;
#pragma endregion

}
void Brick::update(float frameTime) {

}

void Brick::resetPosition() {

}