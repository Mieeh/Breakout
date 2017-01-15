#include "Particle.h"

void Particle::update(float deltaTime)
{
	if (!alive())
		return;

	framesLeft_ -= 1 * deltaTime;

	xVelocity += xAcc*deltaTime;
	yVelocity += yAcc*deltaTime;

	shape.move(xVelocity*deltaTime, yVelocity*deltaTime);

	float ageRation = framesLeft_ / orgFramesLeft_;
	shape.setRadius(lerp(ageRation, 10, shape.getRadius()));
}

void Particle::init(double a_x, double a_y, double a_velocityX, double a_velocityY, double a_accX, double a_accY, int a_lifeTime)
{
	shape.setRadius(3);
	shape.setFillColor(sf::Color::White);

	shape.setPosition(a_x, a_y);
	xVelocity = a_velocityX;
	yVelocity = a_velocityY;

	xAcc = a_accX;
	yAcc = a_accY;

	orgFramesLeft_ = a_lifeTime;
	framesLeft_ = orgFramesLeft_;
}
