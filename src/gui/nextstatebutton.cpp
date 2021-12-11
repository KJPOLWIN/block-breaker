#include "nextstatebutton.h"
#include <SFML/Graphics.hpp>

void NextStateButton::takeInput(sf::Vector2i clickPosition)
{
	if(isClicked(clickPosition) && gameStateTracker != nullptr)
	{
		*gameStateTracker = nextGameState;
	}
}

void NextStateButton::update(double elapsedTime)
{
	sprite.update(elapsedTime);
}

void NextStateButton::draw(sf::RenderWindow *currentWindow)
{
	sprite.draw(currentWindow);
	text.draw(currentWindow);
	
			//DEBUG
			/* sf::RectangleShape debugClickbox{ clickbox };
			debugClickbox.setOrigin( sf::Vector2f(clickbox.x * 0.5, clickbox.y * 0.5) );
			debugClickbox.setPosition(getPosition());
			currentWindow->draw(debugClickbox); */
}


bool NextStateButton::isTracking()
{
	return (gameStateTracker != nullptr);
}

void NextStateButton::setGameStateTracker(GameState& gameStateTracker)
{
	this->gameStateTracker = &gameStateTracker;
}


void NextStateButton::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
	text.setPosition(position + textOffset);
}

sf::Vector2f NextStateButton::getPosition()
{
	return sprite.getPosition();
}


bool NextStateButton::isClicked(sf::Vector2i clickPosition)
{
	return (clickPosition.x > (getPosition().x - clickbox.x / 2)
		 && clickPosition.x < (getPosition().x + clickbox.x / 2)
		 && clickPosition.y > (getPosition().y - clickbox.y / 2)
		 && clickPosition.y < (getPosition().y + clickbox.y / 2));
}

void NextStateButton::changeAnimation(int animationID)
{
	sprite.setAnimation(animationID, true);
}