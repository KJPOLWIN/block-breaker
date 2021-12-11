#ifndef GUITEXT_H
#define GUITEXT_H

	#include <string>
	#include <SFML/Graphics.hpp>

	class guiText
	{
		public:
			//Arguments: font which will be used, text which will be displayed,
			//color of text, character size and text position
			guiText(sf::Font &font, std::string text, sf::Color color, 
					unsigned int size, sf::Vector2f position)
				: text{ sf::Text(text, font, size) }
			{
				//Setting all atributes to SFML text object
				guiText::text.setFillColor(color);
				guiText::text.setPosition(position);
			}
			
			guiText()
				: text{  }
			{
				
			}
			
			void update(std::string newString);
			
			//Drawing text on screen
			void draw(sf::RenderWindow *currentWindow);
			
			//Setter/getter for position
			void setPosition(sf::Vector2f position);
			sf::Vector2f getPosition();
			
			void setSize(unsigned int newSize);
			
			void setColor(sf::Color newColor);
			
		private:
			//Text which will be displayed
			sf::Text text;
	};

#endif