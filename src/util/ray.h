#ifndef RAY_H
#define RAY_H

	#include "constants.h"
	#include "hitbox.h"
	#include <cmath>
	#include <SFML/Graphics.hpp>

	class Ray
	{
		public:
			Ray(sf::Vector2f start, double rotation, double lenght)
				: start{ start },
				  end{ start + sf::Vector2f(lenght * cos(rotation * constant::degToRad),
											lenght * sin(rotation * constant::degToRad)) }
			{

			}

			Ray(sf::Vector2f start, sf::Vector2f end)
				: start{ start },
				  end{ end }
			{

			}

			Ray() = default;

			bool detectIntersection(sf::Vector2f start, sf::Vector2f end);
			bool checkIfHit(HitBox& hitBox);

			void setPositionAndRotation(sf::Vector2f newPosition, double newRotation, double lenght);

			double getRotation();

			void draw(sf::RenderWindow* window, sf::Color color);

		private:
			sf::Vector2f start;
			sf::Vector2f end;
	};

#endif
