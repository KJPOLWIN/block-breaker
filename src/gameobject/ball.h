#ifndef BALL_H
#define BALL_H

  #include "constants.h"
  #include "random.h"
  #include <SFML/Graphics.hpp>

  class Ball {
    public:
      Ball(sf::Vector2f initialPosition, double speed, sf::Vector2f direction);

      void update(double elapsedTime);
      void draw(sf::RenderWindow& targetWindow);

      void bounce(sf::Vector2i hitDirection);

      sf::Vector2f getPosition();
      sf::FloatRect getGlobalBounds();

      void deflect();

    private:
      sf::Vector2f position{ 0, 0 };
      sf::Vector2f velocity{ 0, 1.0f };

      sf::CircleShape ball{ constant::ballRadius };
  };

#endif
