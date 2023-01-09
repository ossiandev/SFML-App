#pragma once
#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>

class Object
{
	PhysicsObject physbody;
	sf::ConvexShape shape;
	Object();
	//Update visual location
	void updatePosition();

};