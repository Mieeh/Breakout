#pragma once

#include"SFML\Graphics.hpp"

namespace ui {

namespace states {
	enum ButtonStates {
		normal,
		highlighted,

	};
}

class Text {
public:
	Text(std::string _fontPath, int _fontSize, sf::Vector2f _startPos);

	/////////////////////
	// \brief Returns m_Text for drawing
	//
	/////////////////////
	sf::Text getText() { return m_Text; }


	// Helper methods
	void setText(std::string a_text) { m_Text.setString(a_text); } // a_text becomes display text
	void setColor(sf::Color a_color) { m_Text.setFillColor(a_color); } // Sets m_Text color
	void setFontSize(int a_size) { m_Text.setCharacterSize(a_size); } // Sets font size of m_Text

	void setScale(sf::Vector2f a_scale) { m_Text.setScale(a_scale); } 
	void setPosition(sf::Vector2f a_pos) { m_Text.setPosition(a_pos); }
	void setFont(sf::Font &a_font) { m_Text.setFont(a_font); }
	
private:
	sf::Text m_Text;
	sf::Font m_Font;
};



class Button{
public:
	/// <summary>
	/// Default constructor for button class
	/// </summary>
	/// <param name="p_buttonText">Text displayed inside the button</param>
	/// <param name="p_color">Fill color for button</param>
	/// <param name="p_size">Button dimensions</param>
	/// <param name="p_pos">Initial position of the button</param>
	Button(std::string p_buttonText, sf::Color p_color, sf::Vector2f p_size = sf::Vector2f(100, 50), sf::Vector2f p_pos = sf::Vector2f(0, 0));

	/// <summary>
	/// Returns true if sf::Mouse is located inside this button
	/// </summary>
	bool isMouseInside();

	void draw(sf::RenderTarget &target);

	// Helper methods
	void setText(std::string a_string) { m_Text.setText(a_string); }
	void setPosition(sf::Vector2f a_pos) { m_Rect.setPosition(a_pos); }
	void setSize(sf::Vector2f a_size) { m_Rect.setSize(a_size); }
	void setColor(sf::Color a_color) { m_Rect.setFillColor(a_color); }

private:

	// Member attributes of button
	ui::Text m_Text;
	sf::RectangleShape m_Rect;

	// Customizable values
	sf::Color m_NormalColor;
	sf::Color m_HighlightedColor;

	states::ButtonStates state;
};
}