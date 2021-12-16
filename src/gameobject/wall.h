#ifndef WALL_H
#define WALL_H

  #include "ball.h"
  #include <SFML/Graphics.hpp>

  class Wall
  {
    public:
      Wall(sf::Vector2f size, sf::Vector2f position);

      void checkForCollisions(Ball& ball);
      void draw(sf::RenderWindow& targetWindow);

    private:
      sf::RectangleShape wall{  };
  };

#endif
