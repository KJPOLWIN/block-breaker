#include "guibar.h"
#include <SFML/Graphics.hpp>

void guiBar::update(double newValue)
{
	if(newValue <= 0.0) currentValue = 0.0;
	else currentValue = newValue;
	bar.setSize(sf::Vector2f(currentValue * pixelPerUnit,
									 				 width));
}

void guiBar::draw(sf::RenderWindow *currentWindow)
{
	currentWindow->draw(bar);
}

void guiBar::recalculatePpU(double sizeX)
{
	pixelPerUnit = sizeX / maxValue;
}

void guiBar::setPosition(sf::Vector2f position)
{
	bar.setPosition(position);
}

sf::Vector2f guiBar::getPosition()
{
	return bar.getPosition();
}
