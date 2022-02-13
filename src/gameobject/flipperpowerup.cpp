#include "flipperpowerup.h"
#include "animatedsprite.h"
#include "ballgenerator.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

FlipperPowerUp::FlipperPowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size)
  : PowerUp(sprite, position, size)
{

}

void FlipperPowerUp::update(BallGenerator& generator)
{
  for( auto& ball : generator.getBalls() )
  {
    if(checkForCollisions(ball))
    {
      ball.deflect();
      alive = false;
      break;
    }
  }
}
