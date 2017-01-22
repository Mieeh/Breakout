#pragma once

#include"Menu.h"
#include"Constants.h"

Menu::Menu(sf::RenderWindow &window) {
	if (!font.loadFromFile("arial.ttf")) {
		printf("Wat");
	}

	startButton = new ui::Button(sf::Vector2f(97, 45), sf::Color(160, 35, 57));
	startButton->SetRectPosition(sf::Vector2f((WINDOW_WIDTH/2)-(97/2), WINDOW_HEIGHT/2));

	startButton->setFont(font);
	startButton->setCharSize(20);
	startButton->setString("Play");
	startButton->setTextColor(sf::Color(255, 119, 61));
	startButton->centerTextWithinRect();

	titleText = new ui::TextLabel(font, "Breakout", 69);
	titleText->setColor(sf::Color(255, 119, 61));
	titleText->centerText(window);
	titleText->setPosition(sf::Vector2f(titleText->getPosition().x, titleText->getPosition().y - 145));

	ball = new Ball();
}

Menu::~Menu() {

}

void Menu::onEvent(const sf::Event event, sf::RenderWindow &target)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (startButton->isMouseInside(static_cast<sf::Vector2f>(sf::Mouse::getPosition(target)))) {
			setPlayTrigger(true);
		}
	}
}

void Menu::draw(sf::RenderTarget & target)
{
	target.draw(ball->getShape());

	// UI elements rendered on top
	target.clear(sf::Color(30, 30, 25));
	startButton->draw(target);
	titleText->draw(target);
}

void Menu::update(float frameTime)
{
	ball->update(frameTime);
}