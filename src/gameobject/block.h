#ifndef BLOCK_H
#define BLOCK_H

  #include "ballcollider.h"
  #include "ball.h"
  #include "guitext.h"
  #include "constants.h"
  #include <SFML/Graphics.hpp>

  class Block : public BallCollider
  {
    public:
      Block(sf::Vector2f position, sf::Vector2f size, sf::Font &textFont,
            unsigned int textSize, int hitPoints);

      void update(Ball& ball);
      void draw(sf::RenderWindow& targetWindow);

      void decreaseHealth(int damage = 1);

      bool isAlive();

      void move();

      int getRow();
      int getColumn();

    private:
      bool wasHitInCurrentFrame{ false };
      int hitPoints{ 1 };

      guiText hitPointsText{  };

      sf::Vector2i gridPosition{  };  //Position in grid, not in xy coordinates
  };

#endif
