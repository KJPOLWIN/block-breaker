#include "powerup.h"
#include <SFML/Graphics.hpp>

PowerUp::PowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size)
  : BallCollider(position, size),
    sprite{ sprite }
{
  this->setPosition(position);
  //Note: if sprites won't be correcly positioned after spawnup, uncomment line below
  //ExtraBallPowerUp::sprite.setPosition(position + sf::Vector2f(size.x / 2, size.y / 2));
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
