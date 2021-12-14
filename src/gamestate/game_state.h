#ifndef GAME_STATE_H
#define GAME_STATE_H

	#include "guitext.h"
	#include "gamestate.h"
	#include <SFML/Graphics.hpp>

	class Game_state
	{
		public:
			Game_state();

			void run(double& elapsedTime, sf::Vector2i& mousePosition, bool& canClick, guiText& fpsCounter, sf::RenderWindow& window, GameState& gamestate);

		private:

	};

#endif
