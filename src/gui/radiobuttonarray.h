#ifndef RADIOBUTTONARRAY_H
#define RADIOBUTTONARRAY_H

	#include "radiobutton.h"
	#include <SFML/Graphics.hpp>
	#include <vector>

	class RadioButtonArray
	{
		public:
			RadioButtonArray(int& followedValue)
				: buttons{ std::vector<RadioButton>() },
				  followedValue{ &followedValue }
			{
				
			}
			
			RadioButtonArray()
				: buttons{ std::vector<RadioButton>() },
				  followedValue{ nullptr }
			{
				
			}
			
			void addRadioButton(RadioButton newRadioButton, sf::Vector2f position);
			void setActive(int buttonID);
			void clear();
			
			//Return true if any button was clicked 
			//and sets followed value to clicked button's yield
			bool takeInput(sf::Vector2i clickPosition);	
			void update(double elapsedTime);
			void draw(sf::RenderWindow* window);
			
			void setFollowedValue(int* newFollowedValue);
		
		private:
			std::vector<RadioButton> buttons;
			int* followedValue;
		
	};

#endif