#ifndef WALL_H
#define WALL_H

  #include "ball.h"
  #include "ballcollider.h"
  #include <SFML/Graphics.hpp>

  class Wall : public BallCollider
  {
    public:
      Wall(sf::Vector2f position, sf::Vector2f size);

      void update(Ball& ball);
      // void checkForCollisions(Ball& ball);
      // void draw(sf::RenderWindow& targetWindow);

    private:
      // sf::RectangleShape wall{  };
  };

#endif
