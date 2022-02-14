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
    for( auto& block : blocks )
    {
      if(block.getRow() == gridPosition.y)
      {
        block.decreaseHealth(collidedBalls - oldCollidedBalls);
      }
    }
  }

  oldCollidedBalls = collidedBalls;
}

void HorizontalDamagePowerUp::move()
{
  ++gridPosition.y;
  PowerUp::move();
}
