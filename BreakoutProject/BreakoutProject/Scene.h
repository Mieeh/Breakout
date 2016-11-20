#pragma once

#include"SFML\Graphics.hpp"
#include"Paddle.h"
#include"Ball.h"

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
private:
	Paddle *player;
	Ball *ball;
};