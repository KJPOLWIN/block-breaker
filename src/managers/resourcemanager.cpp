#include "resourcemanager.h"
#include "animatedsprite.h"
#include <SFML/Graphics.hpp>

void ResourceManager::load()
{
	arial.loadFromFile("resources/fonts/arial.ttf");

	startButtonTexture.loadFromFile("resources/textures/start.png");
	extraBallTexture.loadFromFile("resources/textures/extraball.png");
	verticalDamageTexture.loadFromFile("resources/textures/verticaldamage.png");
	horizontalDamageTexture.loadFromFile("resources/textures/horizontaldamage.png");
	flipperTexture.loadFromFile("resources/textures/flipper.png");
  arrowHeadTexture.loadFromFile("resources/textures/arrowhead.png");
  arrowBaseTexture.loadFromFile("resources/textures/arrowbase.png");

	startButton	= AnimatedSprite{ startButtonTexture,
											   				sf::Vector2f(200, 200),
											   				1,
											   				1.0 };
	extraBall 	= AnimatedSprite{ extraBallTexture,
											   				sf::Vector2f(100, 100),
											   				1,
											   				1.0 };
	verticalDamage 	= AnimatedSprite{ verticalDamageTexture,
											   				sf::Vector2f(100, 100),
											   				1,
											   				1.0 };
	horizontalDamage 	= AnimatedSprite{ horizontalDamageTexture,
											   				sf::Vector2f(100, 100),
											   				1,
											   				1.0 };
	flipper 	= AnimatedSprite{ flipperTexture,
											   				sf::Vector2f(100, 100),
											   				1,
											   				1.0 };
  arrowHead = AnimatedSprite{ arrowHeadTexture,
											   			sf::Vector2f(13, 25),
											   			1,
											   			1.0 };
  arrowBase = AnimatedSprite{ arrowBaseTexture,
											   			sf::Vector2f(50, 15),
											   			1,
											   			1.0 };
}

sf::Font ResourceManager::arial {  };

sf::Texture	ResourceManager::startButtonTexture      {  };
sf::Texture	ResourceManager::extraBallTexture	       {  };
sf::Texture	ResourceManager::verticalDamageTexture   {  };
sf::Texture	ResourceManager::horizontalDamageTexture {  };
sf::Texture	ResourceManager::flipperTexture          {  };
sf::Texture ResourceManager::arrowHeadTexture        {  };
sf::Texture ResourceManager::arrowBaseTexture        {  };

AnimatedSprite ResourceManager::startButton      {  };
AnimatedSprite ResourceManager::extraBall        {  };
AnimatedSprite ResourceManager::verticalDamage   {  };
AnimatedSprite ResourceManager::horizontalDamage {  };
AnimatedSprite ResourceManager::flipper          {  };
AnimatedSprite ResourceManager::arrowHead        {  };
AnimatedSprite ResourceManager::arrowBase        {  };
