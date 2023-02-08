#pragma once
#include <cmath>
#include <vector> // std::vector
#include <SFML/Graphics.hpp> // contains include <algorithm>
#include <iostream>

typedef sf::Vector2f Vector2;
typedef sf::ConvexShape ConvexShape;
namespace OMath
{
	

	Vector2 FindLargestXSide(ConvexShape shape);
	Vector2 FindSmallestXSide(ConvexShape shape);
	Vector2 FindLargestYSide(ConvexShape shape);
	Vector2 FindSmallestYSide(ConvexShape shape);


};
