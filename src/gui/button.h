#ifndef BUTTON_H
#define BUTTON_H

	#include "animatedsprite.h"
	#include "guitext.h"
	#include <SFML/Graphics.hpp>
	
	class Button
	{
		public:
			Button(AnimatedSprite sprite, sf::Vector2f size, sf::Font &font, 
				   std::string text, sf::Color color, unsigned int textSize, 
				   sf::Vector2f textPosition)
				: sprite{ sprite },
				  clickbox{ size },
				  text{ guiText(font, text, color, textSize, textPosition) },
				  textOffset{ textPosition }
			{
				
			}
			
			void update(double elapsedTime)
			{
				sprite.update(elapsedTime);
			}
			
			bool isClicked(sf::Vector2i clickPosition);
			
			void draw(sf::RenderWindow *currentWindow);
			
			void changeAnimation(int animationID)
			{
				sprite.setAnimation(animationID, true);
			}
			
			void setPosition(sf::Vector2f position)
			{
				sprite.setPosition(position);
				text.setPosition(position + textOffset);
			}
			sf::Vector2f getPosition()
			{
				return sprite.getPosition();
			}
		
		private:
			AnimatedSprite sprite;
			sf::Vector2f clickbox;
			guiText text;
			sf::Vector2f textOffset;
	};
	
#endif