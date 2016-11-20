/*
* Holds basic game loops
* Core of the game
*/

#pragma once

#include"SFML\Graphics.hpp"
#include"Constants.h"
#include"Scene.h"

class Game {
public: 
	Game();
	~Game();
	int run();
	void createWindow();

private:
	bool isRunning;
	sf::RenderWindow renderWindow;
	enum GameState{MENU,PLAYING};
	GameState gameState;
};