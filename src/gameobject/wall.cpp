#include "wall.h"
#include "constants.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

    #include <iostream>

Wall::Wall(sf::Vector2f size, sf::Vector2f position)
  : wall{ size }
{
  wall.setPosition(position);
  wall.setFillColor(constant::wallColor);
}

void Wall::checkForCollisions(Ball& ball)
{
  if((((ball.getPosition().x + constant::ballRadius > wall.getPosition().x
  && ball.getPosition().x + constant::ballRadius < wall.getPosition().x + wall.getSize().x)
  || (ball.getPosition().x + constant::ballRadius < wall.getPosition().x
  && ball.getPosition().x + constant::ballRadius > wall.getPosition().x + wall.getSize().x))
  || ((ball.getPosition().x - constant::ballRadius > wall.getPosition().x
  && ball.getPosition().x - constant::ballRadius < wall.getPosition().x + wall.getSize().x)
  || (ball.getPosition().x - constant::ballRadius < wall.getPosition().x
  && ball.getPosition().x - constant::ballRadius > wall.getPosition().x + wall.getSize().x)))
  && (((ball.getPosition().y + constant::ballRadius > wall.getPosition().y
  && ball.getPosition().y + constant::ballRadius < wall.getPosition().y + wall.getSize().y)
  || (ball.getPosition().y + constant::ballRadius < wall.getPosition().y
  && ball.getPosition().y + constant::ballRadius > wall.getPosition().y + wall.getSize().y))
  || ((ball.getPosition().y - constant::ballRadius > wall.getPosition().y
  && ball.getPosition().y - constant::ballRadius < wall.getPosition().y + wall.getSize().y)
  || (ball.getPosition().y - constant::ballRadius < wall.getPosition().y
  && ball.getPosition().y - constant::ballRadius > wall.getPosition().y + wall.getSize().y))))
  {
    if(wall.getPosition().y + wall.getSize().y < ball.getPosition().y)
    {
      ball.bounce(sf::Vector2i(0, 1));
    }

    else if(wall.getPosition().x > ball.getPosition().x)
    {
      ball.bounce(sf::Vector2i(1, 0));
    }

    else if(wall.getPosition().x + wall.getSize().x < ball.getPosition().x)
    {
      ball.bounce(sf::Vector2i(-1, 0));
    }

    else if(wall.getPosition().y > ball.getPosition().y)
    {
      ball.bounce(sf::Vector2i(0, -1));
    }
  }
}

void Wall::draw(sf::RenderWindow& targetWindow)
{
  targetWindow.draw(wall);
}
