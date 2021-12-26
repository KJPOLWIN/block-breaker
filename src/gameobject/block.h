#ifndef BLOCK_H
#define BLOCK_H

  #include "block.h"
  #include "ball.h"
  #include "guitext.h"
  #include "constants.h"
  #include <SFML/Graphics.hpp>

  class Block
  {
    public:
      Block(sf::Vector2f size, sf::Vector2f position, sf::Font &font,
            sf::Color textColor, unsigned int textSize, int hitPoints);

      void checkForCollisions(Ball& ball);
      void draw(sf::RenderWindow& targetWindow);

      bool isAlive();

      void move();

      int getRow();

    private:
      sf::RectangleShape block{  };
      bool wasHitInCurrentFrame{ false };
      int hitPoints{ 30 };

      guiText hitPointsText{  };

      int row{ 2 };
  };

#endif
