#include "Particle.h"

void Particle::update(float deltaTime)
{
	if (!alive())
		return;

	framesLeft_ -= 1 * deltaTime;
	shape.move(xVelocity*deltaTime, yVelocity*deltaTime);
}

void Particle::init(double a_x, double a_y, double a_velocityX, double a_velocityY, int a_lifeTime)
{
	shape.setRadius(3);
	shape.setFillColor(sf::Color::White);

	shape.setPosition(a_x, a_y);
	xVelocity = a_velocityX;
	yVelocity = a_velocityY;

	framesLeft_ = a_lifeTime;
}
