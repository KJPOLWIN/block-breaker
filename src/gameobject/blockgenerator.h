#ifndef BLOCKGENERATOR_H
#define BLOCKGENERATOR_H

  #include "block.h"
  #include "ballgenerator.h"
  #include "constants.h"
  #include <SFML/Graphics.hpp>
  #include <vector>

  class BlockGenerator
  {
    public:
      BlockGenerator();

      void generateRow(int level);

      void update(BallGenerator& generator, bool nextLevelSignal, int level);
      void draw(sf::RenderWindow& targetWindow);

    private:
      std::vector<Block> blocks;

  };

#endif
