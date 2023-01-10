#pragma once
#include "PhysicsObject.h"

class Object
{
	PhysicsObject physbody;
	sf::ConvexShape shape;
	Object();
	//Update visual location
	void updatePosition();

};