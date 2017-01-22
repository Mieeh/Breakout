#pragma once

#include"GameObject.h"
#include"Ball.h"

#include"Constants.h"

class Paddle : public GameObject {
public:
	Paddle();
	~Paddle() override;
	void start() override;
	void update(float frameTime) override;
	void resetPosition() override; 
	sf::Shape &getShape()override { return shape; }

	/////////////////////
	// \brief Handles input for movement
	// 
	/////////////////////
	void onEvent(sf::Event &event);

	/////////////////////
	// \brief Moves the player with inertia
	// 
	/////////////////////
	void move(float frameTime);

	/////////////////////
	// \brief Handles collision with the ball and the window bounds
	// \brief When collided with ball send signal to ball that it has to bounce and the position of the collision
	/////////////////////
	void collision(Ball &ball); 

private:
	sf::RectangleShape shape;
	int moveDirection;
	double maxVelocity = 0.75*1000;
	double currentVelocity;
	const double accerlation = 0.065*1000;

	enum moveStates{MOVING, NOT_MOVING}; // Paddle move states to controll inertia
	moveStates moveState_; // Represents the current move state of this paddle
};