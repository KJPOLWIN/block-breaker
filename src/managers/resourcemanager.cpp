#include "resourcemanager.h"
#include "animatedsprite.h"
#include <SFML/Graphics.hpp>

void ResourceManager::load()
{
	//font.loadFromFile("resources/fonts/font.ttf");

	//texture.loadFromFile("resources/textures/texture.png");

	// sprite 									 = AnimatedSprite{ texture,
	// 										   											 sf::Vector2f(/*size*/),
	// 										   											 1 /*frame count*/,
	// 										   											 1.0 /*frame duration*/};
}

sf::Font ResourceManager::arial {  };

sf::Texture ResourceManager::nothingnessTexture				 			 {  };
//sf::Texture	ResourceManager::texture			   		 			 {  };

AnimatedSprite ResourceManager::nothingness					 					 {  };
//AnimatedSprite ResourceManager::sprite			   		 			 {  };
