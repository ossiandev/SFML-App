#pragma once
#include <SFML/Graphics.hpp>
#include "omath.h"
#include "PhysicsObject.h"



class Collision
{
public:
	//code meant to be used within 
	void AABBCollision(PhysicsObject& object, PhysicsObject& otherObject);
	void SATCollision(PhysicsObject& object, PhysicsObject& otherObject);

};