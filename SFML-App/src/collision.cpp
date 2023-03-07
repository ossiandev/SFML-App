#include "collision.h"

void Collision::AABBCollision(PhysicsObject& object, PhysicsObject& otherObject)
{
	//AABB collision

		//collision detected, send colliding trigger

		/*
		I'd like to redo this part.

		I want to make a void within PhysicsObject.h where it calulates how much it should
		
		*/
		object.updateBool();
		otherObject.updateBool();
		//object.shape.setFillColor(sf::Color(255, 255, 0);
	
	

		//returns colliding bool as 204


}
/*
object.shape.getPosition().x < otherObject.shape.getPosition().x + OMath::findLargestXSide(otherObject.shape).x &&
		otherObject.shape.getPosition().x < object.shape.getPosition().x + OMath::findLargestXSide(object.shape).x &&
		object.shape.getPosition().y < otherObject.shape.getPosition().y + OMath::findLargestYSide(otherObject.shape).y &&
		otherObject.shape.getPosition().y < object.shape.getPosition().y + OMath::findLargestYSide(object.shape).y
		*/


