#include "balldeletor.h"
#include "constants.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

BallDeletor::BallDeletor(sf::Vector2f size, sf::Vector2f position)
  : deletor{ size }
{
  deletor.setPosition(position);
}

void BallDeletor::checkForCollisions(Ball& ball)
{
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


    // if(deletor.getPosition().y + deletor.getSize().y < ball.getPosition().y)
    // {
    //   ball.bounce(sf::Vector2i(0, 1));
    // }
    //
    // else if(deletor.getPosition().x > ball.getPosition().x)
    // {
    //   ball.bounce(sf::Vector2i(1, 0));
    // }
    //
    // else if(deletor.getPosition().x + deletor.getSize().x < ball.getPosition().x)
    // {
    //   ball.bounce(sf::Vector2i(-1, 0));
    // }
    //
    // else if(deletor.getPosition().y > ball.getPosition().y)
    // {
    //   ball.bounce(sf::Vector2i(0, -1));
    // }
  }
}
