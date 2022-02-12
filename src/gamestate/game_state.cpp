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

Game_state::Game_state()
{
	walls.push_back(Wall(sf::Vector2f(0, 0),
											 sf::Vector2f(constant::windowWidth, constant::wallThickness)));
	walls.push_back(Wall(sf::Vector2f(0, 0),
											 sf::Vector2f(constant::wallThickness, constant::windowHeight)));
	walls.push_back(Wall(sf::Vector2f(constant::windowWidth - constant::wallThickness, 0),
											 sf::Vector2f(constant::wallThickness, constant::windowHeight)));
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
	// if(blockGenerator.blocksInLastRow())
	// {
	// 	blockGenerator.reset();
	// 	ballGenerator.reset();
	// 	level = 1;
	// 	ballGenerator.setPosition( sf::Vector2f(constant::windowWidth * 0.5,
	// 																			constant::windowHeight
	// 																			- constant::wallThickness
	// 																			- constant::ballRadius - 10.0f));
	// 	gamestate = GameState::MainMenu;
	// }

	for( auto& wall : walls )
	{
		for( auto& ball : ballGenerator.getBalls() )
		{
			wall.update(ball);
		}
	}

	// blockGenerator.update(ballGenerator, ballGenerator.getNextLevelSignal(), level);

	deletor.update(ballGenerator);

	ballGenerator.update(elapsedTime, mousePosition, clicked);

	if(ballGenerator.getNextLevelSignal())
	{
		++level;
	}

	levelText.update(std::to_string(level));

  fpsCounter.update(std::to_string(static_cast<int>(1 / elapsedTime)));

	//Drawing everything
	window.clear(sf::Color::Black);

	ballGenerator.draw(window);

	for( auto& wall : walls )
	{
		wall.draw(window);
	}


	// blockGenerator.draw(window);

	if(SettingsManager::showFPSCounter)
	{
		fpsCounter.draw(&window);
	}

	levelText.draw(&window);

	window.display();
}
