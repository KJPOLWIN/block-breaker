#ifndef CHECKBOX_H
#define CHECKBOX_H

	#include "animatedsprite.h"
	#include "guitext.h"
	#include <SFML/Graphics.hpp>

	class CheckBox
	{
		public:
			CheckBox(AnimatedSprite sprite, sf::Vector2f size, sf::Font &font,
					 std::string text, sf::Color color, unsigned int textSize,
					 sf::Vector2f textPosition, bool& followedValue)
				: sprite{ sprite },
				  clickbox{ size },
				  text{ guiText(font, text, color, textSize, textPosition) },
				  textOffset{ textPosition },
				  state{ &followedValue }
			{
				changeAnimation(followedValue);
			}

			void takeInput(sf::Vector2i clickPosition);
			void update(double elapsedTime);
			void draw(sf::RenderWindow *currentWindow);

			void setPosition(sf::Vector2f position);
			sf::Vector2f getPosition();

		private:
			AnimatedSprite sprite;
			sf::Vector2f clickbox;
			guiText text;
			sf::Vector2f textOffset;
			bool* state;

			void changeAnimation(int animationID);
			bool isClicked(sf::Vector2i clickPosition);
	};

#endif
