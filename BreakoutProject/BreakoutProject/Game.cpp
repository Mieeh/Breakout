#include"Game.h"
#include"Constants.h"

Game::~Game() {

}

Game::Game() {
	gameState = GameState::MENU;
}

int Game::run() {

	createWindow(); // Creates a new window

	sf::Clock clock; // Game Clock

	Scene mainScene; // The main scene of the game
	Menu mainMenu(renderWindow);

	while (isRunning) { // Main game loop is here
		sf::Event event;
		while (renderWindow.pollEvent(event)) { // Event loop starts here
			if (event.type == sf::Event::Closed)
				renderWindow.close();
			if (sf::Keyboard::isKeyPressed)
				if (event.key.code == sf::Keyboard::Space)
					particleSpawner.create(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, (rand() % 500 + (-250)),(rand() % 500 + (-250)), 300);
			if(gameState == GameState::PLAYING)
				mainScene.onEvent(event); 
			if (gameState == GameState::MENU)
				mainMenu.onEvent(event,renderWindow);
		}
		// Draw stuff under here
		renderWindow.clear(sf::Color(6,6,6,255));

		/*
		* Changing game state logic
		*/
		if (mainMenu.getPlayTrigger()) {
			gameState = GameState::PLAYING;
			mainScene.newBoardSetup();

			mainMenu.setPlayTrigger(false);
		}
		if (mainScene.getGameOver()) {
			gameState = GameState::MENU;
			mainScene.setGameOver(false);
		}

		/*
		* Check what current state the game is in
		* to decide what scene we should update and draw
		*/
		/*
		if (gameState == GameState::MENU) {
			mainMenu.update(clock.restart().asMilliseconds());
			mainMenu.draw(renderWindow);
		}
		if (gameState == GameState::PLAYING) {
			mainScene.update(clock.restart().asMilliseconds());
			mainScene.draw(renderWindow);
		}
		*/
		particleSpawner.update(clock.restart().asSeconds());
		particleSpawner.drawParticles(renderWindow);

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