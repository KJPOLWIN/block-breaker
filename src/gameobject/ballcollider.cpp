#include "ballcollider.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

BallCollider::BallCollider(sf::Vector2f position, sf::Vector2f size)
  : hitbox{ size }
{
  hitbox.setPosition(position);
}

bool BallCollider::checkForCollisions(Ball& ball)
{
  return (((ball.getPosition().x + constant::ballRadius > hitbox.getPosition().x
  && ball.getPosition().x + constant::ballRadius < hitbox.getPosition().x + hitbox.getSize().x)
  || (ball.getPosition().x + constant::ballRadius < hitbox.getPosition().x
  && ball.getPosition().x + constant::ballRadius > hitbox.getPosition().x + hitbox.getSize().x))
  || ((ball.getPosition().x - constant::ballRadius > hitbox.getPosition().x
  && ball.getPosition().x - constant::ballRadius < hitbox.getPosition().x + hitbox.getSize().x)
  || (ball.getPosition().x - constant::ballRadius < hitbox.getPosition().x
  && ball.getPosition().x - constant::ballRadius > hitbox.getPosition().x + hitbox.getSize().x)))
  && (((ball.getPosition().y + constant::ballRadius > hitbox.getPosition().y
  && ball.getPosition().y + constant::ballRadius < hitbox.getPosition().y + hitbox.getSize().y)
  || (ball.getPosition().y + constant::ballRadius < hitbox.getPosition().y
  && ball.getPosition().y + constant::ballRadius > hitbox.getPosition().y + hitbox.getSize().y))
  || ((ball.getPosition().y - constant::ballRadius > hitbox.getPosition().y
  && ball.getPosition().y - constant::ballRadius < hitbox.getPosition().y + hitbox.getSize().y)
  || (ball.getPosition().y - constant::ballRadius < hitbox.getPosition().y
  && ball.getPosition().y - constant::ballRadius > hitbox.getPosition().y + hitbox.getSize().y)));
}

void BallCollider::setColor(sf::Color color)
{
  hitbox.setFillColor(color);
}

void BallCollider::draw(sf::RenderWindow& targetWindow)
{
  targetWindow.draw(hitbox);
}

sf::Vector2f BallCollider::getPosition()
{
  return hitbox.getPosition();
}

void BallCollider::setPosition(sf::Vector2f newPosition)
{
  hitbox.setPosition(newPosition);
}

sf::Vector2f BallCollider::getSize()
{
  return hitbox.getSize();
}
