#include "balldeletor.h"
#include "constants.h"
#include "ball.h"
#include "ballgenerator.h"
#include <SFML/Graphics.hpp>

    #include <iostream>

BallDeletor::BallDeletor(sf::Vector2f size, sf::Vector2f position)
  : deletor{ size }
{
  deletor.setPosition(position);
}

void BallDeletor::checkForCollisions(BallGenerator& ballGenerator)
{
    for(std::size_t iii{ 0 }; iii < ballGenerator.getBalls().size(); ++iii)
    {
      auto& ball = ballGenerator.getBalls().at(iii);

      if((((ball.getPosition().x + constant::ballRadius > deletor.getPosition().x
      && ball.getPosition().x + constant::ballRadius < deletor.getPosition().x + deletor.getSize().x)
      || (ball.getPosition().x + constant::ballRadius < deletor.getPosition().x
      && ball.getPosition().x + constant::ballRadius > deletor.getPosition().x + deletor.getSize().x))
      || ((ball.getPosition().x - constant::ballRadius > deletor.getPosition().x
      && ball.getPosition().x - constant::ballRadius < deletor.getPosition().x + deletor.getSize().x)
      || (ball.getPosition().x - constant::ballRadius < deletor.getPosition().x
      && ball.getPosition().x - constant::ballRadius > deletor.getPosition().x + deletor.getSize().x)))
      && (((ball.getPosition().y + constant::ballRadius > deletor.getPosition().y
      && ball.getPosition().y + constant::ballRadius < deletor.getPosition().y + deletor.getSize().y)
      || (ball.getPosition().y + constant::ballRadius < deletor.getPosition().y
      && ball.getPosition().y + constant::ballRadius > deletor.getPosition().y + deletor.getSize().y))
      || ((ball.getPosition().y - constant::ballRadius > deletor.getPosition().y
      && ball.getPosition().y - constant::ballRadius < deletor.getPosition().y + deletor.getSize().y)
      || (ball.getPosition().y - constant::ballRadius < deletor.getPosition().y
      && ball.getPosition().y - constant::ballRadius > deletor.getPosition().y + deletor.getSize().y))))
      {
        if(firstHit)
        {
          generatorNewPosition = ball.getPosition();
          firstHit = false;
        }

        ballGenerator.getBalls().erase(ballGenerator.getBalls().begin() + iii);
      }
    }
    
    if(ballGenerator.getPhase() == Phase::Aiming && generatorNewPosition.x > 0)
    {
      firstHit = true;
      ballGenerator.setPosition(generatorNewPosition);
    }
}
