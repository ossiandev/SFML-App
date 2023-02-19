#pragma once
#include <cmath>
#include <vector> // std::vector
#include <SFML/Graphics.hpp> // contains include <algorithm>
#include <iostream>

typedef sf::Vector2f Vector2;
typedef sf::ConvexShape ConvexShape;
namespace OMath
{
	

	Vector2 findLargestXSide(ConvexShape shape);
	Vector2 findSmallestXSide(ConvexShape shape);
	Vector2 findLargestYSide(ConvexShape shape);
	Vector2 findSmallestYSide(ConvexShape shape);
	Vector2 findCOF(ConvexShape shape);


};
