#include "block.h"
#include "constants.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

    #include <iostream>

Block::Block(sf::Vector2f size, sf::Vector2f position, sf::Font &font,
             sf::Color textColor, unsigned int textSize, int hitPoints)
  : block{ size },
    hitPoints{ hitPoints },
    hitPointsText{ font, std::to_string(hitPoints), textColor, textSize,
                   position + sf::Vector2f(1.0f, 1.0f) }
{
  block.setPosition(position);
  block.setFillColor(sf::Color::Yellow);
}

void Block::checkForCollisions(Ball& ball)
{
  if((((ball.getPosition().x + constant::ballRadius > block.getPosition().x
  && ball.getPosition().x + constant::ballRadius < block.getPosition().x + block.getSize().x)
  || (ball.getPosition().x + constant::ballRadius < block.getPosition().x
  && ball.getPosition().x + constant::ballRadius > block.getPosition().x + block.getSize().x))
  || ((ball.getPosition().x - constant::ballRadius > block.getPosition().x
  && ball.getPosition().x - constant::ballRadius < block.getPosition().x + block.getSize().x)
  || (ball.getPosition().x - constant::ballRadius < block.getPosition().x
  && ball.getPosition().x - constant::ballRadius > block.getPosition().x + block.getSize().x)))
  && (((ball.getPosition().y + constant::ballRadius > block.getPosition().y
  && ball.getPosition().y + constant::ballRadius < block.getPosition().y + block.getSize().y)
  || (ball.getPosition().y + constant::ballRadius < block.getPosition().y
  && ball.getPosition().y + constant::ballRadius > block.getPosition().y + block.getSize().y))
  || ((ball.getPosition().y - constant::ballRadius > block.getPosition().y
  && ball.getPosition().y - constant::ballRadius < block.getPosition().y + block.getSize().y)
  || (ball.getPosition().y - constant::ballRadius < block.getPosition().y
  && ball.getPosition().y - constant::ballRadius > block.getPosition().y + block.getSize().y))))
  {
    wasHitInCurrentFrame = true;
    --hitPoints;
    hitPointsText.update(std::to_string(hitPoints));

    if(block.getPosition().y + block.getSize().y < ball.getPosition().y)
    {
      ball.bounce(sf::Vector2i(0, 1));
    }
    else if(block.getPosition().x > ball.getPosition().x)
    {
      ball.bounce(sf::Vector2i(1, 0));
    }
    else if(block.getPosition().x + block.getSize().x < ball.getPosition().x)
    {
      ball.bounce(sf::Vector2i(-1, 0));
    }
    else if(block.getPosition().y > ball.getPosition().y)
    {
      ball.bounce(sf::Vector2i(0, -1));
    }
  }
  else
  {
    wasHitInCurrentFrame = false;
  }
}

void Block::draw(sf::RenderWindow& targetWindow)
{
  targetWindow.draw(block);
  hitPointsText.draw(&targetWindow);
}

bool Block::isAlive()
{
  return hitPoints > 0;
}

void Block::move()
{
  block.setPosition(block.getPosition()
                  + sf::Vector2f(0, constant::blockSize + constant::gapSize));
  hitPointsText.setPosition(block.getPosition() + sf::Vector2f(1.0f, 1.0f));
  ++row;
}

int Block::getRow()
{
  return row;
}
