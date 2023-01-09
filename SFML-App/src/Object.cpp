#include "Object.h"




class Object
{
	PhysicsObject physbody;
	sf::ConvexShape shape;
	//Corner Count can't be less than 2
	Object(int cornerCount,float size, sf::Vector2f position)
	{
		
		shape.setPointCount(cornerCount);
		/*
		* shape.setPoint(0, sf::Vector2f(0, 0));
		for (int i = 1; i < cornerCount; i++) 
		{
			shape.setPoint(i, sf::Vector2f(size,size));
		}
		*/
	};
	//Update visual location
	void updatePosition() 
	{
		shape.setPosition(physbody.displacement);
	}
};