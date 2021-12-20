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
#include <SFML/Graphics.hpp>
#include <string>

Game_state::Game_state()
{
	walls.push_back(Wall(sf::Vector2f(constant::windowWidth, constant::wallThickness),
											 sf::Vector2f(0, 0)));
	walls.push_back(Wall(sf::Vector2f(constant::wallThickness, constant::windowHeight),
											 sf::Vector2f(0, 0)));
	walls.push_back(Wall(sf::Vector2f(constant::wallThickness, constant::windowHeight),
											 sf::Vector2f(constant::windowWidth - constant::wallThickness, 0)));

	blocks.push_back(Block(sf::Vector2f(100.f, 100.f),
											 	 sf::Vector2f(100.f, 100.f),
												 ResourceManager::arial,
									       sf::Color::Red, 
												 25));
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
	for( auto& wall : walls )
	{
		for( auto& ball : generator.getBalls() )
		{
			wall.checkForCollisions(ball);
		}
	}

	//for( auto& block : blocks )
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

	deletor.checkForCollisions(generator);

	generator.update(elapsedTime, mousePosition, clicked);

  fpsCounter.update(std::to_string(static_cast<int>(1 / elapsedTime)));
	ballsNumberText.update(std::to_string(generator.getBallsNumber()) + "/" + std::to_string(generator.getMaxBallsNumber()));
	//Drawing everything
	window.clear(sf::Color::Black);

	generator.draw(window);

	for( auto& wall : walls )
	{
		wall.draw(window);
	}

	for( auto& block : blocks )
	{
		block.draw(window);
	}

	if(SettingsManager::showFPSCounter)
	{
		fpsCounter.draw(&window);
	}

	ballsNumberText.draw(&window);

	window.display();
}
