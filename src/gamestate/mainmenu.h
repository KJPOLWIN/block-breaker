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
			//Background sprite
			AnimatedSprite background{ ResourceManager::/*Menu background sprite*/ };

			//Buttons
			NextStateButton startButton{ ResourceManager::/*button spirte*/,
										 							 sf::Vector2f(/*size*/),
										 						 	 ResourceManager::/*font*/,
										 							 "TEXT",
										 						 	 sf::Color::/*text color*/,
										 						 	 /*text size*/,
										 						 	 sf::Vector2f(/*text offset*/),
										 						 	 GameState::/*next gamestate*/ };

	};

#endif
