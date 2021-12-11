#ifndef HITBOX_H
#define HITBOX_H

	#include <SFML/Graphics.hpp>

	class HitBox
	{
		public:
			HitBox(sf::Vector2f size)
				: hitBox{ sf::RectangleShape(size) }
			{
				hitBox.setOrigin(size.x / 2, size.y / 2);
			}
			
			HitBox()
				: hitBox{ sf::RectangleShape() }
			{
				
			}
			
			//void updatePosition(sf::Vector2f position, double rotation);
			void setPosition(sf::Vector2f position);
			void setRotation(double rotation);
			bool checkForCollision(HitBox targetHitBox);
			//bool checkForCollision(HitBox targetHitBox, sf::Vector2f& separatingVector);
			bool isClicked(sf::Vector2i clickPosition);
			
			void draw(sf::RenderWindow *currentWindow)
			{
				currentWindow->draw(hitBox);
			}
			
			sf::Vector2f getAbsolutePoint(std::size_t point)
			{
				return hitBox.getTransform().transformPoint(hitBox.getPoint(point));
			}
			
			sf::Vector2f getSize()
			{
				return hitBox.getSize();
			}
			
			sf::Vector2f getPosition()
			{
				return hitBox.getPosition();
			}
			
			double getRotation()
			{
				return hitBox.getRotation();
			}
			
		private:
			sf::Vector2f getPoint(std::size_t point)
			{
				return hitBox.getPoint(point);
			}
		
			sf::RectangleShape hitBox;
	};

#endif