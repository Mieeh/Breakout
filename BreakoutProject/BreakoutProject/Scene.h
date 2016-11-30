#pragma once

#include"SFML\Graphics.hpp"
#include"Paddle.h"
#include"Ball.h"
#include"Brick.h"
#include<vector>

#ifndef SCENE
#define SCENE

/*
* This class will hold all the game objects
* All of the main game objects will be used here
* Core class of the game
*/

class Scene {
public:
	Scene();
	~Scene();
	void onEvent(const sf::Event event);
	void draw(sf::RenderTarget &target);
	void update(float frameTime);

	/////////////////////
	// \brief Sets up a new board with new bricks
	// 
	/////////////////////
	void newBoardSetup();

private:
	Paddle *player; // Paddle instance ie player
	Ball *ball; // Ball instance 
	std::vector<Brick*> bricks; // All the bricks for the game
};
#endif