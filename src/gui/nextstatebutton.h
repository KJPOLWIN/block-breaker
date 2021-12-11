#ifndef NEXTSTATEBUTTON_H
#define NEXTSTATEBUTTON_H

	#include "animatedsprite.h"
	#include "guitext.h"
	#include "gamestate.h"
	#include <SFML/Graphics.hpp>
	
	class NextStateButton
	{
		public:
			NextStateButton(AnimatedSprite sprite, sf::Vector2f size, sf::Font &font, 
						    std::string text, sf::Color color, unsigned int textSize, 
							sf::Vector2f textPosition, GameState nextGameState)
				: sprite{ sprite },
				  clickbox{ size },
				  text{ guiText(font, text, color, textSize, textPosition) },
				  textOffset{ textPosition },
				  gameStateTracker{ nullptr },
				  nextGameState{ nextGameState }
			{
				
			}
			
			void takeInput(sf::Vector2i clickPosition);
			void update(double elapsedTime);
			void draw(sf::RenderWindow *currentWindow);	
			
			bool isTracking();
			void setGameStateTracker(GameState& gameStateTracker);
			
			void setPosition(sf::Vector2f position);
			sf::Vector2f getPosition();
			
			bool isClicked(sf::Vector2i clickPosition);
		
		private:
			AnimatedSprite sprite;
			sf::Vector2f clickbox;
			guiText text;
			sf::Vector2f textOffset;
			GameState* gameStateTracker;
			GameState nextGameState;
			
			void changeAnimation(int animationID);
			
	};
	
#endif