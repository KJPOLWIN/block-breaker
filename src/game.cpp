#include "game.h"
#include "resourcemanager.h"
#include "guitext.h"
#include "gamestate.h"
#include "viewmanager.h"
#include <SFML/Graphics.hpp>

Game::Game()
{
	//loading resources
	ResourceManager::load();

	//loading default settings
	window.setFramerateLimit(SettingsManager::fpsLimit);
	window.setVerticalSyncEnabled(SettingsManager::enableVSync);

	//initializing states
	mainMenu = MainMenu();
	//initialize here new gamestates
}

void Game::run()
{
	while(window.isOpen())
	{
		gameLoop();
	}
}

void Game::gameLoop()
{
	elapsedTime = clock.restart().asSeconds();

	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if(!canClick && event.type == sf::Event::MouseButtonReleased)
		{
			canClick = true;
		}

		//delete this to disable zoom
		if(event.type == sf::Event::MouseWheelScrolled)
		{
			if(event.mouseWheelScroll.delta > 0)
			{
				ViewManager::zoomDirection = -1;
			}
			else
			{
				ViewManager::zoomDirection = 1;
			}
		}
	}

	switch(gamestate)
	{
		case GameState::MainMenu:
			mainMenu.run(elapsedTime, mousePosition, canClick, fpsCounter, window, gamestate);
		break;

		//add cases for new gamestates

		case GameState::Exit:
			window.close();
		break;
	}
}
