#pragma once
#include <string>
#include <vector>
#include "AxleLocation.h"
#include "Driver.h"

// this namespace is needed for GUI to work
using namespace System::Drawing;
class Driver;
class AxleLocation;

class Axle
{
private:

public:
	std::string partID = "";

	std::vector<AxleLocation *> itsGears;

	float startX = 0.f;
	float startY = 0.f;
	float startAngle = 0.f;

	float currX;
	float currY;
	float currAngle;
	float prevX;
	float prevY;
	float prevAngle;

	//readFile(stream inputFile)
	//writeFile(stream outputFile)

	AxleLocation* addGear(Gear2D * aGear, float xLoc, float yLoc);
	void paint(Graphics ^g, Pen ^aPen, float adj = 1000.);

	void step(Driver* aDriver);
	void step(AxleLocation* drivingObject);
	void step(Axle* drivingObject); 
	void step(Gear2D *drivingGear);


	void reset();


};