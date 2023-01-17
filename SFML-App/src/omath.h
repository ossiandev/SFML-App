#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

typedef sf::Vector2f Vector2;
typedef sf::ConvexShape ConvexShape;
class OMath
{
	

	Vector2 FindLargestXCorner(ConvexShape shape);
	Vector2 FindSmallestXCorner(ConvexShape shape);
	Vector2 FindLargestYCorner(ConvexShape shape);
	Vector2 FindSmallestYCorner(ConvexShape shape);
	float FindCrossSectionalArea(ConvexShape shape);

};
