#ifndef GAME_STATE_H
#define GAME_STATE_H

	#include "guitext.h"
	#include "gamestate.h"
	#include "ball.h"
	#include "wall.h"
	#include "block.h"
	#include "balldeletor.h"
	#include "ballgenerator.h"
	#include "guitext.h"
  #include "extraballpowerup.h"
  #include "verticaldamagepowerup.h"
  #include "horizontaldamagepowerup.h"
  #include "flipperpowerup.h"
	#include "resourcemanager.h"
	#include "blockgenerator.h"
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
			BallGenerator ballGenerator{
															 sf::Vector2f(constant::windowWidth * 0.5,
																					  constant::windowHeight
																				  - constant::wallThickness
																			    - constant::ballRadius - 10.0f),
													     0.1
														 };

			std::vector<Wall> walls{  };
			BlockGenerator blockGenerator{  };

			BallDeletor deletor{
													 sf::Vector2f(0, constant::windowHeight),
                           sf::Vector2f(constant::windowWidth,
														 						500)
												 };

			int level{ 1 };

			guiText levelText{
	                       ResourceManager::arial,
	                       "",
	                       constant::textColor,
	                       50,
	                       sf::Vector2f(constant::windowWidth - 200.f, 50.0f)
	                     };





      //DEBUG
      // void blocksDemo();
      // void xtrBallPowupDemo();
      // void horDamPowupDemo();
      // void verDamPowupDemo();
      // void flipPowupDemo();
	};

#endif
