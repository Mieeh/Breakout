#pragma once

#include"SFML\Graphics.hpp"

/*
* Class for inputing text, interface: keyboard
* Input will happend in an event method
* And drawing will happend in a draw method
*/

/*
* -------------------
* |			        |
* |   Input Text    |
* |                 |
* -------------------
*/

class TextInput {

public:
	/*
	* Constructor 
	*/
	TextInput();

	void draw(sf::RenderTarget &target);
	void onEvent(sf::Event &event);

private:
	// SFML members - rendered objects
	sf::Text m_text; // Text written by the player
	sf::RectangleShape m_displayBox; // m_text is drawn on top of m_displayBox
	
	std::string inputText; // The actual text that's been written by the player
	int inputLength; // inputText's length
	int maxInputLength; // Limit on inputText's length
};