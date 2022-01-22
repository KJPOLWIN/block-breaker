#include "extraballpowerup.h"
#include "animatedsprite.h"
#include "ballgenerator.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

ExtraBallPowerUp::ExtraBallPowerUp(AnimatedSprite sprite, sf::Vector2f size, sf::Vector2f position)
  : sprite{ sprite },
    hitbox{ sf::RectangleShape(size) }
{
  hitbox.setPosition(position);
  //sprite.setPosition(hitbox.getPosition() + sf::Vector2f(hitbox.getSize().x / 2, hitbox.getSize().y / 2));
  ExtraBallPowerUp::sprite.setPosition(position + sf::Vector2f(size.x / 2, size.y / 2));
}

void ExtraBallPowerUp::update(BallGenerator& generator)
{
  for( auto& ball : generator.getBalls() )
  {
    if(checkForCollisions(ball))
    {
      generator.addBall();
      alive = false;
      break;
    }
  }
}

bool ExtraBallPowerUp::checkForCollisions(Ball& ball)
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

void ExtraBallPowerUp::draw(sf::RenderWindow& window)
{
  if(alive)
  {
    sprite.draw(&window);
    //window.draw(hitbox);
  }
}

void ExtraBallPowerUp::move()
{
  hitbox.setPosition(hitbox.getPosition()
                  + sf::Vector2f(0, constant::blockSize + constant::gapSize));
  sprite.setPosition(hitbox.getPosition() + sf::Vector2f(hitbox.getSize().x / 2, hitbox.getSize().y / 2));
}

bool ExtraBallPowerUp::isAlive()
{
  return alive;
}


sf::Vector2f ExtraBallPowerUp::getPosition()
{
  return hitbox.getPosition();
}