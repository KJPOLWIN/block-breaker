#ifndef FLIPPER_POWER_UP_H
#define FLIPPER_POWER_UP_H

  #include "powerup.h"
  #include "animatedsprite.h"
  #include "ballgenerator.h"
  #include "ball.h"
  #include <SFML/Graphics.hpp>

  class FlipperPowerUp : public PowerUp
  {
    public:
      FlipperPowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size);

      void update(BallGenerator& generator);

    private:

  };

#endif
