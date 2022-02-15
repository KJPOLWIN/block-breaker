#include "game_state.h"
#include "constants.h"
#include "guitext.h"
#include "gamestate.h"
#include "settingsmanager.h"
#include "ball.h"
#include "wall.h"
#include "block.h"
#include "balldeletor.h"
#include "ballgenerator.h"
#include "blockgenerator.h"
#include <SFML/Graphics.hpp>
#include <string>

  #include <iostream>


// void Game_state::blocksDemo()
// {
//   for(int iii{ 0 }; iii < 7; ++iii)
//   {
//     blocksDebug.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) *constant::gapSize + iii * constant::blockSize,
//                                              constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
//                                 sf::Vector2f(constant::blockSize, constant::blockSize),
//                                 ResourceManager::arial,
//                                 sf::Color::Red,
//                                 30,
//                                 1));
//   }
//   for(int iii{ 0 }; iii < 7; ++iii)
//   {
//     if(iii != 3)
//     blocksDebug.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) *constant::gapSize + iii * constant::blockSize,
//                                              constant::wallThickness + 3 * constant::gapSize + 2 * constant::blockSize),
//                                 sf::Vector2f(constant::blockSize, constant::blockSize),
//                                 ResourceManager::arial,
//                                 sf::Color::Red,
//                                 30,
//                                 1));
//   }
// }
//
// void Game_state::xtrBallPowupDemo()
// {
//   xtrBallPowupsDebug.push_back(ExtraBallPowerUp(ResourceManager::extraBall,
//                                                 sf::Vector2f(100, 100),
//                                                 sf::Vector2f(constant::blockSize, constant::blockSize)));
//   xtrBallPowupsDebug.push_back(ExtraBallPowerUp(ResourceManager::extraBall,
//                                                 sf::Vector2f(500, 500),
//                                                 sf::Vector2f(constant::blockSize, constant::blockSize)));
// }
//
// void Game_state::horDamPowupDemo()
// {
//   for(int iii{ 0 }; iii < 7; ++iii)
//   {
//     if(iii == 3)
//     blocksDebug.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) *constant::gapSize + iii * constant::blockSize,
//                                              constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
//                                 sf::Vector2f(constant::blockSize, constant::blockSize),
//                                 ResourceManager::arial,
//                                 sf::Color::Red,
//                                 30,
//                                 1));
//   }
//   for(int iii{ 0 }; iii < 7; ++iii)
//   {
//     if(iii == 3)
//     blocksDebug.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) *constant::gapSize + iii * constant::blockSize,
//                                              constant::wallThickness + 3 * constant::gapSize + 2 * constant::blockSize),
//                                 sf::Vector2f(constant::blockSize, constant::blockSize),
//                                 ResourceManager::arial,
//                                 sf::Color::Red,
//                                 30,
//                                 1));
//   }
//   for(int iii{ 0 }; iii < 7; ++iii)
//   {
//     if(iii != 3)
//     blocksDebug.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) *constant::gapSize + iii * constant::blockSize,
//                                              constant::wallThickness + 4 * constant::gapSize + 3 * constant::blockSize),
//                                 sf::Vector2f(constant::blockSize, constant::blockSize),
//                                 ResourceManager::arial,
//                                 sf::Color::Red,
//                                 30,
//                                 1));
//   }
//
//   horDamPowupsDebug.push_back(HorizontalDamagePowerUp(ResourceManager::horizontalDamage,
//                                                       sf::Vector2f(constant::wallThickness + 4 *constant::gapSize + 3 * constant::blockSize,
//                                                                    constant::wallThickness + 4 * constant::gapSize + 3 * constant::blockSize),
//                                                       sf::Vector2f(constant::blockSize, constant::blockSize)));
// }
//
// void Game_state::verDamPowupDemo()
// {
//   for(int iii{ 0 }; iii < 7; ++iii)
//   {
//     if(iii == 3)
//     blocksDebug.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) *constant::gapSize + iii * constant::blockSize,
//                                              constant::wallThickness + 2 * constant::gapSize + constant::blockSize),
//                                 sf::Vector2f(constant::blockSize, constant::blockSize),
//                                 ResourceManager::arial,
//                                 sf::Color::Red,
//                                 30,
//                                 1));
//   }
//   for(int iii{ 0 }; iii < 7; ++iii)
//   {
//     if(iii == 3)
//     blocksDebug.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) *constant::gapSize + iii * constant::blockSize,
//                                              constant::wallThickness + 3 * constant::gapSize + 2 * constant::blockSize),
//                                 sf::Vector2f(constant::blockSize, constant::blockSize),
//                                 ResourceManager::arial,
//                                 sf::Color::Red,
//                                 30,
//                                 1));
//   }
//   for(int iii{ 0 }; iii < 7; ++iii)
//   {
//     if(iii != 3)
//     blocksDebug.push_back(Block(sf::Vector2f(constant::wallThickness + (iii + 1) *constant::gapSize + iii * constant::blockSize,
//                                              constant::wallThickness + 4 * constant::gapSize + 3 * constant::blockSize),
//                                 sf::Vector2f(constant::blockSize, constant::blockSize),
//                                 ResourceManager::arial,
//                                 sf::Color::Red,
//                                 30,
//                                 1));
//   }
//
//   verDamPowupsDebug.push_back(VerticalDamagePowerUp(ResourceManager::verticalDamage,
//                                                       sf::Vector2f(constant::wallThickness + 4 *constant::gapSize + 3 * constant::blockSize,
//                                                                    constant::wallThickness + 4 * constant::gapSize + 3 * constant::blockSize),
//                                                       sf::Vector2f(constant::blockSize, constant::blockSize)));
// }
//
// void Game_state::flipPowupDemo()
// {
//   flipDamPowupsDebug.push_back(FlipperPowerUp(ResourceManager::flipper,
//           sf::Vector2f(constant::windowWidth / 2, 200.0), sf::Vector2f(constant::blockSize, constant::blockSize)));
// }


