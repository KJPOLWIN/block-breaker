#include "blockgenerator.h"
#include "block.h"
#include "constants.h"
#include "extraballpowerup.h"
#include "verticaldamagepowerup.h"
#include "horizontaldamagepowerup.h"
#include "resourcemanager.h"
#include "random.h"
#include <SFML/Graphics.hpp>
#include <vector>

  #include <iostream>

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

  for( auto& extraBallPowerUp : extraBallPowerUps )
  {
    extraBallPowerUp.move();
  }

  for( auto& verticalDamagePowerUp : verticalDamagePowerUps )
  {
    verticalDamagePowerUp.move();
  }

  for( auto& horizontalDamagePowerUp : horizontalDamagePowerUps )
  {
    horizontalDamagePowerUp.move();
  }

  int blocksToAdd{ Random::getRandomInt(1, constant::blocksInRow - 1) };
  int powerUpsToAdd{ Random::getRandomInt(1, constant::blocksInRow - 1 - blocksToAdd) };

  for(int iii{ 0 }; iii < constant::blocksInRow; ++iii)
  {
    if(blocksToAdd == 0 && powerUpsToAdd == 0) break;

    if(constant::blocksInRow - iii > blocksToAdd)
    {
      //If dice below has too many sides, all blocks will generate on right side.
      //If it has too few sides, all blocks will generate on left side
      //Choose some number and test it
      int random{ Random::getRandomInt(1, 2) };

      if(random == 1 && blocksToAdd > 0)
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
      else if(powerUpsToAdd > 0)
      {
        if(constant::blocksInRow - iii - blocksToAdd > 1)
        {
          random = Random::getRandomInt(1, 4);

          if(random == 1)
          {
            extraBallPowerUps.push_back(
              ExtraBallPowerUp(ResourceManager::extraBall,
                             sf::Vector2f(constant::blockSize, constant::blockSize),
                             sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                          constant::wallThickness + 2 * constant::gapSize + constant::blockSize))
                                        );
            --powerUpsToAdd;
          }
          else if(random == 2)
          {
            verticalDamagePowerUps.push_back(
              VerticalDamagePowerUp(ResourceManager::verticalDamage,
                             sf::Vector2f(constant::blockSize, constant::blockSize),
                             sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                          constant::wallThickness + 2 * constant::gapSize + constant::blockSize))
                                        );
            --powerUpsToAdd;
          }
          else
          {
            horizontalDamagePowerUps.push_back(
              HorizontalDamagePowerUp(ResourceManager::verticalDamage,
                             sf::Vector2f(constant::blockSize, constant::blockSize),
                             sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                          constant::wallThickness + 2 * constant::gapSize + constant::blockSize))
                                        );
            --powerUpsToAdd;
          }
        }
        else
        {
          extraBallPowerUps.push_back(
            ExtraBallPowerUp(ResourceManager::extraBall,
                           sf::Vector2f(constant::blockSize, constant::blockSize),
                           sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                        constant::wallThickness + 2 * constant::gapSize + constant::blockSize))
                                      );
          --powerUpsToAdd;
        }
      }
    }
    else if(blocksToAdd > 0)
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


  for( auto& block : blocks )
  {
    std::cout << block.getColumn() << ", " << block.getRow() << "\n";
  }
  std::cout << "\n";
  for( auto& extraBallPowerUp : extraBallPowerUps )
  {
    std::cout << extraBallPowerUp.getPosition().x << ", " << extraBallPowerUp.getPosition().y << "\n";
  }
  std::cout << "\n";
  for( auto& verticalDamagePowerUp : verticalDamagePowerUps )
  {
    std::cout << verticalDamagePowerUp.getPosition().x << ", " << verticalDamagePowerUp.getPosition().y << "\n";
  }
  std::cout << "\n";
  for( auto& horizontalDamagePowerUp : horizontalDamagePowerUps )
  {
    std::cout << horizontalDamagePowerUp.getPosition().x << ", " << horizontalDamagePowerUp.getPosition().y << "\n";
  }
  std::cout << "\n\n";
}

void BlockGenerator::update(BallGenerator& generator, bool nextLevelSignal, int level)
{
  if(nextLevelSignal)
  {
    generateRow(level);

    for(std::size_t iii{ 0 }; iii < verticalDamagePowerUps.size(); ++iii)
  	{
  		if(!verticalDamagePowerUps.at(iii).isAlive())
  		{
  			verticalDamagePowerUps.erase(verticalDamagePowerUps.begin() + iii);
  		}
  	}

    for(std::size_t iii{ 0 }; iii < horizontalDamagePowerUps.size(); ++iii)
  	{
  		if(!horizontalDamagePowerUps.at(iii).isAlive())
  		{
  			horizontalDamagePowerUps.erase(horizontalDamagePowerUps.begin() + iii);
  		}
  	}
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

  for( auto& verticalDamagePowerUp : verticalDamagePowerUps )
  {
    verticalDamagePowerUp.update(generator, blocks);
  }

  for( auto& horizontalDamagePowerUp : horizontalDamagePowerUps )
  {
    horizontalDamagePowerUp.update(generator, blocks);
  }

  for(std::size_t iii{ 0 }; iii < extraBallPowerUps.size(); ++iii)
	{
    extraBallPowerUps.at(iii).update(generator);

    if(!extraBallPowerUps.at(iii).isAlive())
    {
      extraBallPowerUps.erase(extraBallPowerUps.begin() + iii);
    }
	}
}

void BlockGenerator::draw(sf::RenderWindow& targetWindow)
{
  for( auto& block : blocks )
  {
    block.draw(targetWindow);
  }

  for( auto& extraBallPowerUp : extraBallPowerUps )
  {
    extraBallPowerUp.draw(targetWindow);
  }

  for( auto& verticalDamagePowerUp : verticalDamagePowerUps )
  {
    verticalDamagePowerUp.draw(targetWindow);
  }
}

std::vector<Block> BlockGenerator::getBlocks()
{
  return blocks;
}

bool BlockGenerator::blocksInLastRow()
{
  for( auto& block : blocks )
  {
    if(block.getRow() == constant::blocksInColumn)
    {
      return true;
    }
  }

  return false;
}

void BlockGenerator::reset()
{
  blocks.clear();
  extraBallPowerUps.clear();
  verticalDamagePowerUps.clear();
  generateRow(1);
}
