#include "omath.h"





Vector2 OMath::FindLargestXCorner(ConvexShape shape)
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
	return;
}

Vector2 OMath::FindSmallestXCorner(ConvexShape shape)
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
	return;
}

Vector2 OMath::FindLargestYCorner(ConvexShape shape)
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
	return;
}
Vector2 OMath::FindSmallestYCorner(ConvexShape shape)
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
	return;
}



