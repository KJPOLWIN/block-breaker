#include "game.h"
#include "resourcemanager.h"
#include "guitext.h"
#include "gamestate.h"
#include "viewmanager.h"
#include "settingsmanager.h"
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
	game_state = Game_state();
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
	}

	switch(gamestate)
	{
		case GameState::MainMenu:
			mainMenu.run(elapsedTime, mousePosition, canClick, fpsCounter, window, gamestate);
		break;

		case GameState::Game:
			game_state.run(elapsedTime, mousePosition, canClick, fpsCounter, window, gamestate);
		break;

		case GameState::Exit:
			window.close();
		break;
	}
}
