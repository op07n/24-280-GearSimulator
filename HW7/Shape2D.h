/*
Philip Baker
philipba
PS7
*/
#pragma once
#include <fstream>
#include <iostream>
#include "Line2D.h"

// removed from here since it is not strictly needed 
// and it interferes with GUI libraries. Moved to .cpp
//using namespace std;  

// this namespace is needed for GUI to work
using namespace System::Drawing;

struct coordNode {
	Point2D thePoint;
	coordNode *next;
};

class Shape2D
{

private:
	coordNode * head;
	coordNode *tail;
	double minX, minY, maxX, maxY; // bounding box

	void resetMinMax(); // resets bounding box

public:
	Shape2D();
	Shape2D(std::ifstream &input);
	bool addPoint(Point2D newPoint, int index);
	bool addPoint(double newX, double newY, int index);
	bool removePoint(int index);
	void removeAllPoints();
	void loadPath(Drawing2D::GraphicsPath ^ aPath, float angle);
	double perimeter();
	bool isContained(Point2D testPoint, bool isInclusive);
	bool isContained(double testX, double testY, bool isInclusive);
	friend std::ostream & operator << (std::ostream& os, const Shape2D &aShape);

	// additional function for viewing shape in GUI
	void paint(Graphics ^g, Pen ^aPen, float adj = 1000., bool closeShape = true);

	void loadPath(Drawing2D::GraphicsPath ^aPath);
	~Shape2D();
};

