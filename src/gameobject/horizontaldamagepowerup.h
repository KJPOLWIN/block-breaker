#ifndef HORIZONTAL_DAMAGE_POWER_UP_H
#define HORIZONTAL_DAMAGE_POWER_UP_H

  #include "powerup.h"
  #include "animatedsprite.h"
  #include "ballgenerator.h"
  #include "ball.h"
  #include "block.h"
  #include <SFML/Graphics.hpp>

  class HorizontalDamagePowerUp : public PowerUp
  {
    public:
      HorizontalDamagePowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size);

      void update(BallGenerator& generator, std::vector<Block>& blocks);
      // bool checkForCollisions(Ball& ball);
      // void draw(sf::RenderWindow& window);
      //
      // void move();
      //
      // bool isAlive();
      //
      //
      //     sf::Vector2f getPosition();

    private:
      // AnimatedSprite sprite{  };
      // sf::RectangleShape hitbox{  };
      // bool alive{ true };
      int oldCollidedBalls{ 0 };

      sf::Vector2i position{  };  //Position in grid, not in xy coordinates
  };

#endif
