#pragma once

#include"SFML/Graphics.hpp"

#include"Button.h"
#include"TextLabel.h"
#include"Ball.h"

class Menu {
public:
	Menu(sf::RenderWindow &window);
	~Menu();
	void onEvent(const sf::Event event,sf::RenderWindow &target);
	void draw(sf::RenderTarget &target);
	void update(float frameTime);

	bool getPlayTrigger() { return playTrigger; }
	void setPlayTrigger(bool a_bool) { playTrigger = a_bool; }

private:
	ui::Button *startButton;
	//ui::Button *quitButton;

	sf::Font font;
	ui::TextLabel *titleText;

	Ball *ball; // Menu ball for comedic effect

	bool playTrigger;
};