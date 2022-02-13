#ifndef BALLDELETOR_H
#define BALLDELETOR_H

  #include "ballcollider.h"
  #include "ball.h"
  #include "ballgenerator.h"
  #include <SFML/Graphics.hpp>

  class BallDeletor : public BallCollider
  {
    public:
      BallDeletor(sf::Vector2f position, sf::Vector2f size);

      void update(BallGenerator& ballGenerator);

    private:
      bool firstHit{ true };
      double generatorNewPosition{ 0 }; //x coord
  };

#endif
