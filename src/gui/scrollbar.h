#ifndef SCROLLBAR_H
#define SCROLLBAR_H

  #include "animatedsprite.h"
  #include <SFML/Graphics.hpp>

  class ScrollBar
  {
    public:
      ScrollBar(AnimatedSprite barSprite, AnimatedSprite handleSprite,
                sf::Vector2f size, double increasePerPixel, double valueAtZeroX,
                sf::Vector2f position, sf::Vector2f handleOffset, double& followedValue)
        : bar{ barSprite },
          handle{ handleSprite },
          size{ size },
          increasePerPixel{ increasePerPixel },
          baseValue{ valueAtZeroX },
          followedValue{ &followedValue }
      {
        bar.setPosition(position);
        handle.setPosition(position + handleOffset);
      }

      ScrollBar() = default;

      void takeInput(sf::Vector2i clickPosition);
      void update(double elapsedTime);
      void draw(sf::RenderWindow* window);

        bool isTracking() { return followedValue != nullptr; }

    private:
      sf::Vector2f getPosition();
      bool isClicked(sf::Vector2i clickPosition);

      AnimatedSprite bar{  };
      AnimatedSprite handle{  };

      sf::Vector2f size{  };
      double increasePerPixel{ 0.0 };
      double baseValue{ 0.0 };

      double* followedValue{ nullptr };

  };

#endif
