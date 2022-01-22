#include "horizontaldamagepowerup.h"
#include "animatedsprite.h"
#include "ballgenerator.h"
#include "ball.h"
#include "block.h"
#include <SFML/Graphics.hpp>

HorizontalDamagePowerUp::HorizontalDamagePowerUp(AnimatedSprite sprite, sf::Vector2f size, sf::Vector2f position)
  : sprite{ sprite },
    hitbox{ sf::RectangleShape(size) },
    position{ sf::Vector2i((position.x - constant::wallThickness - constant::gapSize) / (constant::blockSize + constant::gapSize),
                    (position.y - constant::wallThickness - constant::gapSize) / (constant::blockSize + constant::gapSize)) }
{
  hitbox.setPosition(position);
  //sprite.setPosition(hitbox.getPosition() + sf::Vector2f(hitbox.getSize().x / 2, hitbox.getSize().y / 2));
  HorizontalDamagePowerUp::sprite.setPosition(position + sf::Vector2f(size.x / 2, size.y / 2));
}

void HorizontalDamagePowerUp::update(BallGenerator& generator, std::vector<Block>& blocks)
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
      if(block.getColumn() == position.y)
      {
        block.decreaseHealth(collidedBalls - oldCollidedBalls);
      }
    }
  }

  oldCollidedBalls = collidedBalls;
}

bool HorizontalDamagePowerUp::checkForCollisions(Ball& ball)
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

void HorizontalDamagePowerUp::draw(sf::RenderWindow& window)
{
  sprite.draw(&window);
  //window.draw(hitbox);
}

void HorizontalDamagePowerUp::move()
{
  hitbox.setPosition(hitbox.getPosition()
                  + sf::Vector2f(0, constant::blockSize + constant::gapSize));
  sprite.setPosition(hitbox.getPosition() + sf::Vector2f(hitbox.getSize().x / 2, hitbox.getSize().y / 2));
  ++position.y;
}

bool HorizontalDamagePowerUp::isAlive()
{
  return alive;
}


sf::Vector2f HorizontalDamagePowerUp::getPosition()
{
  return hitbox.getPosition();
}
