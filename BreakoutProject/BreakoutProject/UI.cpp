#include"UI.h"

ui::Text::Text(std::string _fontPath, int _fontSize, sf::Vector2f _startPos)
{
	if (!m_Font.loadFromFile(_fontPath)) {
		printf("error loading font from given search path");
	}

	setFont(m_Font);
	setFontSize(_fontSize);
	setPosition(_startPos);
}

ui::Button::Button(std::string p_buttonText, sf::Color p_color, sf::Vector2f p_size, sf::Vector2f p_pos) : m_Text("arial.ttf", 25, p_pos) 
{
	m_Rect.setSize(p_size);
	m_Rect.setPosition(sf::Vector2f(p_pos.x - p_size.x / 2, p_pos.y - p_size.y / 2));

	setText(p_buttonText);
	setColor(p_color);

	// Formula for centering a text within a bounding box
	/// text_start = bounding_box_width / 2 - text_width / 2
	m_Text.setPosition(sf::Vector2f(m_Rect.getPosition().x + m_Rect.getGlobalBounds().width - m_Text.getText().getGlobalBounds().width - m_Rect.getGlobalBounds().width/3, m_Rect.getPosition().y)); // Set m_Text position in the middle of button

	state = states::ButtonStates::normal;
}

void ui::Button::draw(sf::RenderTarget & target)
{
	// Draw rect then text ontop 
	target.draw(m_Rect);
	target.draw(m_Text.getText());
}
