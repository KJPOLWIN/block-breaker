#ifndef GAME_H
#define GAME_H

	#include "guitext.h"
	#include "constants.h"
	#include "gamestate.h"
	#include "mainmenu.h"
	#include <SFML/Graphics.hpp>

	class Game
	{
		public:
			Game();

			void run();

		private:
			void gameLoop();

			//Window
			sf::RenderWindow window{ sf::VideoMode(constant::windowWidth,
																						 constant::windowHeight),
									 						 "",
									 					   constant::windowStyle };

			//Game state setup
			GameState gamestate{ GameState::MainMenu };

			MainMenu mainMenu;			//Note: game states aren't initialized here,
															//	  	because they must be initialized
															//  		AFTER resources are loaded
			//add new gamestates here

			//FPS counter
			guiText fpsCounter{ /*Font*/,
													"",
													constant::fpsCounterColor,
													50,
													sf::Vector2f(50, 50) };

			//Mouse position
			sf::Vector2i mousePosition{ 0, 0 };
			bool canClick{ true };

			//Event
			sf::Event event{  };

			//Clock and time
			sf::Clock clock{  };
			double elapsedTime{ 0.0 };

	};

#endif