Game_state::Game_state()
{
	walls.push_back(Wall(sf::Vector2f(0, 0),
											 sf::Vector2f(constant::windowWidth, constant::wallThickness)));
	walls.push_back(Wall(sf::Vector2f(0, 0),
											 sf::Vector2f(constant::wallThickness, constant::windowHeight)));
	walls.push_back(Wall(sf::Vector2f(constant::windowWidth - constant::wallThickness, 0),
											 sf::Vector2f(constant::wallThickness, constant::windowHeight)));


  // const int demo{ 4 };
  //
  // switch(demo)
  // {
  //   case 0:
  //     blocksDemo();
  //   break;
  //
  //   case 1:
  //     xtrBallPowupDemo();
  //   break;
  //
  //   case 2:
  //     horDamPowupDemo();
  //   break;
  //
  //   case 3:
  //     verDamPowupDemo();
  //   break;
  //
  //   case 4:
  //     flipPowupDemo();
  //   break;
  // }




}

void Game_state::run(double& elapsedTime, sf::Vector2i& mousePosition,
										 bool& canClick, guiText& fpsCounter,
										 sf::RenderWindow& window,
										 GameState& gamestate)
{
	//Button logic
	bool clicked{ false };
	mousePosition = sf::Mouse::getPosition(window);
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && canClick)
	{
		canClick = false;
		clicked = true;
	}
	else
	{
		clicked = false;
	}

	//Updating everything
	if(blockGenerator.blocksInLastRow())
	{
		blockGenerator.reset();
		ballGenerator.reset();
		level = 1;
		ballGenerator.setPosition( sf::Vector2f(constant::windowWidth * 0.5,
																				constant::windowHeight
																				- constant::wallThickness
																				- constant::ballRadius - 10.0f));
		gamestate = GameState::MainMenu;
	}

	for( auto& wall : walls )
	{
		for( auto& ball : ballGenerator.getBalls() )
		{
			wall.update(ball);
		}
	}

	blockGenerator.update(ballGenerator, ballGenerator.getNextLevelSignal(), level);
  // for( auto& block : blocksDebug )
  // {
  //   for( auto& ball : ballGenerator.getBalls() )
  //   {
  //     block.update(ball);
  //   }
  // }

	deletor.update(ballGenerator);

	ballGenerator.update(elapsedTime, mousePosition, clicked);

  // for( auto& xtrBallPowup : xtrBallPowupsDebug )
  // {
  //   xtrBallPowup.update(ballGenerator);
  // }
  // for( auto& horDamPowup : horDamPowupsDebug )
  // {
  //   horDamPowup.update(ballGenerator, blocksDebug);
  // }
  // for( auto& verDamPowup : verDamPowupsDebug )
  // {
  //   verDamPowup.update(ballGenerator, blocksDebug);
  // }
  // for( auto& flipDamPowup : flipDamPowupsDebug )
  // {
  //   flipDamPowup.update(ballGenerator);
  // }

	if(ballGenerator.getNextLevelSignal())
	{
		++level;
	}

	levelText.update(std::to_string(level));

  fpsCounter.update(std::to_string(static_cast<int>(1 / elapsedTime)));

	//Drawing everything
	window.clear(constant::backgroundColor);

	ballGenerator.draw(window);

	for( auto& wall : walls )
	{
		wall.draw(window);
	}

	blockGenerator.draw(window);

  // for( auto& block : blocksDebug )
  // {
  //   block.draw(window);
  // }
  //
  // for( auto& xtrBallPowup : xtrBallPowupsDebug )
  // {
  //   xtrBallPowup.draw(window);
  // }
  // for( auto& horDamPowup : horDamPowupsDebug )
  // {
  //   horDamPowup.draw(window);
  // }
  // for( auto& verDamPowup : verDamPowupsDebug )
  // {
  //   verDamPowup.draw(window);
  // }
  // for( auto& flipDamPowup : flipDamPowupsDebug )
  // {
  //   flipDamPowup.draw(window);
  // }

	if(SettingsManager::showFPSCounter)
	{
		fpsCounter.draw(&window);
	}

	levelText.draw(&window);

	window.display();
}
