#include"Game.h"
#include"Constants.h"

Game::~Game() {

}

Game::Game() {

}

int Game::run() {

	createWindow(); // Creates a new window

	sf::Clock clock; // Game Clock

	Scene mainScene; // The main scene of the game

	while (isRunning) { // Main game loop is here
		sf::Event event;
		while (renderWindow.pollEvent(event)) { // Event loop starts here
			if (event.type == sf::Event::Closed)
				renderWindow.close();
			mainScene.onEvent(event);
		}

		// Draw stuff under here
		renderWindow.clear();

		mainScene.update(clock.restart().asMilliseconds());
		mainScene.draw(renderWindow);

		renderWindow.display();
	}

	return 0;
}

void Game::createWindow() {
	if (renderWindow.isOpen())
		renderWindow.close();

	renderWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	renderWindow.setFramerateLimit(FPS);
}