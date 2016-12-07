#pragma once

#include"GameObject.h"
#include"Constants.h"
#include"Brick.h"
#include"Paddle.h"
#include<vector>

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
	// \brief Checks for wall collision
	// 
	/////////////////////
	void paddle_collision(float hitFactor);

	/////////////////////
	// \brief Checks for collision,
	// \brief with any of the objects inside the bricks vector
	// 
	/////////////////////
	void bricks_collision(std::vector<Brick*> bricks);

	/*
	* Getters and setters for froozenToPaddle
	*/
	void freezToPaddle() { froozenToPaddle = true; }
	void unfreezeFromPaddle() { froozenToPaddle = false; }
	bool isFroozenToPaddle() { return froozenToPaddle; }

private:
	sf::CircleShape shape;
	bool froozenToPaddle;				// On true set position

	// Move attributes
	double			 velocityX=0.2;		// Speed of the ball in the x direction
	double			 velocityY=-0.4;	// Speed of the ball in the y direction
};