#include "balldeletor.h"
#include "constants.h"
#include "ball.h"
#include "ballgenerator.h"
#include <SFML/Graphics.hpp>

BallDeletor::BallDeletor(sf::Vector2f size, sf::Vector2f position)
  : BallCollider(position, size)
{

}

void BallDeletor::update(BallGenerator& ballGenerator)
{
    for(std::size_t iii{ 0 }; iii < ballGenerator.getBalls().size(); ++iii)
    {
      auto& ball = ballGenerator.getBalls().at(iii);

      if(this->checkForCollisions(ball))
      {
        if(firstHit)
        {
          generatorNewPosition = ball.getPosition().x;
          firstHit = false;
        }

        ballGenerator.getBalls().erase(ballGenerator.getBalls().begin() + iii);
      }
    }

    if(ballGenerator.getPhase() == Phase::Aiming && generatorNewPosition > 0)
    {
      firstHit = true;
      ballGenerator.setPosition(generatorNewPosition);
    }
}
