#include "collision.h"

void Collision::AABBCollision(PhysicsObject object, PhysicsObject otherObject)
{
	//AABB collision
	if (object.shape.getPosition().x < otherObject.shape.getPosition().x + OMath::findLargestXSide(otherObject.shape).x &&
		otherObject.shape.getPosition().x < object.shape.getPosition().x + OMath::findLargestXSide(object.shape).x &&
		object.shape.getPosition().y < otherObject.shape.getPosition().y + OMath::findLargestYSide(otherObject.shape).y &&
		otherObject.shape.getPosition().y < object.shape.getPosition().y + OMath::findLargestYSide(object.shape).y)
	{
		//collision detected, send colliding trigger
		object.colliding = true;
		otherObject.colliding = true;
	}
	else
	{
		//No collision so sending nothing
		//send nothing
	}

}
