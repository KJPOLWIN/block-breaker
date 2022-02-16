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
			static sf::Texture horizontalDamageTexture;
			static sf::Texture flipperTexture;

      //Arrow
      static sf::Texture arrowHeadTexture;
      static sf::Texture arrowBaseTexture;

			//SPRITES
			//	Buttons
			static AnimatedSprite startButton;

			//	Power ups
			static AnimatedSprite extraBall;
			static AnimatedSprite verticalDamage;
			static AnimatedSprite horizontalDamage;
			static AnimatedSprite flipper;

      //Arrow
      static AnimatedSprite arrowHead;
      static AnimatedSprite arrowBase;

		private:
			ResourceManager() {  }
	};

#endif
