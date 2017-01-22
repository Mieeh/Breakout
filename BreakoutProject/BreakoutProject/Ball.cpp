#include"Ball.h"
#include<cmath>

Ball::Ball() {
	start();
}

Ball::~Ball() {

}

void Ball::start() {
	// Ball setup, color, size and position
	shape.setFillColor(sf::Color(187, 15, 31));
	shape.setRadius(BALL_RADIUS);
	shape.setPointCount(32);
	shape.setPosition(sf::Vector2f((WINDOW_WIDTH / 2) - BALL_RADIUS, WINDOW_HEIGHT / 2));
	froozenToPaddle = true;
}

void Ball::update(float frameTime) {
	shape.move(sf::Vector2f((velocityX * velocityScale)*frameTime, (velocityY * velocityScale)*frameTime)); // Move the ball as usual

	particleEmitter.update(frameTime); // Updates particle objects and moves lifeTime forwards

	// Creates particles at shape.position with a velocity inverted to this objects velocity
	particleEmitter.create(shape.getPosition().x + shape.getRadius(), shape.getPosition().y+shape.getRadius(), rand() % 30 - (15), rand() % 30 - (15), 0, 0, 60, sf::Color(rand() % 255, rand() % 255, rand() % 255));

	this->wall_collision();
}

void Ball::wall_collision() {
	// Collision for right,left and top walls NOT bottom wall

	// Left bounds
	if (shape.getPosition().x < 0) {
		shape.setPosition(sf::Vector2f(0, shape.getPosition().y));
		velocityX *= -1;
	}
	// Right bounds
	if (shape.getPosition().x > WINDOW_WIDTH - BALL_RADIUS * 2) {
		shape.setPosition(sf::Vector2f(WINDOW_WIDTH - BALL_RADIUS * 2, shape.getPosition().y));
		velocityX *= -1;
	}
	if (shape.getPosition().y < 0) {
		shape.setPosition(sf::Vector2f(shape.getPosition().x, 0));
		velocityY *= -1;
	}
}

void Ball::bricks_collision(std::vector<Brick*> bricks)
{
	
	for (int i = 0; i < bricks.size(); i++) {
		if (shape.getGlobalBounds().intersects(bricks.at(i)->getShape().getGlobalBounds())) {
			velocityScale += 0.05f;

			//bricks.at(i)->getShape().setFillColor(sf::Color::Blue);
			if (shape.getPosition().y <= bricks.at(i)->getShape().getPosition().y) {
				//printf("Over");
				bricks.at(i)->loseLife();
				velocityY *= -1;
				return;
			}
			if (shape.getPosition().y >= bricks.at(i)->getShape().getPosition().y+BRICK_HEIGHT-11) {
				//printf("Under");
				bricks.at(i)->loseLife();
				velocityY *= -1;
				return;
			}
			if(shape.getPosition().x >= bricks.at(i)->getShape().getPosition().x + BRICK_WIDTH-11) {
				//printf("Right");
				bricks.at(i)->loseLife();
				velocityX *= -1;
				return;
			}
			if (shape.getPosition().x <= bricks.at(i)->getShape().getPosition().x) {
				//printf("Left");
				bricks.at(i)->loseLife();
				velocityX *= -1;
				return;
			}
		}
	}
}

void Ball::draw(sf::RenderTarget & target)
{
	particleEmitter.drawParticles(target);
}

void Ball::clearParticles()
{
	particleEmitter.clearParticlePool();
}

void Ball::resetPosition() {
	shape.setPosition(sf::Vector2f(0, 0));
}

void Ball::paddle_collision(float hitFactor) {
	velocityY *= -1;
}