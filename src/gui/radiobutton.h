#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

	#include "animatedsprite.h"
	#include "guitext.h"
	#include <SFML/Graphics.hpp>
	
	class RadioButton
	{
		public:
			RadioButton(AnimatedSprite sprite, sf::Vector2f size, sf::Font &font, 
						std::string text, sf::Color color, unsigned int textSize, 
						sf::Vector2f textPosition, int yield)
				: sprite{ sprite },
				  clickbox{ size },
				  text{ guiText(font, text, color, textSize, textPosition) },
				  textOffset{ textPosition },
				  yield{ yield }
			{
				
			}
			
			RadioButton(AnimatedSprite sprite, sf::Vector2f size, int yield)
				: sprite{ sprite },
				  clickbox{ size },
				  text{ guiText() },
				  textOffset{ sf::Vector2f() },
				  yield{ yield }
			{
				
			}
			
			void update(double elapsedTime);
			void draw(sf::RenderWindow *currentWindow);
			
			bool isClicked(sf::Vector2i clickPosition);
			void changeAnimation(int animationID);
			
			void setPosition(sf::Vector2f position);
			sf::Vector2f getPosition();
			
			int getYield();
		
		private:
			AnimatedSprite sprite;
			sf::Vector2f clickbox;
			guiText text;
			sf::Vector2f textOffset;
			int yield;
	};
	
#endif