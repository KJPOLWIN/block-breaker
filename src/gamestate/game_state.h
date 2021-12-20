#ifndef GAME_STATE_H
#define GAME_STATE_H

	#include "guitext.h"
	#include "gamestate.h"
	#include "ball.h"
	#include "wall.h"
	#include "balldeletor.h"
	#include "ballgenerator.h"
	#include "guitext.h"
	#include "resourcemanager.h"
	#include "constants.h"
	#include <SFML/Graphics.hpp>
	#include <vector>

	class Game_state
	{
		public:
			Game_state();

			void run(double& elapsedTime, sf::Vector2i& mousePosition,
							 bool& canClick, guiText& fpsCounter, sf::RenderWindow& window,
							 GameState& gamestate);

		private:
			BallGenerator generator{
															 sf::Vector2f(constant::windowWidth * 0.5,
																					  constant::windowHeight
																				  - constant::wallThickness
																			    - constant::ballRadius - 10.0f),
													     0.2
														 };

			std::vector<Wall> walls;
			BallDeletor deletor{
													 sf::Vector2f(constant::windowWidth,
														 						constant::wallThickness),
													 sf::Vector2f(0,
														 						constant::windowHeight
																			- constant::wallThickness)
												 };

			guiText ballsNumberText{
															 ResourceManager::arial,
															 "",
															 sf::Color::Red,
						  								 50,
															 sf::Vector2f(constant::windowWidth - 200.0,
																 								25.0)
														 };
	};

#endif
