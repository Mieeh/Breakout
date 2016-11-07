#pragma once

#include"SFML\Graphics.hpp"

class GameObject {
public:
	virtual ~GameObject(){ }
	/////////////////////
	// \brief Called when the game starts
	//
	/////////////////////
	virtual void start() = 0;

	/////////////////////
	// \brief Called every frame of the game
	//
	/////////////////////
	virtual void update(float deltaTime) = 0;

	/////////////////////
	// \brief Should returns the game objects sprite
	//
	/////////////////////
	virtual sf::Shape &getShape() = 0;
};