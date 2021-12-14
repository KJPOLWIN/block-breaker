#ifndef MAINMENU_H
#define MAINMENU_H

	#include "guitext.h"
	#include "gamestate.h"
	#include "animatedsprite.h"
	#include "resourcemanager.h"
	#include "nextstatebutton.h"
	#include <SFML/Graphics.hpp>

	class MainMenu
	{
		public:
			MainMenu();

			void run(double& elapsedTime, sf::Vector2i& mousePosition, bool& canClick, guiText& fpsCounter, sf::RenderWindow& window, GameState& gamestate);

		private:
			//Buttons
			NextStateButton startButton{ ResourceManager::startButton,
										 							 sf::Vector2f(200, 200),
										 						 	 ResourceManager::arial,
										 							 "",
										 						 	 sf::Color::White,
										 						 	 0,
										 						 	 sf::Vector2f(0, 0),
										 						 	 GameState::Game };

	};

#endif
