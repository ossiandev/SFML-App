#include "collision.h"
#include <cmath>

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




/*
	/*
	https://gamedevelopment.tutsplus.com/tutorials/collision-detection-using-the-separating-axis-theorem--gamedev-169

	https://latexeditor.lagrida.com/
	det är dags

A. P=A_{magnitude}*P_{magnitude}*cos(\theta)\\
A.\frac{P}{P_{magnitude}}=A_{magnitude}*cos(\theta)\\
\begin{bmatrix}A_x \\A_y\end{bmatrix}.
\begin{bmatrix}P_x/P_{magnitude} \\P_y/P_{magnitude}\end{bmatrix}=
A_{magnitude}*cos(\theta)

\\\\
\begin{bmatrix}A_x \\A_y\end{bmatrix}.
\begin{bmatrix}B_x \\B_y\end{bmatrix}=
(A_x)(B_x)+(A_y)(B_y)


	*/

	/*
	steps
	step 1 do simple aabb collision on standard axis
	step 2 find p axis through magnitude
	step 3 do aabb collision on p axis
	step 4 send true

	any of them return nothing!
	optional: cry throughout whole ordeal
	

	//step 1
if (!object.shape.getPosition().x < otherObject.shape.getPosition().x + OMath::findLargestXSide(otherObject.shape).x &&
	otherObject.shape.getPosition().x < object.shape.getPosition().x + OMath::findLargestXSide(object.shape).x &&
	object.shape.getPosition().y < otherObject.shape.getPosition().y + OMath::findLargestYSide(otherObject.shape).y &&
	otherObject.shape.getPosition().y < object.shape.getPosition().y + OMath::findLargestYSide(object.shape).y)
{
	object.colliding = false;
	otherObject.colliding = false;
}

//step 2


//suggestion to make code

find closest and farthest dot of shape that are connected to eachother before calculating p axis

float pMagn =
sqrt(
	pow((object.shape.getPoint(3).x - object.shape.getPoint(2).x), 2) +
	pow((object.shape.getPoint(3).y - object.shape.getPoint(2).y), 2));

//step 3

*/