#include "button.h"
#include <SFML/Graphics.hpp>

bool Button::isClicked(sf::Vector2i clickPosition)
{
	return (clickPosition.x > (Button::getPosition().x - Button::clickbox.x / 2)
		 && clickPosition.x < (Button::getPosition().x + Button::clickbox.x / 2)
		 && clickPosition.y > (Button::getPosition().y - Button::clickbox.y / 2)
		 && clickPosition.y < (Button::getPosition().y + Button::clickbox.y / 2));
}

void Button::draw(sf::RenderWindow *currentWindow)
{
	sprite.draw(currentWindow);
	text.draw(currentWindow);
	
			//DEBUG
			/* sf::RectangleShape debugClickbox{ clickbox };
			debugClickbox.setOrigin( sf::Vector2f(clickbox.x * 0.5, clickbox.y * 0.5) );
			debugClickbox.setPosition(getPosition());
			currentWindow->draw(debugClickbox); */
}