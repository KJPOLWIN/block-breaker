#include "mainmenu.h"
#include "constants.h"
#include "guitext.h"
#include "gamestate.h"
#include "settingsmanager.h"
#include <SFML/Graphics.hpp>
#include <string>

MainMenu::MainMenu()
{
	startButton.setPosition(sf::Vector2f(/*position*/));

	background.setPosition(sf::Vector2f(constant::windowWidth * 0.5,
																			constant::windowHeight * 0.5));
}

void MainMenu::run(double& elapsedTime, sf::Vector2i& mousePosition, bool& canClick, guiText& fpsCounter, sf::RenderWindow& window, GameState& gamestate)
{
	//Button logic
	mousePosition = sf::Mouse::getPosition(window);
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && canClick)
	{
		canClick = false;

		if(!startButton.isTracking())	 startButton.setGameStateTracker(gamestate);

		startButton.takeInput(mousePosition);
	}

	//Updating everything
	background.update(elapsedTime);
	startButton.update(elapsedTime);

	fpsCounter.update(std::to_string(static_cast<int>(1 / elapsedTime)));

	//Drawing everything
	window.clear();

	background.draw(&window);
	startButton.draw(&window);

	if(SettingsManager::showFPSCounter)
	{
		fpsCounter.draw(&window);
	}

	window.display();
}
