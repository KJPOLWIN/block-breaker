#include "checkbox.h"
#include <SFML/Graphics.hpp>

void CheckBox::takeInput(sf::Vector2i clickPosition)
{
	if(isClicked(clickPosition))
	{
		*state = !(*state);
		changeAnimation(*state);
	}
}

void CheckBox::update(double elapsedTime)
{
	sprite.update(elapsedTime);
}

void CheckBox::draw(sf::RenderWindow *currentWindow)
{
	sprite.draw(currentWindow);
	text.draw(currentWindow);
}

void CheckBox::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
	text.setPosition(position + textOffset);
}

sf::Vector2f CheckBox::getPosition()
{
	return sprite.getPosition();
}

void CheckBox::changeAnimation(int animationID)
{
	sprite.setAnimation(animationID, true);
}

bool CheckBox::isClicked(sf::Vector2i clickPosition)
{
	return (clickPosition.x > (getPosition().x - clickbox.x / 2)
		 && clickPosition.x < (getPosition().x + clickbox.x / 2)
		 && clickPosition.y > (getPosition().y - clickbox.y / 2)
		 && clickPosition.y < (getPosition().y + clickbox.y / 2));
}	