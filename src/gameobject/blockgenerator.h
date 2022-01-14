#ifndef BLOCKGENERATOR_H
#define BLOCKGENERATOR_H

  #include "block.h"
  #include "ballgenerator.h"
  #include "extraballpowerup.h"
  #include "verticaldamagepowerup.h"
  #include "horizontaldamagepowerup.h"
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

      std::vector<Block> getBlocks();

      bool blocksInLastRow();

      void reset();

    private:
      std::vector<Block> blocks{  };
      std::vector<ExtraBallPowerUp> extraBallPowerUps{  };
      std::vector<VerticalDamagePowerUp> verticalDamagePowerUps{  };
      std::vector<HorizontalDamagePowerUp> horizontalDamagePowerUps{  };

  };

#endif
