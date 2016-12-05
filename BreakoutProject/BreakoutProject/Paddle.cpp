#include"Paddle.h"
#include<iostream>

Paddle::Paddle() {
	start();
}

Paddle::~Paddle() {
	
}

void Paddle::start() {
	// Move attributes
	currentVelocity = 0;
	moveDirection = 0;

	// Coloring, re-sizing and setting position
	shape.setFillColor(sf::Color::Red);
	shape.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
	shape.setPosition(WINDOW_WIDTH/2 - (PADDLE_WIDTH / 2), WINDOW_HEIGHT - PADDLE_HEIGHT * 5);
}

void Paddle::update(float frameTime) {
	this->move(frameTime);
}

void Paddle::onEvent(sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		// Move postively
		if (event.key.code == sf::Keyboard::D)
			moveDirection = 1;
		if (event.key.code == sf::Keyboard::A)
			moveDirection = -1;
		moveState_ = moveStates::MOVING;		// ie. We are supposed to be moving
	}
	if (event.type == sf::Event::KeyReleased) {
		moveState_ = moveStates::NOT_MOVING;	// ie. We are not supposed to be moving
		moveDirection = 0; // Move negativly
		currentVelocity = 0;
	}
}

void Paddle::move(float frameTime) {
	// velocity = v0 + a * t
	// v0 = 0, a = accerlation, t = frameTime
	if (moveState_ == moveStates::MOVING) {
		currentVelocity += accerlation;			// Apply accerlation to our current velocity 
		if (currentVelocity >= maxVelocity)		// Checking if we hit maximum velocity
			currentVelocity = maxVelocity;		// Constrain velocity to maximum velocity
	}
	if (moveState_ == moveStates::NOT_MOVING) {
		currentVelocity = 0; // Stop the paddle with no inertia 
	}

	//std::cout << currentVelocity << std::endl;	// Print current velocity for debugging
	shape.move(sf::Vector2f((currentVelocity * moveDirection) * frameTime, 0));
}

void Paddle::resetPosition() {
	shape.setPosition(sf::Vector2f(0, 0));
}

void Paddle::collision(Ball& ball) {
	// Checks for ball and wall collisions
	// Ball Collision
	if (shape.getGlobalBounds().intersects(ball.getShape().getGlobalBounds())) {
		// TODO: Implement hit factor functionality
		float hitFactor = 1; // Distance from the middle point of paddle to the balls middle point
		//hitFactor = (shape.getPosition().x + (PADDLE_WIDTH / 2)) - (ball.getShape().getPosition().x - BALL_RADIUS);
		//std::cout << hitFactor << std::endl;
		ball.paddle_collision(hitFactor); // Sending message to the ball that collision with paddle happend
	}

	// When colliding with a wall velocity becomes zero
	// Constraining paddle to the screen dimensions
	if (shape.getPosition().x < 0)
		shape.setPosition(sf::Vector2f(0, shape.getPosition().y));
	else if (shape.getPosition().x > WINDOW_WIDTH - shape.getSize().x)
		shape.setPosition(sf::Vector2f(WINDOW_WIDTH - shape.getSize().x, shape.getPosition().y));
}