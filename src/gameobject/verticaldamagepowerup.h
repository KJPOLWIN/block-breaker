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
      void move();

    private:
      int oldCollidedBalls{ 0 };

      sf::Vector2i gridPosition{  };
  };

#endif
