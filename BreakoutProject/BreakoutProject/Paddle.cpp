#include"Paddle.h"

Paddle::Paddle() {
	start();
}

Paddle::~Paddle() {
	
}

void Paddle::start() {
	shape.setFillColor(sf::Color::Red);
	shape.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
	shape.setPosition(WINDOW_WIDTH/2 - (PADDLE_WIDTH / 2), WINDOW_HEIGHT - PADDLE_HEIGHT * 11);
}

void Paddle::update(float frameTime) {

}

void Paddle::onEvent(sf::Event &event) {

}