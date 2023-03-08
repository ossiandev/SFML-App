#include "collision.h"

void Collision::AABBCollision(PhysicsObject& object, PhysicsObject& otherObject)
{
	//AABB collision
	if (object.shape.getPosition().x < otherObject.shape.getPosition().x + OMath::findLargestXSide(otherObject.shape).x &&
		otherObject.shape.getPosition().x < object.shape.getPosition().x + OMath::findLargestXSide(object.shape).x &&
		object.shape.getPosition().y < otherObject.shape.getPosition().y + OMath::findLargestYSide(otherObject.shape).y &&
		otherObject.shape.getPosition().y < object.shape.getPosition().y + OMath::findLargestYSide(object.shape).y)
	{
		object.colliding = true;
		otherObject.colliding = true;
	}
	else
	{
		object.colliding = false;
		otherObject.colliding = false;
	}
	


}

void Collision::SATCollision(PhysicsObject& object, PhysicsObject& otherObject)
{

}




