#include"Game.h"
#include"Constants.h"

Game::~Game() {

}

Game::Game() {

}

int Game::run() {

	createWindow(); // Creates a new window

	sf::Clock clock;

	while (isRunning) { // Main game loop is here
		sf::Event event;
		while (renderWindow.pollEvent(event)) { // Event loop starts here
			if (event.type == sf::Event::Closed)
				renderWindow.close();
		}
		// Draw stuff under here
		renderWindow.clear();

		renderWindow.display();
	}

	return 0;
}

void Game::createWindow() {
	if (renderWindow.isOpen())
		renderWindow.close();

	renderWindow.create(sf::VideoMode(800, 600), "Classic Breakout");
}