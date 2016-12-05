#include"Ball.h"

Ball::Ball() {
	start();
}

Ball::~Ball() {

}

void Ball::start() {
	// Ball setup, color, size and position
	shape.setFillColor(sf::Color::Blue);
	shape.setRadius(BALL_RADIUS);
	shape.setPointCount(32);
	shape.setPosition(sf::Vector2f((WINDOW_WIDTH / 2) - BALL_RADIUS, WINDOW_HEIGHT / 2));
	shape.setOrigin(0, 0);
}

void Ball::update(float frameTime) {
	shape.move(sf::Vector2f(velocityX*frameTime, velocityY*frameTime)); // Move the ball accordingly

	this->wall_collision();
}

void Ball::wall_collision() {
	// Collision for right,left and top walls NOT bottom wall
	if (shape.getPosition().x < 0)
		velocityX *= -1;
	if (shape.getPosition().x > WINDOW_WIDTH - BALL_RADIUS * 2)
		velocityX *= -1;
	if (shape.getPosition().y < 0)
		velocityY *= -1;
}

void Ball::paddle_collision(float hitFactor) {
	velocityY *= -1;
}

void Ball::bricks_collision(std::vector<Brick*> bricks)
{
	for (int i = 0; i < bricks.size(); i++) {
		if (shape.getGlobalBounds().intersects(bricks.at(i)->getShape().getGlobalBounds())) {
			//printf("BALL COLLIDED WITH A BRICK");
			//bricks.at(i)->getShape().setFillColor(sf::Color::Blue);

			sf::FloatRect ballBoundingBox = shape.getGlobalBounds();
			sf::FloatRect brickBoundingBox = shape.getGlobalBounds();

			if (ballBoundingBox.top >= brickBoundingBox.height || ballBoundingBox.height <= brickBoundingBox.top) 
				if(ballBoundingBox.left > brickBoundingBox.left && ballBoundingBox.width < brickBoundingBox.width)
					velocityY *= -1;

			else if (ballBoundingBox.width <= brickBoundingBox.left) {
				printf("Hello");
				velocityX *= -1;
			}
		}
	}
}

void Ball::resetPosition() {
	shape.setPosition(sf::Vector2f(0, 0));
}