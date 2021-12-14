#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

	#include "animatedsprite.h"
	#include <SFML/Graphics.hpp>

	class ResourceManager
	{
		public:
			static void load();

			//FONTS
			static sf::Font arial;

			//TEXTURES
			//	Empty texture
			//static sf::Texture nothingnessTexture;

			//	Buttons
			static sf::Texture startButtonTexture;

			//	GUI

			//	Backgrounds


			//SPRITES
			//	Empty sprite
			//static AnimatedSprite nothingness;

			//	Buttons
			static AnimatedSprite startButton;

			//	GUI

			//	Backgrounds

		private:
			ResourceManager() {  }
	};

#endif
