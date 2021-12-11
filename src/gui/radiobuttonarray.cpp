#include "radiobuttonarray.h"
#include "radiobutton.h"
#include <SFML/Graphics.hpp>
#include <vector>

void RadioButtonArray::addRadioButton(RadioButton newRadioButton, sf::Vector2f position)
{
	buttons.push_back(newRadioButton);
	buttons.back().setPosition(position);
}

void RadioButtonArray::setActive(int buttonID)
{
	buttons.at(buttonID).changeAnimation(1);
}

void RadioButtonArray::clear()
{
	buttons.clear();
}

bool RadioButtonArray::takeInput(sf::Vector2i clickPosition)
{
	bool wasClicked{ false };
	
	for(std::size_t iii{ 0 }; iii < buttons.size(); ++iii)
	{
		if(buttons.at(iii).isClicked(clickPosition) && followedValue != nullptr)
		{
			wasClicked = true;
			
			*followedValue = buttons.at(iii).getYield();
			buttons.at(iii).changeAnimation(1);
			
			for(std::size_t jjj{ 0 }; jjj < buttons.size(); ++jjj)
			{
				if(iii == jjj) continue;
				
				buttons.at(jjj).changeAnimation(0);
			}
			
			break;
		}
	}
	
	return wasClicked;
}

void RadioButtonArray::update(double elapsedTime)
{
	for( auto& button : buttons )
	{
		button.update(elapsedTime);
	}
}

void RadioButtonArray::draw(sf::RenderWindow* window)
{
	for( auto& button : buttons )
	{
		button.draw(window);
	}
}

void RadioButtonArray::setFollowedValue(int* newFollowedValue)
{
	followedValue = newFollowedValue;
}