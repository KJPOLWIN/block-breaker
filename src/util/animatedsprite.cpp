#include "animatedsprite.h"

#include <SFML/Graphics.hpp>


void AnimatedSprite::setAnimation(int animationNumber, bool isItEndless)
{
	currentAnimationFrame.y = animationNumber;
	
	if(isItEndless)
		status = AnimationStatus::endless;
	else
		status = AnimationStatus::in_progress;
}

void AnimatedSprite::update(double elapsedTime)
{
	currentTime += elapsedTime;
	
	//Switching frames
	if(currentTime >= switchTime 
	   && status != AnimationStatus::finished)
	{
		++currentAnimationFrame.x;
		
		currentTime -= switchTime;
	
		if(currentAnimationFrame.x > frameCount - 1)
		{
			if(status == AnimationStatus::endless)
			{
				currentAnimationFrame.x = 0;
			}
			else
			{
				--currentAnimationFrame.x;
				status = AnimationStatus::finished;
			}
		}
	}
	
	sprite.setTextureRect(sf::IntRect(currentAnimationFrame.x * spriteSize.x, 
									  currentAnimationFrame.y * spriteSize.y, 
									  spriteSize.x, 
									  spriteSize.y));
}

void AnimatedSprite::draw(sf::RenderWindow *currentWindow)
{
	currentWindow->draw(sprite);
}

void AnimatedSprite::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

sf::Vector2f AnimatedSprite::getPosition()
{
	return sprite.getPosition();
}
			
void AnimatedSprite::setRotation(double rotation)
{
	sprite.setRotation(rotation);
}

double AnimatedSprite::getRotation()
{
	return sprite.getRotation();
}

sf::Vector2f AnimatedSprite::getSize()
{
	return spriteSize;
}