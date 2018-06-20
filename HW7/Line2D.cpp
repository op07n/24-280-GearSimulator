//#include "stdafx.h"
#include "Line2D.h"
#include <math.h>
#include <algorithm>
using namespace std;

double Line2D::getLength(Point2D startPoint, Point2D endPoint) {
	// returns the distance from one point to the other.
	// just calls other version of function
	return getLength(startPoint.X, startPoint.Y, endPoint.X, endPoint.Y);
}

double Line2D::getLength(double startX, double startY,
	double endX, double endY) {
	// returns the distance from one point to the other.
	// square root of the sum of the squares
	return pow(pow(endX - startX, 2) + pow(endY - startY, 2), 0.5);
}

Point2D *Line2D::getIntersection(Point2D line1A, Point2D line1B, Point2D
	line2A, Point2D line2B) {
	// returns a point at the intersection of the two lines defined by the
	// two end points. Note that the intersection point may lie beyond the 
	// given line segments (i.e., the two line segments may not touch at all, 
	// but their extensions into infinity will surely intersect.If the lines
	// are parallel, the function returns NULL

	double x1 = line1A.X;
	double x2 = line1B.X;
	double y1 = line1A.Y;
	double y2 = line1B.Y;

	double x3 = line2A.X;
	double x4 = line2B.X;
	double y3 = line2A.Y;
	double y4 = line2B.Y;

	double denominator = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4);

	if (abs(denominator) < TOLERANCE) // lines are parallel or coincident
		return NULL;
	else {
		Point2D *newPoint = new Point2D;
		newPoint->X = ((x1 * y2 - y1 * x2)*(x3 - x4)
			- (x1 - x2)*(x3 * y4 - y3 * x4)) / denominator;
		newPoint->Y = ((x1 * y2 - y1 * x2)*(y3 - y4)
			- (y1 - y2)*(x3 * y4 - y3 * x4)) / denominator;

		return newPoint;
	}
}