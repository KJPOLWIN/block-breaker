#ifndef BALLDELETOR_H
#define BALLDELETOR_H

  #include "ball.h"
  #include <SFML/Graphics.hpp>

  class BallDeletor
  {
    public:
      BallDeletor(sf::Vector2f size, sf::Vector2f position);

      void checkForCollisions(Ball& ball);

    private:
      sf::RectangleShape deletor{  };
  };

#endif
