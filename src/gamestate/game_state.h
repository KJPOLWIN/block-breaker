#ifndef GAME_STATE_H
#define GAME_STATE_H

	#include "guitext.h"
	#include "gamestate.h"
	#include "ball.h"
	#include "wall.h"
	#include <SFML/Graphics.hpp>
	#include <vector>

	class Game_state
	{
		public:
			Game_state();

			void run(double& elapsedTime, sf::Vector2i& mousePosition, bool& canClick, guiText& fpsCounter, sf::RenderWindow& window, GameState& gamestate);

		private:
			Ball testBall{ sf::Vector2f(400, 500), 100.0, sf::Vector2f(-1.0f, -1.0f) };
			std::vector<Wall> walls;
	};

#endif
