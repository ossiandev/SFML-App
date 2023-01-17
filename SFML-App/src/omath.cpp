#include "omath.h"





Vector2 OMath::FindLargestXCorner(ConvexShape shape)
{
	for (int i = 0; i < shape.getPointCount(); i++) 
	{
		shape.getPoint(i).x;
	}
	return Vector2();
}

Vector2 OMath::FindSmallestXCorner(ConvexShape shape)
{
	for (int i = 0; i < shape.getPointCount(); i++)
	{

	}
	return Vector2();
}

Vector2 OMath::FindLargestYCorner(ConvexShape shape)
{
	for (int i = 0; i < shape.getPointCount(); i++)
	{

	}
	return Vector2();
}

float OMath::FindCrossSectionalArea(ConvexShape shape)
{
	return 0.0f;
}

Vector2 OMath::FindSmallestYCorner(ConvexShape shape)
{
	return Vector2();
}
