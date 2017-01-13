#include"Button.h"

ui::Button::Button(sf::Vector2f p_size, sf::Color p_color)
{
	setRectSize(p_size);
	setRectColor(p_color);
}

void ui::Button::draw(sf::RenderTarget & target)
{
	target.draw(m_rect);
	m_text.draw(target);
}

bool ui::Button::isMouseInside(sf::Vector2f a_mousePos)
{	
	if (m_rect.getGlobalBounds().contains(a_mousePos))
		return true;
	else
		return false;
}

void ui::Button::setRectSize(sf::Vector2f a_size)
{
	m_rect.setSize(a_size);
}

sf::Vector2f ui::Button::getRectSize() const
{
	return m_rect.getSize();
}

void ui::Button::setRectColor(sf::Color a_color)
{
	m_rect.setFillColor(a_color);
}

void ui::Button::SetRectPosition(sf::Vector2f a_pos)
{
	m_rect.setPosition(a_pos);
}

void ui::Button::setTextColor(sf::Color a_color)
{
	m_text.setColor(a_color);
}

void ui::Button::setCharSize(unsigned int a_size)
{
	m_text.setFontSize(a_size);
}

void ui::Button::setFont(sf::Font & a_font)
{
	m_text.setFont(a_font);
}

void ui::Button::setString(std::string a_string)
{
	m_text.setText(a_string);
}

void ui::Button::centerTextWithinRect()
{
	sf::FloatRect rectBounds = m_rect.getGlobalBounds();
	sf::FloatRect textBounds = m_text.getActualText().getGlobalBounds();
	m_text.setPosition(sf::Vector2f(rectBounds.left + (rectBounds.width/2) - textBounds.width/2, rectBounds.top + (rectBounds.height/2) - textBounds.height/2));
}