#include "radiobutton.h"
#include <SFML/Graphics.hpp>

void RadioButton::update(double elapsedTime)
{
	sprite.update(elapsedTime);
}

void RadioButton::draw(sf::RenderWindow *currentWindow)
{
	sprite.draw(currentWindow);
	text.draw(currentWindow);
}

bool RadioButton::isClicked(sf::Vector2i clickPosition)
{
	return (clickPosition.x > (getPosition().x - clickbox.x / 2)
		 && clickPosition.x < (getPosition().x + clickbox.x / 2)
		 && clickPosition.y > (getPosition().y - clickbox.y / 2)
		 && clickPosition.y < (getPosition().y + clickbox.y / 2));
}

void RadioButton::changeAnimation(int animationID)
{
	sprite.setAnimation(animationID, true);
}


void RadioButton::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
	text.setPosition(position + textOffset);
}

sf::Vector2f RadioButton::getPosition()
{
	return sprite.getPosition();

}

int RadioButton::getYield()
{
	return yield;
}

