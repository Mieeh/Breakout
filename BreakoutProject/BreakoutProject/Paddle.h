#pragma once

#include"GameObject.h"

#include"Constants.h"

class Paddle : public GameObject {
public:
	Paddle();
	~Paddle();
	void update(float frameTime);
	void start();
	void onEvent(sf::Event &event);
	sf::Shape &getShape() { return shape; }

private:
	sf::RectangleShape shape;
};