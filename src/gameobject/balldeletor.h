#ifndef BALLDELETOR_H
#define BALLDELETOR_H

  #include "ball.h"
  #include "ballgenerator.h"
  #include <SFML/Graphics.hpp>

  class BallDeletor
  {
    public:
      BallDeletor(sf::Vector2f size, sf::Vector2f position);

      void checkForCollisions(BallGenerator& ballGenerator);

    private:
      sf::RectangleShape deletor{  };
  };

#endif
