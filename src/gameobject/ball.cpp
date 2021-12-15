#include "ball.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

Ball::Ball(sf::Vector2f initialPosition, double speed, sf::Vector2f direction)
  : position{ initialPosition },
    velocity{ direction.x * speed, direction.y * speed }
{
  ball.setFillColor(constant::ballColor);
  ball.setOrigin(constant::ballRadius * 0.5, constant::ballRadius * 0.5);
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

}
