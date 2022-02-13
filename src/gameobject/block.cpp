#include "block.h"
#include "constants.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

    #include <iostream>

Block::Block(sf::Vector2f position, sf::Vector2f size, sf::Font &font,
             sf::Color textColor, unsigned int textSize, int hitPoints)
  : BallCollider(position, size),
    hitPoints{ hitPoints },
    hitPointsText{ font, std::to_string(hitPoints), textColor, textSize,
                   position + sf::Vector2f(1.0f, 1.0f) },
    position{ sf::Vector2i((position.x - constant::wallThickness - constant::gapSize) / (constant::blockSize + constant::gapSize),
                           (position.y - constant::wallThickness - constant::gapSize) / (constant::blockSize + constant::gapSize)) }
{
  this->setColor(sf::Color::Yellow);
}

void Block::update(Ball& ball)
{
  if(this->checkForCollisions(ball))
  {
    decreaseHealth();

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
  else
  {
    wasHitInCurrentFrame = false;
  }
}

void Block::draw(sf::RenderWindow& targetWindow)
{
  BallCollider::draw(targetWindow);
  hitPointsText.draw(&targetWindow);
}

void Block::decreaseHealth(int damage /* = 1*/)
{
  wasHitInCurrentFrame = true;
  hitPoints -= damage;
  hitPointsText.update(std::to_string(hitPoints));
}

bool Block::isAlive()
{
  return hitPoints > 0;
}

void Block::move()
{
  this->setPosition(this->getPosition()
                  + sf::Vector2f(0, constant::blockSize + constant::gapSize));
  hitPointsText.setPosition(this->getPosition() + sf::Vector2f(1.0f, 1.0f));
  ++position.y;
}

int Block::getRow()
{
  return position.y;
}

int Block::getColumn()
{
  return position.x;
}
