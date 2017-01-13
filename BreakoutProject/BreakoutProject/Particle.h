#pragma once

#include"SFML\Graphics.hpp"
#include"GameObject.h"

class Particle{
public:
	
	void update(float deltaTime);
	sf::Shape &getShape() {	return shape; }

	void init(double a_x, double a_y, double a_velocityX, double a_velocityY, int a_lifeTime);
	bool alive() const { return framesLeft_ > 0; }

private:
	int framesLeft_;
	sf::CircleShape shape;
	double xVelocity, yVelocity;
};