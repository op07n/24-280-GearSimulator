/*
Philip Baker
philipba
PS7
*/

#pragma once
#include <fstream>
#include <iostream>
#define TOLERANCE 1e-10  // aka EPSILON

// removed from here since it is not strictly needed 
// and it interferes with GUI libraries. Moved to .cpp
//using namespace std;

struct Point2D {
	double X;
	double Y;
};

class Line2D {
public:
	static double getLength(Point2D startPoint, Point2D endPoint);
	static double getLength(double startX, double startY, double endX, double endY);
	static Point2D *getIntersection(Point2D line1A, Point2D line1B,
		Point2D line2A, Point2D line2B);
};
