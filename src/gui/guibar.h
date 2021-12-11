#ifndef GUIBAR_H
#define GUIBAR_H

	#include <SFML/Graphics.hpp>

	class guiBar
	{
		public:
			//Arguments: color of bar, size of bar, initial position
			//and maximum value of observed variable
			guiBar(sf::Color color, sf::Vector2f size,
				   sf::Vector2f position, double maximumValue)
				: bar{ sf::RectangleShape(size) },
				  width{ size.y },
				  currentValue{ maximumValue },
			    maxValue{ maximumValue },
				  pixelPerUnit{ size.x / maximumValue }
			{
				guiBar::bar.setFillColor(color);
				guiBar::bar.setPosition(position);
			}

			//Updating bar lenght
			void update(double newValue);

			//Drawing on screen
			void draw(sf::RenderWindow *currentWindow);
			void recalculatePpU(double sizeX);

			void setPosition(sf::Vector2f position);
			sf::Vector2f getPosition();

			void setMaxValue(double newMaxValue)
			{
				maxValue = newMaxValue;
				pixelPerUnit = bar.getSize().x / maxValue;
			}

		private:
			//Actual bar
			sf::RectangleShape bar;
			//Width of bar
			double width;

			//Current value of observed variable
			double currentValue;
			//Maximum value of observed variable
			double maxValue;

			double pixelPerUnit;
	};

#endif
