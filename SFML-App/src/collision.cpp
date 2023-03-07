#include "collision.h"

void Collision::AABBCollision(PhysicsObject object, PhysicsObject otherObject)
{
	//AABB collision
	if (true)
	{
		//collision detected, send colliding trigger

		/*
		I'd like to redo this part.

		I want to make a void within PhysicsObject.h where it calulates how much it should
		
		*/
		object.colliding = true;
		otherObject.colliding = true;
		//object.shape.setFillColor(sf::Color(255, 255, 0);
	
	

		//returns colliding bool as 204
		
	}
	else
	{
		//No collision so sending nothing
		//send nothing

	}

}
/*
object.shape.getPosition().x < otherObject.shape.getPosition().x + OMath::findLargestXSide(otherObject.shape).x &&
		otherObject.shape.getPosition().x < object.shape.getPosition().x + OMath::findLargestXSide(object.shape).x &&
		object.shape.getPosition().y < otherObject.shape.getPosition().y + OMath::findLargestYSide(otherObject.shape).y &&
		otherObject.shape.getPosition().y < object.shape.getPosition().y + OMath::findLargestYSide(object.shape).y
		*/


