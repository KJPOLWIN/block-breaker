#ifndef GAME_STATE_H
#define GAME_STATE_H

	#include "guitext.h"
	#include "gamestate.h"
	#include "ball.h"
	#include "wall.h"
	#include "balldeletor.h"
	#include "ballgenerator.h"
	#include <SFML/Graphics.hpp>
	#include <vector>

	class Game_state
	{
		public:
			Game_state();

			void run(double& elapsedTime, sf::Vector2i& mousePosition, bool& canClick, guiText& fpsCounter, sf::RenderWindow& window, GameState& gamestate);

		private:
			BallGenerator generator{ sf::Vector2f(constant::windowWidth * 0.5,
																					  constant::windowHeight
																				  - constant::wallThickness
																			    - constant::ballRadius - 10.0f),
													     1.0 };

			std::vector<Wall> walls;
			BallDeletor deletor{ sf::Vector2f(constant::windowWidth, constant::wallThickness),
													 sf::Vector2f(0, constant::windowHeight - constant::wallThickness) };
	};

#endif
