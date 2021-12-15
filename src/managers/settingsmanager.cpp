#include "settingsmanager.h"
#include "keyboardcontrols.h"
#include <SFML/Graphics.hpp>

bool 	   	 	 SettingsManager::showFPSCounter { true };
bool 		 	 	 SettingsManager::enableVSync	   { false };
int 				 SettingsManager::fpsLimit 			 { 144 };
// KeyboardControls SettingsManager::keyboardControls{ sf::Keyboard::W,
// 																										sf::Keyboard::S,
// 																										sf::Keyboard::D,
// 																										sf::Keyboard::A,
// 																										sf::Keyboard::Escape };
int SettingsManager::zoomingSpeed{ 1 };
