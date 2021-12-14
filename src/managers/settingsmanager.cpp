#include "settingsmanager.h"
#include "keyboardcontrols.h"
#include <SFML/Graphics.hpp>

bool 	   	 	 SettingsManager::showFPSCounter { true };
bool 		 	 	 SettingsManager::enableVSync	   { true };
int 				 SettingsManager::fpsLimit 			 { 0 };
// KeyboardControls SettingsManager::keyboardControls{ sf::Keyboard::W,
// 																										sf::Keyboard::S,
// 																										sf::Keyboard::D,
// 																										sf::Keyboard::A,
// 																										sf::Keyboard::Escape };
int SettingsManager::zoomingSpeed{ 1 };
