#include "flipperpowerup.h"
#include "animatedsprite.h"
#include "ballgenerator.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

FlipperPowerUp::FlipperPowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size)
  : PowerUp(sprite, position, size)
    // sprite{ sprite },
    // hitbox{ sf::RectangleShape(size) }
{
  // hitbox.setPosition(position);
  // FlipperPowerUp::sprite.setPosition(position + sf::Vector2f(size.x / 2, size.y / 2));
}

void FlipperPowerUp::update(BallGenerator& generator)
{
  for( auto& ball : generator.getBalls() )
  {
    if(checkForCollisions(ball))
    {
      ball.deflect();
      alive = false;
      break;
    }
  }
}

// bool FlipperPowerUp::checkForCollisions(Ball& ball)
// {
//   return ((((ball.getPosition().x + constant::ballRadius > hitbox.getPosition().x
//   && ball.getPosition().x + constant::ballRadius < hitbox.getPosition().x + hitbox.getSize().x)
//   || (ball.getPosition().x + constant::ballRadius < hitbox.getPosition().x
//   && ball.getPosition().x + constant::ballRadius > hitbox.getPosition().x + hitbox.getSize().x))
//   || ((ball.getPosition().x - constant::ballRadius > hitbox.getPosition().x
//   && ball.getPosition().x - constant::ballRadius < hitbox.getPosition().x + hitbox.getSize().x)
//   || (ball.getPosition().x - constant::ballRadius < hitbox.getPosition().x
//   && ball.getPosition().x - constant::ballRadius > hitbox.getPosition().x + hitbox.getSize().x)))
//   && (((ball.getPosition().y + constant::ballRadius > hitbox.getPosition().y
//   && ball.getPosition().y + constant::ballRadius < hitbox.getPosition().y + hitbox.getSize().y)
//   || (ball.getPosition().y + constant::ballRadius < hitbox.getPosition().y
//   && ball.getPosition().y + constant::ballRadius > hitbox.getPosition().y + hitbox.getSize().y))
//   || ((ball.getPosition().y - constant::ballRadius > hitbox.getPosition().y
//   && ball.getPosition().y - constant::ballRadius < hitbox.getPosition().y + hitbox.getSize().y)
//   || (ball.getPosition().y - constant::ballRadius < hitbox.getPosition().y
//   && ball.getPosition().y - constant::ballRadius > hitbox.getPosition().y + hitbox.getSize().y))));
// }
//
// void FlipperPowerUp::draw(sf::RenderWindow& window)
// {
//   sprite.draw(&window);
// }
//
// void FlipperPowerUp::move()
// {
//   hitbox.setPosition(hitbox.getPosition()
//                   + sf::Vector2f(0, constant::blockSize + constant::gapSize));
//   sprite.setPosition(hitbox.getPosition() + sf::Vector2f(hitbox.getSize().x / 2, hitbox.getSize().y / 2));
// }
//
// bool FlipperPowerUp::isAlive()
// {
//   return alive;
// }
//
//
// sf::Vector2f FlipperPowerUp::getPosition()
// {
//   return hitbox.getPosition();
// }
