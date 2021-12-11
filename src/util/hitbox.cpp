#include "hitbox.h"
#include <SFML/Graphics.hpp>

void HitBox::setPosition(sf::Vector2f position)
{
	HitBox::hitBox.setPosition(position);
}

void HitBox::setRotation(double rotation)
{
	HitBox::hitBox.setRotation(rotation);
}

bool HitBox::checkForCollision(HitBox targetHitBox)
{
	//Step 1: Calculating hitboxes sides and perpendicular vectors
	sf::Vector2f side1{ HitBox::getAbsolutePoint(0) - HitBox::getAbsolutePoint(1) };
	sf::Vector2f perpendicularSide1{ sf::Vector2f(-side1.y, side1.x) };
		
	sf::Vector2f side2{ HitBox::getAbsolutePoint(0) - HitBox::getAbsolutePoint(3) };
	sf::Vector2f perpendicularSide2{ sf::Vector2f(-side2.y, side2.x) };
	
	sf::Vector2f point1[4]{
		sf::Vector2f(HitBox::getAbsolutePoint(0).x, HitBox::getAbsolutePoint(0).y),
		sf::Vector2f(HitBox::getAbsolutePoint(1).x, HitBox::getAbsolutePoint(1).y),
		sf::Vector2f(HitBox::getAbsolutePoint(2).x, HitBox::getAbsolutePoint(2).y),
		sf::Vector2f(HitBox::getAbsolutePoint(3).x, HitBox::getAbsolutePoint(3).y)
	};
	
	sf::Vector2f point2[4]{
		sf::Vector2f(targetHitBox.getAbsolutePoint(0).x, targetHitBox.getAbsolutePoint(0).y),
		sf::Vector2f(targetHitBox.getAbsolutePoint(1).x, targetHitBox.getAbsolutePoint(1).y),
		sf::Vector2f(targetHitBox.getAbsolutePoint(2).x, targetHitBox.getAbsolutePoint(2).y),
		sf::Vector2f(targetHitBox.getAbsolutePoint(3).x, targetHitBox.getAbsolutePoint(3).y)
	};
		
	//Step 2: Calculating dot product of all vertices
	//A.B = AxBx + AyBy
	double dota_1[4]{		
		point1[0].x * perpendicularSide1.x + point1[0].y * perpendicularSide1.y,
		point1[1].x * perpendicularSide1.x + point1[1].y * perpendicularSide1.y,
		point1[2].x * perpendicularSide1.x + point1[2].y * perpendicularSide1.y,
		point1[3].x * perpendicularSide1.x + point1[3].y * perpendicularSide1.y
	};
		
	double dotb_1[4]{
		point2[0].x * perpendicularSide1.x + point2[0].y * perpendicularSide1.y,
		point2[1].x * perpendicularSide1.x + point2[1].y * perpendicularSide1.y,
		point2[2].x * perpendicularSide1.x + point2[2].y * perpendicularSide1.y,
		point2[3].x * perpendicularSide1.x + point2[3].y * perpendicularSide1.y
	};
		
	double dota_2[4]{
		point1[0].x * perpendicularSide2.x + point1[0].y * perpendicularSide2.y,
		point1[1].x * perpendicularSide2.x + point1[1].y * perpendicularSide2.y,
		point1[2].x * perpendicularSide2.x + point1[2].y * perpendicularSide2.y,
		point1[3].x * perpendicularSide2.x + point1[3].y * perpendicularSide2.y
	};
		
	double dotb_2[4]{
		point2[0].x * perpendicularSide2.x + point2[0].y * perpendicularSide2.y,
		point2[1].x * perpendicularSide2.x + point2[1].y * perpendicularSide2.y,
		point2[2].x * perpendicularSide2.x + point2[2].y * perpendicularSide2.y,
		point2[3].x * perpendicularSide2.x + point2[3].y * perpendicularSide2.y
	};
		
	//Step 3: Checking for intersections
	/*
	 * amin < bmax AND amin > bmin
	 *		 OR
​ 	 * bmin < amax AND bmin > amin
	 */
	double amin{ dota_1[0] };
	double amax{ dota_1[0] };
	double bmin{ dotb_1[0] };
	double bmax{ dotb_1[0] };
		
	for(int iii{ 1 }; iii < 4; ++iii)
	{
		if(dota_1[iii] < amin)	amin = dota_1[iii];
		if(dota_1[iii] > amax)	amax = dota_1[iii];
		if(dotb_1[iii] < bmin)	bmin = dotb_1[iii];
		if(dotb_1[iii] > bmax)	bmax = dotb_1[iii];
	}
		
	bool collisionOnAxis1{ (amin < bmax && amin > bmin) 
						|| (bmin < amax && bmin > amin) 
						|| (amin > bmin && amax < bmax)
						|| (amin < bmin && amax > bmax)};
		
	amin = dota_2[0];
	amax = dota_2[0];
	bmin = dotb_2[0];
	bmax = dotb_2[0];
		
	for(int iii{ 1 }; iii < 4; ++iii)
	{
		if(dota_2[iii] < amin)	amin = dota_2[iii];
		if(dota_2[iii] > amax)	amax = dota_2[iii];
		if(dotb_2[iii] < bmin)	bmin = dotb_2[iii];
		if(dotb_2[iii] > bmax)	bmax = dotb_2[iii];
	}
		
	bool collisionOnAxis2{ (amin < bmax && amin > bmin) 
						|| (bmin < amax && bmin > amin) 
						|| (amin > bmin && amax < bmax)
						|| (amin < bmin && amax > bmax)};
	
	return (collisionOnAxis1 && collisionOnAxis2);
}

