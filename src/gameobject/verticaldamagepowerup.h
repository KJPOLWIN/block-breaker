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
