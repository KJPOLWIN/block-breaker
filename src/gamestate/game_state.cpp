#include "game_state.h"
#include "constants.h"
#include "guitext.h"
#include "gamestate.h"
#include "settingsmanager.h"
#include "ball.h"
#include "wall.h"
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
}

void Game_state::run(double& elapsedTime, sf::Vector2i& mousePosition, bool& canClick, guiText& fpsCounter, sf::RenderWindow& window, GameState& gamestate)
{
	//Button logic
	mousePosition = sf::Mouse::getPosition(window);
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && canClick)
	{
		canClick = false;


	}

	//Updating everything
	generator.shotBall(elapsedTime);

	for( auto& wall : walls )
	{
		for( auto& ball : generator.getBalls() )
		{
			wall.checkForCollisions(ball);
		}
	}

	for( auto& ball : generator.getBalls() )
	{
		ball.update(elapsedTime);
	}

  fpsCounter.update(std::to_string(static_cast<int>(1 / elapsedTime)));

	//Drawing everything
	window.clear(sf::Color::Black);

	for( auto& ball : generator.getBalls() )
	{
		ball.draw(window);
	}

	for( auto& wall : walls )
	{
		wall.draw(window);
	}

	if(SettingsManager::showFPSCounter)
	{
		fpsCounter.draw(&window);
	}

	window.display();
}
