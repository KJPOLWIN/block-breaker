#include "verticaldamagepowerup.h"
#include "animatedsprite.h"
#include "ballgenerator.h"
#include "ball.h"
#include "block.h"
#include <SFML/Graphics.hpp>

VerticalDamagePowerUp::VerticalDamagePowerUp(AnimatedSprite sprite, sf::Vector2f size, sf::Vector2f position)
  : sprite{ sprite },
    hitbox{ sf::RectangleShape(size) },
    position{ sf::Vector2i((position.x - constant::wallThickness - constant::gapSize) / (constant::blockSize + constant::gapSize),
                    (position.y - constant::wallThickness - constant::gapSize) / (constant::blockSize + constant::gapSize)) }
{
  hitbox.setPosition(position);
  //sprite.setPosition(hitbox.getPosition() + sf::Vector2f(hitbox.getSize().x / 2, hitbox.getSize().y / 2));
  VerticalDamagePowerUp::sprite.setPosition(position + sf::Vector2f(size.x / 2, size.y / 2));
}

void VerticalDamagePowerUp::update(BallGenerator& generator, std::vector<Block>& blocks)
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
      if(block.getColumn() == position.x)
      {
        block.decreaseHealth(collidedBalls - oldCollidedBalls);
      }
    }
  }

  oldCollidedBalls = collidedBalls;
}

bool VerticalDamagePowerUp::checkForCollisions(Ball& ball)
{
  return ((((ball.getPosition().x + constant::ballRadius > hitbox.getPosition().x
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
  && ball.getPosition().y - constant::ballRadius > hitbox.getPosition().y + hitbox.getSize().y))));
}

void VerticalDamagePowerUp::draw(sf::RenderWindow& window)
{
  sprite.draw(&window);
  //window.draw(hitbox);
}

void VerticalDamagePowerUp::move()
{
  hitbox.setPosition(hitbox.getPosition()
                  + sf::Vector2f(0, constant::blockSize + constant::gapSize));
  sprite.setPosition(hitbox.getPosition() + sf::Vector2f(hitbox.getSize().x / 2, hitbox.getSize().y / 2));
}

bool VerticalDamagePowerUp::isAlive()
{
  return alive;
}


sf::Vector2f VerticalDamagePowerUp::getPosition()
{
  return hitbox.getPosition();
}
