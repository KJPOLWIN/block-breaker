#ifndef ARROW_H
#define ARROW_H

  #include "constants.h"
  #include "animatedsprite.h"
  #include "resourcemanager.h"
  #include <SFML/Graphics.hpp>

  class Arrow
  {
    public:
      Arrow();

      void update(sf::Vector2f start, sf::Vector2i end);
      void draw(sf::RenderWindow& targetWindow);

    private:
      AnimatedSprite arrowHead{ ResourceManager::arrowHead };
      sf::RectangleShape arrowBody{ sf::Vector2f(0, 15) };
      AnimatedSprite arrowBase{ ResourceManager::arrowBase };

  };

#endif
