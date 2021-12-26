#include "blockgenerator.h"
#include "block.h"
#include "constants.h"
#include "resourcemanager.h"
#include "random.h"
#include <SFML/Graphics.hpp>
#include <vector>

BlockGenerator::BlockGenerator()
{
  generateRow(1);
}

void BlockGenerator::generateRow(int level)
{
  for( auto& block : blocks )
  {
    block.move();
  }

  int blocksToAdd{ Random::getRandom(1, constant::blocksInRow - 1) };

  for(int iii{ 0 }; iii < constant::blocksInRow; ++iii)
  {
    if(constant::blocksInRow - iii > blocksToAdd)
    {
      int random{ Random::getRandom(1, constant::blocksInRow - iii) };
      if(random == 1)
      {
        blocks.push_back(Block(sf::Vector2f(constant::blockSize, constant::blockSize),
      											 	 sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                            constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
      												 ResourceManager::arial,
      									       sf::Color::Red,
      												 25,
                               level));
        --blocksToAdd;
      }
    }
    else
    {
      blocks.push_back(Block(sf::Vector2f(constant::blockSize, constant::blockSize),
    											 	 sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                          constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
    												 ResourceManager::arial,
    									       sf::Color::Red,
    												 25,
                             level));
      --blocksToAdd;
    }

    if(blocksToAdd < 1)
    {
      break;
    }
  }
}

void BlockGenerator::update(BallGenerator& generator, bool nextLevelSignal, int level)
{
  if(nextLevelSignal)
  {
    generateRow(level);
  }

  for(std::size_t iii{ 0 }; iii < blocks.size(); ++iii)
	{
		for( auto& ball : generator.getBalls() )
		{
			blocks.at(iii).checkForCollisions(ball);
		}

		if(!blocks.at(iii).isAlive())
		{
			blocks.erase(blocks.begin() + iii);
		}
	}
}

void BlockGenerator::draw(sf::RenderWindow& targetWindow)
{
  for( auto& block : blocks )
  {
    block.draw(targetWindow);
  }
}

bool BlockGenerator::blocksInLastRow()
{
  for( auto& block : blocks )
  {
    if(block.getRow() == constant::blocksInColumn + 1)
    {
      return true;
    }
  }

  return false;
}

void BlockGenerator::reset()
{
  blocks.clear();
  generateRow(1);
}
