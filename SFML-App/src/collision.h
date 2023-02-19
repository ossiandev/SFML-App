#pragma once
#include <SFML/Graphics.hpp>
#include "omath.h"
#include "PhysicsObject.h"



class Collision
{
	//code meant to be used within collision
private:
	
	
	//code that is used outside collision
public: 
	void AABBCollision(PhysicsObject object, PhysicsObject otherObject);
	void SATCollision(PhysicsObject object, PhysicsObject otherObject);

};