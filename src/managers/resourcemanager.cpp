#include "resourcemanager.h"
#include "animatedsprite.h"
#include <SFML/Graphics.hpp>

void ResourceManager::load()
{
	arial.loadFromFile("resources/fonts/arial.ttf");

	startButtonTexture.loadFromFile("resources/textures/start.png");
	extraBallTexture.loadFromFile("resources/textures/extraball.png");

	startButton	= AnimatedSprite{ startButtonTexture,
											   				sf::Vector2f(200, 200),
											   				1,
											   				1.0 };
	extraBall 	= AnimatedSprite{ extraBallTexture,
											   				sf::Vector2f(100, 100),
											   				1,
											   				1.0 };
}

sf::Font ResourceManager::arial {  };

sf::Texture	ResourceManager::startButtonTexture{  };
sf::Texture	ResourceManager::extraBallTexture	 {  };

AnimatedSprite ResourceManager::startButton{  };
AnimatedSprite ResourceManager::extraBall	 {  };
