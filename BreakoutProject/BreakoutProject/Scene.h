#pragma once

#include"SFML\Graphics.hpp"
#include"Paddle.h"
#include"Ball.h"
#include"Brick.h"
#include<vector>
#include"Button.h"
#include"TextLabel.h"

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

	/////////////////////
	// \brief Same as newBoardSetup but no value resets
	//  called when player cleared a level
	/////////////////////
	void levelClear();

	/////////////////////
	// \brief Functions for controlling when to change game state
	// used by Game.cpp mainly since that's where GameState is located
	/////////////////////
	bool getGameOver() { return m_gameOver; }
	void setGameOver(bool a_bool) { m_gameOver = a_bool; }

private:
	Paddle *player; // Paddle instance ie player
	Ball *ball; // Ball instance 
	std::vector<Brick*> bricks; // All the bricks for the game

	sf::Font font;
	ui::TextLabel *scoreText;
	ui::TextLabel *lifeText;

	int m_score; // Number of bricks our player has taken out
	int m_life; // Number of tries before the game goes to menu

	bool m_gameOver;
};
#endif