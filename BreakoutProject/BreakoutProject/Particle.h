#pragma once

#include"SFML\Graphics.hpp"
#include"GameObject.h"

class Particle{
public:
	
	void update(float deltaTime);
	sf::Shape &getShape() {	return shape; }

	void init(double a_x, double a_y, double a_velocityX, double a_velocityY, double a_accX, double a_accY, int a_lifeTime, sf::Color a_startColor);
	bool alive() const { return framesLeft_ > 0; }

	void clear() { framesLeft_ = 0; }

private:
	int framesLeft_, orgFramesLeft_;
	sf::CircleShape shape;
	double xVelocity, yVelocity;
	double xAcc, yAcc;
};