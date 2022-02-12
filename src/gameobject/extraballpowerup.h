#ifndef EXTRA_BALL_POWER_UP_H
#define EXTRA_BALL_POWER_UP_H

  #include "powerup.h"
  #include "animatedsprite.h"
  #include "ballgenerator.h"
  #include "ball.h"
  #include <SFML/Graphics.hpp>

  class ExtraBallPowerUp : public PowerUp
  {
    public:
      ExtraBallPowerUp(AnimatedSprite sprite, sf::Vector2f position, sf::Vector2f size);

      void update(BallGenerator& generator);
      //bool checkForCollisions(Ball& ball);
      //void draw(sf::RenderWindow& window);

    //  void move();

      //bool isAlive();


          //sf::Vector2f getPosition();

    private:
      //AnimatedSprite sprite{  };
    //sf::RectangleShape hitbox{  };
      //bool alive{ true };
  };

#endif
