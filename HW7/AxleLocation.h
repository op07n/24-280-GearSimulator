#pragma once
#include <string>
#include "Gear2D.h"
#include "Axle.h"

class Axle;
class Gear2D;

class AxleLocation
{
private:
public:
	float relativeX;
	float relativeY;

	bool releaseX;
	bool releaseY;
	bool releaseTheta;

	Gear2D* theGear;
	Axle* theAxle;

	AxleLocation(Gear2D *aGear, Axle *anAxle, float xLoc, float yLoc) {
		relativeX = xLoc;
		relativeY = yLoc;
		theGear = aGear;
		theAxle = anAxle;
	}

	AxleLocation(Gear2D *aGear, Axle *anAxle, bool relX, bool relY, bool relTh) {
		releaseX = relX;
		releaseY = relY;
		releaseTheta = relTh;
		theGear = aGear;
		theAxle = anAxle;
	}

};
