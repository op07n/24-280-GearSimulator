//#include "stdafx.h"
#include "Shape2D.h"
#include <algorithm>
using namespace std;

Shape2D::Shape2D() {
	// default constructor for the class. Initializes member variables only
	head = NULL;
	tail = NULL;

	// note: bounding box variables are not initialized because no value is
	//       appropriate.
}

Shape2D::Shape2D(ifstream &input) {
	// additional constructor for the class.Takes a pre - created ifstream and 
	// uses it to read coordinate information for the shape.Note that the 
	// method’s parameter cannot be a string filename because the file may 
	// already be in the process of being read.The constructor instantiates 
	// constituent objects and data structures

	double currX, currY;  // used to read from file
	coordNode *currNode;  // 
	head = NULL;
	tail = NULL;

	while (!input.eof()) {
		// get values from file
		input >> currX >> currY;

		// create and initialize new node
		currNode = new coordNode;
		currNode->thePoint.X = currX;
		currNode->thePoint.Y = currY;
		currNode->next = NULL;

		// insert new node into list

		if (head == NULL) {
			// this is the first node, so initialize head and bounding box
			head = currNode;
			minX = maxX = currX;
			minY = maxY = currY;
		}
		else {
			// add at tail and update bounding box as needed
			tail->next = currNode;
			minX = min(minX, currX);  // can also code: minX = ((minX < currX) ? minX : currX);
			maxX = max(maxX, currX);
			minY = min(minY, currY);
			maxY = max(maxY, currY);
		}
		tail = currNode; // since node added at the tail

	}
}

bool Shape2D::addPoint(Point2D newPoint, int index) {
	// see other version of function
	return addPoint(newPoint.X, newPoint.Y, index);
}

bool Shape2D::addPoint(double newX, double newY, int index) {
	// adds a coordinate point such that the new point becomes the index-th 
	// point . For example, an index value of 3 will insert a point between
	// the existing 2nd and 3rd points such that the new point becomes the 
	// new 3rd point. An index of 1will insert the new point at the start of 
	// the shape and an index greater than the number of points will insert 
	// the new point as the last point. Function returns false only if the 
	// new point cannot be added for any reason.

	int currIndex = 1;
	coordNode *currNode = head;
	coordNode *newNode;
	if (index <= 0)
		return false;
	else {
		// prepare node for addition
		newNode = new coordNode;
		newNode->thePoint.X = newX;
		newNode->thePoint.Y = newY;

		if (index == 1) { // add at head of list
			newNode->next = head;
			head = newNode;
			if (tail == NULL)   // corrects error when adding first point
				tail = newNode;
		}
		else {
			// advance to just before requested index
			while (currNode != NULL && currIndex < index - 1) {
				currIndex++;
				currNode = currNode->next;
			}

			if (currNode == NULL || currNode == tail) { // adding at end of list
				currNode = tail;    // make the old tail currNode
				tail = newNode;     // update tail
			}

			// set the pointers to insert in list
			// remmber that currNode holds the node just before insertion point
			newNode->next = currNode->next;
			currNode->next = newNode;
		}

		// update bounding box values
		minX = min(minX, newX);
		maxX = max(maxX, newX);
		minY = min(minY, newY);
		maxY = max(maxY, newY);

		return true;
	}
}

bool Shape2D::removePoint(int index) {
	// removes the indicated point from the shape. Function returns false 
	// only if the point cannot be removed for any reason.

	int currIndex = 1;
	bool foundPoint = false;
	coordNode *currNode = head;
	coordNode *tempNode;

	if (index <= 0 || head == NULL)
		return false;
	else {
		if (index == 1) { // remove at head of list
			currNode = head;
			head = currNode->next;
			delete currNode;
			foundPoint = true;
		}
		else {
			// advance to just before requested index
			while (currNode != NULL && currIndex < index - 1) {
				currIndex++;
				currNode = currNode->next;
			}
			if (currNode->next == NULL) // trying to remove node beyond end of list
				foundPoint = false;
			else {
				tempNode = currNode->next;
				if (tempNode->next == NULL) { // removing tail node
					tail = currNode;
				}

				currNode->next = tempNode->next;
				delete tempNode;  // this frees the memory space
				foundPoint = true;
			}
		}

		// must correct bounding box values before returning true
		if (foundPoint) {
			resetMinMax();
			return true;
		}
		else
			return false;
	}

}

void Shape2D::resetMinMax() {
	// function navigates list in order to determine bounding box
	// only used by removePoint() function since point inserting functions
	// check bounding box at the time of insertion

	coordNode *currNode = head;
	while (currNode != NULL) {
		// update bounding box values
		minX = min(minX, currNode->thePoint.X);
		maxX = max(maxX, currNode->thePoint.X);
		minY = min(minY, currNode->thePoint.Y);
		maxY = max(maxY, currNode->thePoint.Y);
		currNode = currNode->next;
	}
}

double Shape2D::perimeter() {
	// calculates and returns the length of the perimeter of the shape

	coordNode *prevNode = tail;
	coordNode *currNode = head;
	double perim = 0.;

	while (currNode != NULL) {
		perim += Line2D::getLength(prevNode->thePoint, currNode->thePoint);
		prevNode = currNode;
		currNode = currNode->next;
	}
	return perim;
}

bool Shape2D::isContained(Point2D testPoint, bool isInclusive) {
	// simply calls the other version of the function
	return isContained(testPoint.X, testPoint.Y, isInclusive);
}

