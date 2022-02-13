#include "powerup.h"
#include <SFML/Graphics.hpp>

#include <iostream>

PowerUp::PowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size)
  : BallCollider(position, size),
    sprite{ sprite }
{
  this->setPosition(position);
  this->sprite.setPosition(position + sf::Vector2f(size.x / 2, size.y / 2));

  // std::cout << "hitbox: " << this->getPosition().x << ", " << this->getPosition().y << "\n";
  // std::cout << "sprite: " << sprite.getPosition().x << ", " << sprite.getPosition().y << "\n";
}

void PowerUp::draw(sf::RenderWindow& window)
{
  if(alive)
  {
    sprite.draw(&window);
  }
}

void PowerUp::move()
{
  this->setPosition(this->getPosition()
                  + sf::Vector2f(0, constant::blockSize + constant::gapSize));
  sprite.setPosition(this->getPosition() + sf::Vector2f(this->getSize().x / 2, this->getSize().y / 2));
}

bool PowerUp::isAlive()
{
  return alive;
}
