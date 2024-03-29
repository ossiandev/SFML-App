#include "omath.h"





Vector2 OMath::findLargestXSide(ConvexShape shape)
{
	// To store all the available .x coordinates
	std::vector<float> points;
	for (int i = 0; i < shape.getPointCount(); i++) 
	{
		// Add all the .x coordinate to a vector
		points.push_back(shape.getPoint(i).x);
	}
	// std::sort with the reverse iterators to sort points with LARGEST number coming first.
	std::sort(points.rbegin(), points.rend());
	for (int i = 0; i < shape.getPointCount(); i++) 
	{
		// Search through the points again for the matching .x coordinate
		if (points[0] == shape.getPoint(i).x) {
			return shape.getPoint(i);
		}
	}
	//should never reach here
	return sf::Vector2f(0, 0);
}

Vector2 OMath::findSmallestXSide(ConvexShape shape)
{
	
	// To store all the available .x coordinates
	std::vector<float> points;
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		// Add all the .x coordinate to a vector
		points.push_back(shape.getPoint(i).x);
	}
	// std::sort with the reverse iterators to sort points with SMALLEST number coming first.
	std::sort(points.begin(), points.end());
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		// Search through the points again for the matching .x coordinate
		if (points[0] == shape.getPoint(i).x) {
			return shape.getPoint(i);
		}
	}
	std::cout << "build is failing.";
	return sf::Vector2f(0,0);
}

Vector2 OMath::findLargestYSide(ConvexShape shape)
{
	// To store all the available .y coordinates
	std::vector<float> points;
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		// Add all the .y coordinate to a vector
		points.push_back(shape.getPoint(i).y);
	}
	// std::sort with the reverse iterators to sort points with LARGEST number coming first.
	std::sort(points.rbegin(), points.rend());
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		// Search through the points again for the matching .y coordinate
		if (points[0] == shape.getPoint(i).y) {
			return shape.getPoint(i);
		}
	}
	std::cout << "build is failing.";
	return sf::Vector2f(0, 0);
}
Vector2 OMath::findSmallestYSide(ConvexShape shape)
{
	// To store all the available .y coordinates
	std::vector<float> points;
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		// Add all the .y coordinate to a vector
		points.push_back(shape.getPoint(i).y);
	}
	// std::sort with the reverse iterators to sort points with SMALLEST number coming first.
	std::sort(points.begin(), points.end());
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		// Search through the points again for the matching .y coordinate
		if (points[0] == shape.getPoint(i).y) {
			return shape.getPoint(i);
		}
	}
	std::cout << "build is failing.";
	return sf::Vector2f(0, 0);
}

Vector2 OMath::shapeCenter(ConvexShape shape)
{

	float mX = 0;
	float mY = 0;
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		//Sum up all the point x:es and y:s
		mX += shape.getPoint(i).x;
		mY += shape.getPoint(i).y;

	}
	mX /= shape.getPointCount();
	mY /= shape.getPointCount();

	return Vector2(mX, mY);
}

Vector2 OMath::normalize(ConvexShape shape)
{
	//this returns a normal vector which will become an axis for SAT calculations
	
	//If we define dx = x2 - x1 and dy = y2 - y1, then the normals are(-dy, dx) and (dy, -dx).


	return;
}