/*bool HitBox::checkForCollision(HitBox targetHitBox, sf::Vector2f& separatingVector)
{
	//Step 1: Calculating hitboxes sides and perpendicular vectors
	sf::Vector2f side1{ HitBox::getAbsolutePoint(0) - HitBox::getAbsolutePoint(1) };
	sf::Vector2f perpendicularSide1{ sf::Vector2f(-side1.y, side1.x) };
		
	sf::Vector2f side2{ HitBox::getAbsolutePoint(0) - HitBox::getAbsolutePoint(3) };
	sf::Vector2f perpendicularSide2{ sf::Vector2f(-side2.y, side2.x) };
	
	sf::Vector2f point1[4]{
		sf::Vector2f(HitBox::getAbsolutePoint(0).x, HitBox::getAbsolutePoint(0).y),
		sf::Vector2f(HitBox::getAbsolutePoint(1).x, HitBox::getAbsolutePoint(1).y),
		sf::Vector2f(HitBox::getAbsolutePoint(2).x, HitBox::getAbsolutePoint(2).y),
		sf::Vector2f(HitBox::getAbsolutePoint(3).x, HitBox::getAbsolutePoint(3).y)
	};
	
	sf::Vector2f point2[4]{
		sf::Vector2f(targetHitBox.getAbsolutePoint(0).x, targetHitBox.getAbsolutePoint(0).y),
		sf::Vector2f(targetHitBox.getAbsolutePoint(1).x, targetHitBox.getAbsolutePoint(1).y),
		sf::Vector2f(targetHitBox.getAbsolutePoint(2).x, targetHitBox.getAbsolutePoint(2).y),
		sf::Vector2f(targetHitBox.getAbsolutePoint(3).x, targetHitBox.getAbsolutePoint(3).y)
	};
		
	//Step 2: Calculating dot product of all vertices
	//A.B = AxBx + AyBy
	double dota_1[4]{		
		point1[0].x * perpendicularSide1.x + point1[0].y * perpendicularSide1.y,
		point1[1].x * perpendicularSide1.x + point1[1].y * perpendicularSide1.y,
		point1[2].x * perpendicularSide1.x + point1[2].y * perpendicularSide1.y,
		point1[3].x * perpendicularSide1.x + point1[3].y * perpendicularSide1.y
	};
		
	double dotb_1[4]{
		point2[0].x * perpendicularSide1.x + point2[0].y * perpendicularSide1.y,
		point2[1].x * perpendicularSide1.x + point2[1].y * perpendicularSide1.y,
		point2[2].x * perpendicularSide1.x + point2[2].y * perpendicularSide1.y,
		point2[3].x * perpendicularSide1.x + point2[3].y * perpendicularSide1.y
	};
		
	double dota_2[4]{
		point1[0].x * perpendicularSide2.x + point1[0].y * perpendicularSide2.y,
		point1[1].x * perpendicularSide2.x + point1[1].y * perpendicularSide2.y,
		point1[2].x * perpendicularSide2.x + point1[2].y * perpendicularSide2.y,
		point1[3].x * perpendicularSide2.x + point1[3].y * perpendicularSide2.y
	};
		
	double dotb_2[4]{
		point2[0].x * perpendicularSide2.x + point2[0].y * perpendicularSide2.y,
		point2[1].x * perpendicularSide2.x + point2[1].y * perpendicularSide2.y,
		point2[2].x * perpendicularSide2.x + point2[2].y * perpendicularSide2.y,
		point2[3].x * perpendicularSide2.x + point2[3].y * perpendicularSide2.y
	};
		
	//Step 3: Checking for intersections
	/*
	 * amin < bmax AND amin > bmin
	 *		 OR
​ 	 * bmin < amax AND bmin > amin
	 */
	/*double amin{ dota_1[0] };
	double amax{ dota_1[0] };
	double bmin{ dotb_1[0] };
	double bmax{ dotb_1[0] };
		
	for(int iii{ 1 }; iii < 4; ++iii)
	{
		if(dota_1[iii] < amin)	amin = dota_1[iii];
		if(dota_1[iii] > amax)	amax = dota_1[iii];
		if(dotb_1[iii] < bmin)	bmin = dotb_1[iii];
		if(dotb_1[iii] > bmax)	bmax = dotb_1[iii];
	}
		
	bool collisionOnAxis1{ (amin < bmax && amin > bmin) 
						|| (bmin < amax && bmin > amin) 
						|| (amin > bmin && amax < bmax)
						|| (amin < bmin && amax > bmax)};
						
	if(collisionOnAxis1)
	{
		separatingVector.x = amax - bmin;
	}
	else
	{
		separatingVector.x = 0.0f;
	}
		
	amin = dota_2[0];
	amax = dota_2[0];
	bmin = dotb_2[0];
	bmax = dotb_2[0];
		
	for(int iii{ 1 }; iii < 4; ++iii)
	{
		if(dota_2[iii] < amin)	amin = dota_2[iii];
		if(dota_2[iii] > amax)	amax = dota_2[iii];
		if(dotb_2[iii] < bmin)	bmin = dotb_2[iii];
		if(dotb_2[iii] > bmax)	bmax = dotb_2[iii];
	}
		
	bool collisionOnAxis2{ (amin < bmax && amin > bmin) 
						|| (bmin < amax && bmin > amin) 
						|| (amin > bmin && amax < bmax)
						|| (amin < bmin && amax > bmax)};
						
	if(collisionOnAxis1)
	{
		separatingVector.y = amax - bmin;
	}
	if(collisionOnAxis2)
	{
		separatingVector.x = amax - bmin;
	}
	
	if(!(collisionOnAxis1 && collisionOnAxis2))
	{
		separatingVector.x = 0.0f;
		separatingVector.y = 0.0f;
	}
	
	return (collisionOnAxis1 && collisionOnAxis2);
}*/

