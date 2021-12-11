#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H
	
	#include "zoomableview.h"
	#include <SFML/Graphics.hpp>
	
	class ViewManager
	{
		public:
			static ZoomableView mainView;
			static sf::View debugGUIView;
			static sf::View guiView;
			static short zoomDirection;
		
		private:
			ViewManager() {  };
		
	};

#endif