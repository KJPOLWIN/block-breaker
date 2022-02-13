#include "extraballpowerup.h"
#include "animatedsprite.h"
#include "ballgenerator.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

    #include <iostream>

ExtraBallPowerUp::ExtraBallPowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size)
  : PowerUp(sprite, position, size)
{

}

void ExtraBallPowerUp::update(BallGenerator& generator)
{
  for( auto& ball : generator.getBalls() )
  {
    if(this->checkForCollisions(ball) && alive)
    {
      generator.addBall();
      alive = false;
      break;
    }
  }
}

void ExtraBallPowerUp::draw(sf::RenderWindow& targetWindow)
{
  if(alive)
  {
    PowerUp::draw(targetWindow);
  }
}
