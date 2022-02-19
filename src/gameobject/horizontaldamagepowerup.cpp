#include "horizontaldamagepowerup.h"
#include "animatedsprite.h"
#include "ballgenerator.h"
#include "ball.h"
#include "block.h"
#include <SFML/Graphics.hpp>

HorizontalDamagePowerUp::HorizontalDamagePowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size)
  : PowerUp(sprite, position, size),
    gridPosition{ sf::Vector2i((position.x - constant::wallThickness - constant::gapSize) / (constant::blockSize + constant::gapSize),
                    (position.y - constant::wallThickness - constant::gapSize) / (constant::blockSize + constant::gapSize)) }
{
  rayEffect.setOrigin(sf::Vector2f(rayEffect.getSize().x * 0.5, rayEffect.getSize().y * 0.5));
  rayEffect.setPosition(this->getPosition() + sf::Vector2f(0, 50));
  rayEffect.setFillColor(constant::rayColor);
}

void HorizontalDamagePowerUp::update(BallGenerator& generator, std::vector<Block>& blocks)
{
  int collidedBalls{ 0 };

  for( auto& ball : generator.getBalls() )
  {
    if(checkForCollisions(ball))
    {
      ++collidedBalls;
    }
  }

  if(collidedBalls > oldCollidedBalls)
  {
    alive = false;
    active = true;
    for( auto& block : blocks )
    {
      if(block.getRow() == gridPosition.y)
      {
        block.decreaseHealth(collidedBalls - oldCollidedBalls);
      }
    }
  }
  else
  {
    active = false;
  }

  oldCollidedBalls = collidedBalls;
}

void HorizontalDamagePowerUp::draw(sf::RenderWindow& targetWindow)
{
  PowerUp::draw(targetWindow);
  if(active) targetWindow.draw(rayEffect);
}

void HorizontalDamagePowerUp::move()
{
  ++gridPosition.y;
  PowerUp::move();
  rayEffect.setPosition(this->getPosition() + sf::Vector2f(0, 50));
}