bool Shape2D::isContained(double testX, double testY, bool isInclusive) {
	// returns true if the coordinates of testPoint is contained inside the 
	// shape.  If isInclusive is true, then a testPoint right on the shape 
	// outline itself is considered inside. Uses ray tracing algorithm.

	// if there are less than 3 points, return false
	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return false;    // <<<< possible exit from function

						 // if testpoint is inside bounding box, check further
	else if (minX <= testX && testX <= maxX && minY <= testY && testY <= maxY) {
		double segX1, segY1, segX2, segY2, crossX;
		coordNode *currNode = head;
		int crossCounter = 0;
		segX1 = tail->thePoint.X;
		segY1 = tail->thePoint.Y;

		while (currNode != NULL) {
			// get far end of current segment
			segX2 = currNode->thePoint.X;
			segY2 = currNode->thePoint.Y;

			// if current segment is "of interest", keep checking
			if (min(segY1, segY2) <= testY && testY <= max(segY1, segY2)) {
				// if segment is horizontal, could get a divide-by-zero error
				if (abs(segY1 - segY2) < TOLERANCE) {
					// if testX is between segX1 and segX2, 
					// test point is on the horizontal segment
					if (min(segX1, segX2) <= testX && testX <= max(segX1, segX2))
						return isInclusive; // <<<< possible exit from function
				}
				else {  // get crossX and continue checking

					crossX = segX1 + (testY - segY1) / (segY2 - segY1) * (segX2 - segX1);

					// if crossX is equal to testX, test point is on the segment
					// simply return user's choice and exit function
					if (abs(crossX - testX) < TOLERANCE)
						return isInclusive;     // <<<< possible exit from function

					else if (crossX > testX) {  // crossX is to right of test point
						if (abs(testY - segY1) < TOLERANCE) { // cross is at 1st vertex
							if (segY2 > testY) // otherpoint is above
								crossCounter++;
						}
						else if (abs(testY - segY2) < TOLERANCE) { // cross is at 2nd vertex
							if (segY1 > testY) // otherpoint is above
								crossCounter++;
						}
						else
							crossCounter++;
					}
				}
			}

			// advance to next segment
			segX1 = segX2;
			segY1 = segY2;
			currNode = currNode->next;
		}
		//cout << "Found " << crossCounter << " crossings" << endl;

		// if crossCounter is odd, return true
		return (crossCounter % 2 == 1);
	}
	else
		return false;
}

void Shape2D::removeAllPoints() {
	coordNode *currNode = head;
	coordNode *prevNode;

	while (currNode != NULL) {
		prevNode = currNode;
		currNode = currNode->next;
		delete prevNode;
	}

	head = NULL;
	tail = NULL;
}

void Shape2D::loadPath(Drawing2D::GraphicsPath ^ aPath, float angle)
{
	coordNode *currNode = head;
	coordNode *prevNode;
	float adj = 1000.f;
	float X1, Y1, X2, Y2, X1R, Y1R, X2R, Y2R;
	//	if (closeShape)
	//		prevNode = tail;
	//	else
	prevNode = head;
	while (currNode != NULL) {
		X1 = prevNode->thePoint.X;
		Y1 = prevNode->thePoint.Y;
		X2 = currNode->thePoint.X;
		Y2 = currNode->thePoint.Y;
		X1R = X1 * cos(angle) - Y1 * sin(angle);
		Y1R = X1 * sin(angle) + Y1 * cos(angle);
		X2R = X2 * cos(angle) - Y2 * sin(angle);
		Y2R = X2 * sin(angle) + Y2 * cos(angle);
		aPath->AddLine(
			(float)(X1R*adj),
			(float)(Y1R*adj),
			(float)(X2R*adj),
			(float)(Y2R*adj));

		prevNode = currNode;
		currNode = currNode->next;
	}

}

Shape2D::~Shape2D() {
	// destructor for class. Simply delete all the points. 
	removeAllPoints();
}


void Shape2D::paint(Graphics ^g, Pen ^aPen, float adj, bool closeShape) {
	Pen^ blackPen = gcnew Pen(Color::Aquamarine, 1.0f*adj);

	coordNode *currNode = head;
	coordNode *prevNode;
	if (closeShape)
		prevNode = tail;
	else
		prevNode = head;
	while (currNode != NULL) {
		g->DrawLine(aPen,
			(int)(prevNode->thePoint.X*adj),
			(int)(prevNode->thePoint.Y*adj),
			(int)(currNode->thePoint.X*adj),
			(int)(currNode->thePoint.Y*adj));

		prevNode = currNode;
		currNode = currNode->next;
	}
}

ostream & operator<<(ostream & os, const Shape2D & aShape)
{   // output all the coordinates of a shape. 
	// this function can access private data of Shape2D because it is a friend

	coordNode *currNode = aShape.head;
	int i = 1;
	if (currNode != NULL) {
		os << "Bounding Box: (" << aShape.minX << ", " << aShape.minY << "), ("
			<< aShape.maxX << ", " << aShape.maxY << ")" << endl;
	}
	while (currNode != NULL) {
		os << i++ << " (" << currNode->thePoint.X << ", " << currNode->thePoint.Y << ") " << endl;
		currNode = currNode->next;
	}
	return os; // this allows other outputs to be printed after shape
}
