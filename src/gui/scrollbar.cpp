#include "scrollbar.h"
#include <SFML/Graphics.hpp>

void ScrollBar::takeInput(sf::Vector2i clickPosition)
{
  if(isClicked(clickPosition))
  {
    handle.setPosition( sf::Vector2f(clickPosition.x, handle.getPosition().y) );
  }

  if(followedValue != nullptr)
  {
    *followedValue = baseValue + increasePerPixel * (handle.getPosition().x - getPosition().x);
  }
}

void ScrollBar::update(double elapsedTime)
{
  bar.update(elapsedTime);
  handle.update(elapsedTime);
}

void ScrollBar::draw(sf::RenderWindow* window)
{
  bar.draw(window);
  handle.draw(window);
}


sf::Vector2f ScrollBar::getPosition()
{
  return sf::Vector2f(bar.getPosition().x - bar.getSize().x * 0.5, bar.getPosition().y - bar.getSize().y * 0.5);
}

bool ScrollBar::isClicked(sf::Vector2i clickPosition)
{
	return (clickPosition.x > getPosition().x
		   && clickPosition.x < getPosition().x + size.x
		   && clickPosition.y > getPosition().y
		   && clickPosition.y < getPosition().y + size.y);
}
