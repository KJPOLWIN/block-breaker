#include "game_state.h"
#include "constants.h"
#include "guitext.h"
#include "gamestate.h"
#include "settingsmanager.h"
#include <SFML/Graphics.hpp>
#include <string>

Game_state::Game_state()
{

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
  fpsCounter.update(std::to_string(static_cast<int>(1 / elapsedTime)));

	testBall.update(elapsedTime);

	//Drawing everything
	window.clear(sf::Color::Black);

	testBall.draw(window);

	if(SettingsManager::showFPSCounter)
	{
		fpsCounter.draw(&window);
	}

	window.display();
}
