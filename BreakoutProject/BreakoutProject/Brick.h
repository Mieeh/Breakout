#pragma once

#include"GameObject.h"
#include"Constants.h"

/* 
* Class for the destroyable bricks in the game
* Static rectangles that responds when the ball hits it
* Response is dependant on the "state" 
*/

class Brick : GameObject {
public:
	/*
	* Not yet a needed implementations into the class
	void changeState(brickStates state);
	*/
	Brick(sf::Vector2f pos);
	~Brick();

	// Interface operations
	void start() override;
	void update(float frameTime) override;
	void resetPosition() override;
	sf::Shape &getShape()override { return shape; }

private:
	sf::RectangleShape shape;
	
	/*
	* On hit:
	* NORMAL - Destroyed in one hit
	* DIAMOND - Can't be destroyed
	* DOUBLE_HIT - Required two hits to get destroyed
	*/
	enum brickStates{NORMAL, DIAMOND, DOUBLE_HIT}; 
	brickStates state;
};