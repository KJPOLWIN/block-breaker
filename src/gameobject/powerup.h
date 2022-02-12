#ifndef POWERUP_H
#define POWERUP_H

  #include "ballcollider.h"
  #include "animatedsprite.h"
  #include "ball.h"
  #include <SFML/Graphics.hpp>

  class PowerUp : public BallCollider
  {
    public:
      PowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size);

      void draw(sf::RenderWindow& window);
      void move();

      bool isAlive();

    protected:
      bool alive{ true };

    private:
      AnimatedSprite sprite{  };
  };

#endif
