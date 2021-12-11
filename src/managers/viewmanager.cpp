#include "viewmanager.h"
#include "zoomableview.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

ZoomableView ViewManager::mainView{ 11, 6 };

sf::View ViewManager::debugGUIView{ sf::Vector2f(constant::windowWidth * 0.5,
																								 constant::windowHeight * 0.5),
										  							sf::Vector2f(constant::windowWidth,
																								 constant::windowHeight) };
sf::View ViewManager::guiView{ sf::Vector2f(constant::windowWidth * 0.5,
																						constant::windowHeight * 0.5),
										  				 sf::Vector2f(constant::windowWidth,
																 						constant::windowHeight) };

short ViewManager::zoomDirection{ 0 };
