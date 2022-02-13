#include "ball.h"
#include "constants.h"
#include "random.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Ball::Ball(sf::Vector2f initialPosition, double speed, sf::Vector2f direction)
  : position{ initialPosition },
    velocity{ direction.x * speed, direction.y * speed }
{
  ball.setFillColor(constant::ballColor);
  ball.setOrigin(constant::ballRadius, constant::ballRadius);
}

void Ball::update(double elapsedTime)
{
  position.x += velocity.x * elapsedTime;
  position.y += velocity.y * elapsedTime;

  ball.setPosition(position);
}

void Ball::draw(sf::RenderWindow& targetWindow)
{
  targetWindow.draw(ball);
}

void Ball::bounce(sf::Vector2i hitDirection)
{
  if(hitDirection.y == 0)
  {
    velocity.x = -velocity.x;
  }
  else if(hitDirection.x == 0)
  {
    velocity.y = -velocity.y;
  }
}

sf::Vector2f Ball::getPosition()
{
  return position;
}

sf::FloatRect Ball::getGlobalBounds()
{
  return ball.getGlobalBounds();
}

void Ball::deflect()
{
  //1.5 gives more "randomized" results than 1.0, and vector is normalized anyway
  velocity.x = Random::getRandomDouble(-1.5, 1.5) * constant::ballSpeed;

  double length{ sqrt(pow(velocity.x, 2) + pow(velocity.y, 2)) };
  velocity.x = (velocity.x / length) * constant::ballSpeed;
  velocity.y = (velocity.y / length) * constant::ballSpeed;
}
