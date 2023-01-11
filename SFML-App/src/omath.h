#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

class OMath
{
	typedef sf::Vector2f Vector2;
	typedef sf::ConvexShape shape;

	Vector2 FindLargestXCorner(shape);
	Vector2 FindSmallestXCorner(shape);
	Vector2 FindLargestYCorner(shape);
	Vector2 FindSmallestYCorner(shape);

};
