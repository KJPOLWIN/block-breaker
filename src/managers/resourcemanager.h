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
			//	Buttons
			static sf::Texture startButtonTexture;

			//	Power ups
			static sf::Texture extraBallTexture;
			static sf::Texture verticalDamageTexture;

			//SPRITES
			//	Buttons
			static AnimatedSprite startButton;

			//	Power ups
			static AnimatedSprite extraBall;
			static AnimatedSprite verticalDamage;

		private:
			ResourceManager() {  }
	};

#endif
