#ifndef BALLCOLLIDER_H
#define BALLCOLLIDER_H

  #include "ball.h"
  #include <SFML/Graphics.hpp>

  class BallCollider
  {
    public:
      BallCollider(sf::Vector2f position, sf::Vector2f size);

      bool checkForCollisions(Ball& ball);
      void setColor(sf::Color color);
      void draw(sf::RenderWindow& targetWindow);

      sf::Vector2f getPosition();
      void setPosition(sf::Vector2f newPosition);

      sf::Vector2f getSize();

    private:
      sf::RectangleShape hitbox {};

  };

#endif
