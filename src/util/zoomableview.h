#ifndef ZOOMABLEVIEW_H
#define ZOOMABLEVIEW_H

	#include "constants.h"
	#include <SFML/Graphics.hpp>

	class ZoomableView
	{
		public:
			ZoomableView(double maxZoomLevel, double initialZoomLevel);
			
			void move(sf::Vector2f offset);
			void zoom(short direction);
			void reset();
			
			sf::View& getView()
			{
				return view;
			}
			
		
		private:
			sf::View view{ sf::Vector2f(constant::windowWidth * 0.5, constant::windowHeight * 0.5), 
						   sf::Vector2f(constant::windowWidth, constant::windowHeight) };
			double initialZoomLevel;
			double zoomLevel;
			double maxZoomLevel;
		
	};

#endif