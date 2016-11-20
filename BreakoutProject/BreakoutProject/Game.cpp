#include"Game.h"
#include"Constants.h"

Game::~Game() {

}

Game::Game() {
	gameState = GameState::PLAYING;
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
		renderWindow.clear(sf::Color(6,6,6,255));

		/*
		* Check what current state the game is in
		* to decide what scene we should update and draw
		*/
		if (gameState == GameState::PLAYING) {
			mainScene.update(clock.restart().asMilliseconds());
			mainScene.draw(renderWindow);
		}

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