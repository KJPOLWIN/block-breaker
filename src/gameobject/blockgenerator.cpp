#include "blockgenerator.h"
#include "block.h"
#include "constants.h"
#include "resourcemanager.h"
#include <SFML/Graphics.hpp>
#include <vector>

    #include <iostream>

BlockGenerator::BlockGenerator()
{
  blocks.push_back(Block(sf::Vector2f(constant::blockSize, constant::blockSize),
											 	 sf::Vector2f(constant::wallThickness + 2 * constant::gapSize + constant::blockSize,
                                      constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
												 ResourceManager::arial,
									       sf::Color::Red,
												 25));
}

void BlockGenerator::generateRow(int level)
{
  for( auto& block : blocks )
  {
    block.move(sf::Vector2f(0, constant::blockSize + constant::gapSize));
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
