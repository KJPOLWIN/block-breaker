#include "blockgenerator.h"
#include "block.h"
#include "constants.h"
#include "extraballpowerup.h"
#include "verticaldamagepowerup.h"
#include "horizontaldamagepowerup.h"
#include "resourcemanager.h"
#include "flipperpowerup.h"
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

  for( auto& flipperPowerUp : flipperPowerUps )
  {
    flipperPowerUp.move();
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
        blocks.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                            constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
                               sf::Vector2f(constant::blockSize, constant::blockSize),
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
                             sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                          constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
                            sf::Vector2f(constant::blockSize, constant::blockSize)
                          ));
            --powerUpsToAdd;
          }
          else if(random == 2)
          {
            verticalDamagePowerUps.push_back(
              VerticalDamagePowerUp(ResourceManager::verticalDamage,
                             sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                          constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
                                    sf::Vector2f(constant::blockSize, constant::blockSize)
                                  ));
            --powerUpsToAdd;
          }
          else if(random == 3)
          {
            horizontalDamagePowerUps.push_back(
              HorizontalDamagePowerUp(ResourceManager::horizontalDamage,
                             sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                          constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
                                          sf::Vector2f(constant::blockSize, constant::blockSize)
                                        ));
            --powerUpsToAdd;
          }
          else
          {
            flipperPowerUps.push_back(
              FlipperPowerUp(ResourceManager::flipper,
                             sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                          constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
                                          sf::Vector2f(constant::blockSize, constant::blockSize)
                                        ));
            --powerUpsToAdd;
          }
        }
        else
        {
          extraBallPowerUps.push_back(
            ExtraBallPowerUp(ResourceManager::extraBall,
                           sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                        constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
                                        sf::Vector2f(constant::blockSize, constant::blockSize)
                                      ));
          --powerUpsToAdd;
        }
      }
    }
    else if(blocksToAdd > 0)
    {
      blocks.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) * constant::gapSize + iii * constant::blockSize,
                                          constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
                                          sf::Vector2f(constant::blockSize, constant::blockSize),
    												 ResourceManager::arial,
    									       sf::Color::Red,
    												 25,
                             level));
      --blocksToAdd;
    }
  }


  // for( auto& block : blocks )
  // {
  //   std::cout << block.getColumn() << ", " << block.getRow() << "\n";
  // }
  // std::cout << "\n";
  // for( auto& extraBallPowerUp : extraBallPowerUps )
  // {
  //   std::cout << extraBallPowerUp.getPosition().x << ", " << extraBallPowerUp.getPosition().y << "\n";
  // }
  // std::cout << "\n";
  // for( auto& verticalDamagePowerUp : verticalDamagePowerUps )
  // {
  //   std::cout << verticalDamagePowerUp.getPosition().x << ", " << verticalDamagePowerUp.getPosition().y << "\n";
  // }
  // std::cout << "\n";
  // for( auto& horizontalDamagePowerUp : horizontalDamagePowerUps )
  // {
  //   std::cout << horizontalDamagePowerUp.getPosition().x << ", " << horizontalDamagePowerUp.getPosition().y << "\n";
  // }
  // std::cout << "\n\n";
}

void BlockGenerator::update(BallGenerator& generator, bool nextLevelSignal, int level)
{
  for( auto& extraBallPowerUp : extraBallPowerUps )
  {
    extraBallPowerUp.update(generator);
  }

  //this algorithm ensures that vector doesn't get displaced
  //when elements are deleted, in which case crashes may happen

  bool notAnyObjectDeleted{ false };
  while(!notAnyObjectDeleted)
  {
    notAnyObjectDeleted = true;
    for(int iii{ 0 }; iii < extraBallPowerUps.size(); ++iii)
    {
      if(!extraBallPowerUps.at(iii).isAlive())
      {
        extraBallPowerUps.erase(extraBallPowerUps.begin() + iii);
        notAnyObjectDeleted = false;
        break;
      }
    }
  }


  // for(std::size_t iii{ 0 }; iii < extraBallPowerUps.size(); ++iii)
	// {
  //   if(!extraBallPowerUps.at(iii).isAlive())
  //   {
  //     extraBallPowerUps.erase(extraBallPowerUps.begin() + iii);
  //   }
	// }

  for( auto& block : blocks )
  {
    for( auto& ball : generator.getBalls() )
    {
      block.update(ball);
    }
  }

  notAnyObjectDeleted = false;
  while(!notAnyObjectDeleted)
  {
    notAnyObjectDeleted = true;
    for(int iii{ 0 }; iii < blocks.size(); ++iii)
    {
      if(!blocks.at(iii).isAlive())
      {
        blocks.erase(blocks.begin() + iii);
        notAnyObjectDeleted = false;
        break;
      }
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

  for( auto& flipperPowerUp : flipperPowerUps )
  {
    flipperPowerUp.update(generator);
  }

  if(nextLevelSignal)
  {
    notAnyObjectDeleted = false;
    while(!notAnyObjectDeleted)
    {
      notAnyObjectDeleted = true;
      for(int iii{ 0 }; iii < verticalDamagePowerUps.size(); ++iii)
      {
        if(!verticalDamagePowerUps.at(iii).isAlive())
        {
          verticalDamagePowerUps.erase(verticalDamagePowerUps.begin() + iii);
          notAnyObjectDeleted = false;
          break;
        }
      }
    }

    notAnyObjectDeleted = false;
    while(!notAnyObjectDeleted)
    {
      notAnyObjectDeleted = true;
      for(int iii{ 0 }; iii < horizontalDamagePowerUps.size(); ++iii)
      {
        if(!horizontalDamagePowerUps.at(iii).isAlive())
        {
          horizontalDamagePowerUps.erase(horizontalDamagePowerUps.begin() + iii);
          notAnyObjectDeleted = false;
          break;
        }
      }
    }

    notAnyObjectDeleted = false;
    while(!notAnyObjectDeleted)
    {
      notAnyObjectDeleted = true;
      for(int iii{ 0 }; iii < flipperPowerUps.size(); ++iii)
      {
        if(!flipperPowerUps.at(iii).isAlive())
        {
          flipperPowerUps.erase(flipperPowerUps.begin() + iii);
          notAnyObjectDeleted = false;
          break;
        }
      }
    }

    generateRow(level);
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

  for( auto& horizontalDamagePowerUp : horizontalDamagePowerUps )
  {
    horizontalDamagePowerUp.draw(targetWindow);
  }

  for( auto& flipperPowerUp : flipperPowerUps )
  {
    flipperPowerUp.draw(targetWindow);
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
  horizontalDamagePowerUps.clear();
  flipperPowerUps.clear();
  generateRow(1);
}
