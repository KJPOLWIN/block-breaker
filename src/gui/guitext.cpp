#include "guitext.h"
#include <string>
#include <SFML/Graphics.hpp>

void guiText::update(std::string newString)
{
	guiText::text.setString(newString);
}

void guiText::draw(sf::RenderWindow *currentWindow)
{
	currentWindow->draw(guiText::text);
}
			
void guiText::setPosition(sf::Vector2f position)
{
	guiText::text.setPosition(position);
}

sf::Vector2f guiText::getPosition()
{
	return guiText::text.getPosition();
}

void guiText::setSize(unsigned int newSize)
{
	guiText::text.setCharacterSize(newSize);
}

void guiText::setColor(sf::Color newColor)
{
	guiText::text.setColor(newColor);
}