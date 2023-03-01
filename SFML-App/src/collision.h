#pragma once
#include <SFML/Graphics.hpp>
#include "omath.h"
#include "PhysicsObject.h"



namespace Collision
{
	//code meant to be used within 
	void AABBCollision(PhysicsObject object, PhysicsObject otherObject);
	void SATCollision(PhysicsObject object, PhysicsObject otherObject);

};