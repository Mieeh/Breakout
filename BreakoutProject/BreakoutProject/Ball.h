#pragma once

#include"GameObject.h"
#include"Constants.h"

class Ball : GameObject {
public:
	Ball();
	~Ball();

	void start() override;
	void update(float frameTime) override;
	void resetPosition() override;
	sf::Shape &getShape()override { return shape; }

	/////////////////////
	// \brief Checks for wall collisions only
	// 
	/////////////////////
	void wall_collision();

	/////////////////////
	// \brief Checks for wall colli
	// 
	/////////////////////
	void paddle_collision();

private:
	sf::CircleShape shape;

	// Move attributes
	sf::Vector2f	 velocityVector;	// The direction of the ball
	double			 velocityX=0.2;		// Speed of the ball in the x direction
	double			 velocityY=-0.2;	// Speed of the ball in the y direction

};