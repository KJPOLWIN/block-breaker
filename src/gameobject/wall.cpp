#include "wall.h"
#include "constants.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

Wall::Wall(sf::Vector2f position, sf::Vector2f size)
  : BallCollider(position, size)
{
  this->setColor(constant::wallColor);
}

void Wall::update(Ball& ball)
{
  if(this->checkForCollisions(ball))
  {
    if(this->getPosition().y + this->getSize().y < ball.getPosition().y)
    {
      ball.bounce(sf::Vector2i(0, 1));
    }

    else if(this->getPosition().x > ball.getPosition().x)
    {
      ball.bounce(sf::Vector2i(1, 0));
    }

    else if(this->getPosition().x + this->getSize().x < ball.getPosition().x)
    {
      ball.bounce(sf::Vector2i(-1, 0));
    }

    else if(this->getPosition().y > ball.getPosition().y)
    {
      ball.bounce(sf::Vector2i(0, -1));
    }
  }
}
