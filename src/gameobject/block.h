#ifndef BLOCK_H
#define BLOCK_H

  #include "block.h"
  #include "ball.h"
  #include "guitext.h"
  #include <SFML/Graphics.hpp>

  class Block
  {
    public:
      Block(sf::Vector2f size, sf::Vector2f position, sf::Font &font,
            sf::Color textColor, unsigned int textSize);

      void checkForCollisions(Ball& ball);
      void draw(sf::RenderWindow& targetWindow);

      bool isAlive();

    private:
      sf::RectangleShape block{  };
      bool wasHitInCurrentFrame{ false };
      int hitPoints{ 30 };

      guiText hitPointsText{  };
  };

#endif
