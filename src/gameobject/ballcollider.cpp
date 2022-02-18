#include "ballcollider.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

    #include <iostream>

BallCollider::BallCollider(sf::Vector2f position, sf::Vector2f size)
  : hitbox{ size }
{
  hitbox.setPosition(position);
}

bool BallCollider::checkForCollisions(Ball& ball)
{
  sf::Vector2f size = hitbox.getSize();
  sf::Vector2f hpos = hitbox.getPosition();
  sf::Vector2f bpos = ball.getPosition();
  double rad = constant::ballRadius;

  //ball hits from the bottom
  return (((bpos.y > hpos.y + size.y) && (hpos.y + size.y > bpos.y - rad)
        && (bpos.x > hpos.x) && (bpos.x < hpos.x + size.x))

  //ball hits from the left
  || ((bpos.x < hpos.x) && (bpos.x + rad > hpos.x)
  && (bpos.y > hpos.y) && (bpos.y < hpos.y + size.y))

  //ball hits from the right
  || ((bpos.x > hpos.x + size.x) && (bpos.x - rad < hpos.x + size.x)
    && (bpos.y > hpos.y) && (bpos.y < hpos.y + size.y))

  //ball hits from the top
  || ((bpos.y < hpos.y) && (hpos.y < bpos.y + rad)
  && (bpos.x > hpos.x) && (bpos.x < hpos.x + size.x)));

  //ball is inside
  //|| ((bpos.x > hpos.x) && (bpos.x < hpos.x + size.x) && (bpos.y > hpos.y) && (bpos.y < hpos.y + size.y)));

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