bool HitBox::isClicked(sf::Vector2i clickPosition)
{
	//Calculating linear equations out of hitbox sides
	double a[4] {
		(getAbsolutePoint(1).y - getAbsolutePoint(0).y) / (getAbsolutePoint(1).x - getAbsolutePoint(0).x),
		(getAbsolutePoint(2).y - getAbsolutePoint(1).y) / (getAbsolutePoint(2).x - getAbsolutePoint(1).x),
		(getAbsolutePoint(3).y - getAbsolutePoint(2).y) / (getAbsolutePoint(3).x - getAbsolutePoint(2).x),
		(getAbsolutePoint(3).y - getAbsolutePoint(0).y) / (getAbsolutePoint(3).x - getAbsolutePoint(0).x)
	};
	
	double b[4] {
		getAbsolutePoint(0).y - a[0] * getAbsolutePoint(0).x,
		getAbsolutePoint(1).y - a[1] * getAbsolutePoint(1).x,
		getAbsolutePoint(2).y - a[2] * getAbsolutePoint(2).x,
		getAbsolutePoint(0).y - a[3] * getAbsolutePoint(0).x
	};
	
	//Since hitbox is always a convex rectangle, ray from click point to infinity will cross only one side
	int intersections{ 0 };
		
	//Checking if ray crossed any side
	//side 1:
	if((getAbsolutePoint(0).x < (clickPosition.y - b[0]) / a[0]
	 && getAbsolutePoint(1).x > (clickPosition.y - b[0]) / a[0]
	 && (clickPosition.y - b[0]) / a[0] > clickPosition.x)
	|| (getAbsolutePoint(0).x > (clickPosition.y - b[0]) / a[0]
	 && getAbsolutePoint(1).x < (clickPosition.y - b[0]) / a[0]
	 && (clickPosition.y - b[0]) / a[0] > clickPosition.x)) ++intersections;
	 
	if(getAbsolutePoint(0).x == getAbsolutePoint(1).x
	&& clickPosition.x < getAbsolutePoint(0).x	
	&& ((clickPosition.y > getAbsolutePoint(0).y && clickPosition.y < getAbsolutePoint(1).y)
   	 || (clickPosition.y < getAbsolutePoint(0).y && clickPosition.y > getAbsolutePoint(1).y)))
	{
		++intersections;
	}
		  
	//side 2:
	if((getAbsolutePoint(1).x < (clickPosition.y - b[1]) / a[1]
	 && getAbsolutePoint(2).x > (clickPosition.y - b[1]) / a[1]
	 && (clickPosition.y - b[1]) / a[1] > clickPosition.x)
	|| (getAbsolutePoint(1).x > (clickPosition.y - b[1]) / a[1]
	 && getAbsolutePoint(2).x < (clickPosition.y - b[1]) / a[1]
	 && (clickPosition.y - b[1]) / a[1] > clickPosition.x)) ++intersections;
	 
	if(getAbsolutePoint(1).x == getAbsolutePoint(2).x
	&& clickPosition.x < getAbsolutePoint(1).x	
	&& ((clickPosition.y > getAbsolutePoint(1).y && clickPosition.y < getAbsolutePoint(2).y)
   	 || (clickPosition.y < getAbsolutePoint(1).y && clickPosition.y > getAbsolutePoint(2).y)))
	{
		++intersections;
	}
	 
	//side 3:
	if((getAbsolutePoint(2).x < (clickPosition.y - b[2]) / a[2]
	 && getAbsolutePoint(3).x > (clickPosition.y - b[2]) / a[2]
	 && (clickPosition.y - b[2]) / a[2] > clickPosition.x)
	|| (getAbsolutePoint(2).x > (clickPosition.y - b[2]) / a[2]
	 && getAbsolutePoint(3).x < (clickPosition.y - b[2]) / a[2]
	 && (clickPosition.y - b[2]) / a[2] > clickPosition.x)) ++intersections;
	 
	if(getAbsolutePoint(2).x == getAbsolutePoint(3).x
	&& clickPosition.x < getAbsolutePoint(2).x
	&& ((clickPosition.y > getAbsolutePoint(2).y && clickPosition.y < getAbsolutePoint(3).y)
   	 || (clickPosition.y < getAbsolutePoint(2).y && clickPosition.y > getAbsolutePoint(3).y)))
	{
		++intersections;
	}
		  
	//side 4:
	if((getAbsolutePoint(0).x < (clickPosition.y - b[3]) / a[3]
	 && getAbsolutePoint(3).x > (clickPosition.y - b[3]) / a[3]
	 && (clickPosition.y - b[3]) / a[3] > clickPosition.x)
	|| (getAbsolutePoint(0).x > (clickPosition.y - b[3]) / a[3]
	 && getAbsolutePoint(3).x < (clickPosition.y - b[3]) / a[3]
	 && (clickPosition.y - b[3]) / a[3] > clickPosition.x)) ++intersections;
	 
	if(getAbsolutePoint(0).x == getAbsolutePoint(3).x
	&& clickPosition.x < getAbsolutePoint(0).x	
	&& ((clickPosition.y > getAbsolutePoint(0).y && clickPosition.y < getAbsolutePoint(3).y)
   	 || (clickPosition.y < getAbsolutePoint(0).y && clickPosition.y > getAbsolutePoint(3).y)))
	{
		++intersections;
	}
	
	//If ray crossed only one side, return true
	return intersections == 1;
}