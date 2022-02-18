#ifndef VERTICAL_DAMAGE_POWER_UP_H
#define VERTICAL_DAMAGE_POWER_UP_H

  #include "powerup.h"
  #include "animatedsprite.h"
  #include "ballgenerator.h"
  #include "ball.h"
  #include "block.h"
  #include <SFML/Graphics.hpp>

  class VerticalDamagePowerUp : public PowerUp
  {
    public:
      VerticalDamagePowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size);

      void update(BallGenerator& generator, std::vector<Block>& blocks);
      void draw(sf::RenderWindow& targetWindow);
      void move();

    private:
      int oldCollidedBalls{ 0 };
      bool active{ false };

      sf::Vector2i gridPosition{  };

      sf::RectangleShape rayEffect{ sf::Vector2f(25.0, constant::windowHeight * 2) };
  };

#endif
