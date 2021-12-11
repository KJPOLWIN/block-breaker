#include "ray.h"
#include "constants.h"
#include "hitbox.h"
#include <cmath>
#include <algorithm>
#include <SFML/Graphics.hpp>

	#include <iostream>
	


bool Ray::detectIntersection(sf::Vector2f start, sf::Vector2f end)
{
	//If second line is vertical segment
	//start.x and end.x are equal up to 1% of larger value (Knuth's algorithm)
	if(std::abs(start.x - end.x) <= (std::max(std::abs(start.x), std::abs(end.x)) * 0.01 ))
	{
		//If ray is also vertical segment
		if(std::abs(Ray::start.x - Ray::end.x) <= (std::max(std::abs(Ray::start.x), std::abs(Ray::end.x)) * 0.01 ))
		{
			return (((Ray::start.y <= start.y && start.y <= Ray::end.y)
				 || (Ray::end.y <= start.y && start.y <= Ray::start.y)
				 || (Ray::start.y <= end.y && end.y <= Ray::end.y)
				 || (Ray::end.y <= end.y && end.y <= Ray::start.y))
			&& (std::abs(Ray::start.x - start.x) <= (std::max(std::abs(Ray::start.x), std::abs(start.x)) * 0.01 )));
				
		}
		
		//Turning ray into linear equation
		double a1{ (Ray::end.y - Ray::start.y) / (Ray::end.x - Ray::start.x)};
		double b1{ Ray::start.y - a1 * Ray::start.x };
		
		//Calculating intersection point
		double x{ start.x };
		double y{ a1 * x + b1 };
		
		//Checking if intersection point is on the lines
		return (((Ray::start.x <= x && x <= Ray::end.x) || (Ray::end.x <= x && x <= Ray::start.x))
		&& ((start.x <= x && x <= end.x) || (end.x <= x && x <= start.x))
		&& ((Ray::start.y <= y && y <= Ray::end.y) || (Ray::end.y <= y && y <= Ray::start.y))
		&& ((start.y <= y && y <= end.y) || (end.y <= y && y <= start.y)));
	}
	else
	{
		//Turning lines into linear equations
		double a1{ (Ray::end.y - Ray::start.y) / (Ray::end.x - Ray::start.x)};
		double b1{ Ray::start.y - a1 * Ray::start.x };
	
		double a2{ (end.y - start.y) / (end.x - start.x)};
		double b2{ start.y - a2 * start.x };
	
		//Calculating intersection point
		double x{ (b2 - b1) / (a1 - a2) };
		double y{ a1 *  x + b1 };
	
		//Checking if intersection point is on the lines
		return (((Ray::start.x <= x && x <= Ray::end.x) || (Ray::end.x <= x && x <= Ray::start.x))
		&& ((x <= end.x && x >= start.x) || (x >= end.x && x <= start.x))
		&& ((y <= Ray::end.y && y >= Ray::start.y) || (y >= Ray::end.y && y <= Ray::start.y))
		&& ((y <= end.y && y >= start.y) || (y >= end.y && y <= start.y)));
	}
	
	/* std::cout << "Ray: " << Ray::start.x << ", " << Ray::start.y << " -> " << Ray::end.x << ", " << Ray::end.y
	<< " x?x " << start.x << ", " << start.y << " -> " << end.x << ", " << end.y << "\n";
	std::cout << "x: " << start.x << " -?> " << Ray::start.x << " -?> " << end.x << "\n";
	std::cout << "y: " << start.y << " -?> " << Ray::start.y << " -?> " << end.y << "\n"; */
	
	//std::cout << "\n";
}

bool Ray::checkIfHit(HitBox& hitBox)
{
	/* std::cout << "Side 0: " << hitBox.getAbsolutePoint(0).x << ", " << hitBox.getAbsolutePoint(0).y
				 << " - > " << hitBox.getAbsolutePoint(1).x << ", " << hitBox.getAbsolutePoint(1).y << "\n";
	std::cout << "Side 1: " << hitBox.getAbsolutePoint(1).x << ", " << hitBox.getAbsolutePoint(1).y
				 << " - > " << hitBox.getAbsolutePoint(2).x << ", " << hitBox.getAbsolutePoint(2).y << "\n";
	std::cout << "Side 2: " << hitBox.getAbsolutePoint(2).x << ", " << hitBox.getAbsolutePoint(2).y
				 << " - > " << hitBox.getAbsolutePoint(3).x << ", " << hitBox.getAbsolutePoint(3).y << "\n";
	std::cout << "Side 3: " << hitBox.getAbsolutePoint(0).x << ", " << hitBox.getAbsolutePoint(0).y
				 << " - > " << hitBox.getAbsolutePoint(3).x << ", " << hitBox.getAbsolutePoint(3).y << "\n\n"; */
	
	return detectIntersection(hitBox.getAbsolutePoint(0), hitBox.getAbsolutePoint(1))
		|| detectIntersection(hitBox.getAbsolutePoint(1), hitBox.getAbsolutePoint(2))
		|| detectIntersection(hitBox.getAbsolutePoint(2), hitBox.getAbsolutePoint(3))
		|| detectIntersection(hitBox.getAbsolutePoint(0), hitBox.getAbsolutePoint(3));
}

void Ray::setPositionAndRotation(sf::Vector2f newPosition, double newRotation, double lenght)
{
	Ray::start = newPosition;
	Ray::end = newPosition + sf::Vector2f(lenght * cos(newRotation * constant::degToRad), 
									      lenght * sin(newRotation * constant::degToRad));
}

double Ray::getRotation()
{
	//tg-1(y/x)
	double y = Ray::end.y - Ray::start.y;
	double x = Ray::end.x - Ray::start.x;
	
	if(x < 0 && y > 0)
	{
		return atan(y/x) / constant::degToRad + 180.0;
	}
	else if(x > 0 && y > 0)
	{
		return atan(y/x) / constant::degToRad;
	}
	else if(x > 0 && y < 0)
	{
		return atan(y/x) / constant::degToRad + 360.0;
	}
	else if(x < 0 && y < 0)
	{
		return atan(y/x) / constant::degToRad + 180.0;
	}
	else return -1.0;
}

void Ray::draw(sf::RenderWindow* window, sf::Color color)
{
	sf::VertexArray line(sf::Lines, 2);

	line[0].position = start;
	line[1].position = end;

	line[0].color = color;
	line[1].color = color;
	
	window->draw(line);
}