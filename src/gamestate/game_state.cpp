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
	if(blocks.blocksInLastRow())
	{
		blocks.reset();
		generator.reset();
		level = 1;
		generator.setPosition( sf::Vector2f(constant::windowWidth * 0.5,
																				constant::windowHeight
																				- constant::wallThickness
																				- constant::ballRadius - 10.0f));
		gamestate = GameState::MainMenu;
	}

	for( auto& wall : walls )
	{
		for( auto& ball : generator.getBalls() )
		{
			wall.update(ball);
		}
	}

	blocks.update(generator, generator.getNextLevelSignal(), level);

	deletor.checkForCollisions(generator);

	generator.update(elapsedTime, mousePosition, clicked);

	if(generator.getNextLevelSignal())
	{
		++level;
	}

	levelText.update(std::to_string(level));

  fpsCounter.update(std::to_string(static_cast<int>(1 / elapsedTime)));

	//Drawing everything
	window.clear(sf::Color::Black);

	generator.draw(window);

	for( auto& wall : walls )
	{
		wall.draw(window);
	}


	blocks.draw(window);

	if(SettingsManager::showFPSCounter)
	{
		fpsCounter.draw(&window);
	}

	levelText.draw(&window);

	window.display();
}
