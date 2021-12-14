#include "resourcemanager.h"
#include "animatedsprite.h"
#include <SFML/Graphics.hpp>

void ResourceManager::load()
{
	arial.loadFromFile("resources/fonts/arial.ttf");

	startButtonTexture.loadFromFile("resources/textures/start.png");

	startButton	= AnimatedSprite{ startButtonTexture,
											   				sf::Vector2f(200, 200),
											   				1,
											   				1.0 };
}

sf::Font ResourceManager::arial {  };

//sf::Texture ResourceManager::nothingnessTexture{  };
sf::Texture	ResourceManager::startButtonTexture	 {  };

//AnimatedSprite ResourceManager::nothingness{  };
AnimatedSprite ResourceManager::startButton	 {  };
