#include"Ball.h"

Ball::Ball() {
	start();
}

Ball::~Ball() {

}

void Ball::start() {
	shape.setFillColor(sf::Color::Blue);
	shape.setRadius(BALL_RADIUS);
	shape.setPointCount(8);
	shape.setPosition(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

	velocityVector = sf::Vector2f(velocityX, velocityY);
}

void Ball::update(float frameTime) {
	shape.move(velocityVector*frameTime);

	this->wall_collision();
}

void Ball::wall_collision() {
	// Collision for right,left and top walls NOT bottom wall
	if (shape.getPosition().x < 0)
		velocityVector.x *= -1;
	else if (shape.getPosition().x > WINDOW_WIDTH - BALL_RADIUS * 2)
		velocityVector.x *= -1;
	else if (shape.getPosition().y < 0)
		velocityVector.y *= -1;
}

void Ball::resetPosition() {

}