#include "zoomableview.h"
#include "settingsmanager.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

ZoomableView::ZoomableView(double maxZoomLevel, double initialZoomLevel)
	: initialZoomLevel{ initialZoomLevel },
	  zoomLevel{ initialZoomLevel },
	  maxZoomLevel{ maxZoomLevel }
{
	
}

void ZoomableView::move(sf::Vector2f offset)
{
	view.move(sf::Vector2f(offset.x * zoomLevel, offset.y * zoomLevel));
}

void ZoomableView::zoom(short direction)
{
	if(direction == 1 && zoomLevel + SettingsManager::zoomingSpeed <= maxZoomLevel)
	{
		view.zoom(SettingsManager::zoomingSpeed);
		zoomLevel += SettingsManager::zoomingSpeed;
	}
	else if(direction == -1 && zoomLevel - SettingsManager::zoomingSpeed >= 1)
	{
		view.zoom(1 / SettingsManager::zoomingSpeed);
		zoomLevel -= SettingsManager::zoomingSpeed;
	}
}

void ZoomableView::reset()
{
	view.setCenter(constant::windowWidth * 0.5, constant::windowHeight * 0.5);
	view.setSize(constant::windowWidth, constant::windowHeight);
	zoomLevel = initialZoomLevel;
}