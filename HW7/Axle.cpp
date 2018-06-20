#include "Axle.h"

AxleLocation* Axle::addGear(Gear2D * aGear, float xLoc, float yLoc)
{
	Gear2D *currGear;

	// be sure not to add the same gear twice
	for (int i = 0; i < (int)itsGears.size(); i++) {
		currGear = itsGears[i]->theGear;

		if (currGear == aGear)
			return NULL;   // <<<<<<<<<<< possible exit from function
	}

	AxleLocation *newLoc = new AxleLocation(aGear, this, xLoc, yLoc);
	itsGears.push_back(newLoc);
	aGear->addAxle(newLoc);
	return newLoc;
}

void Axle::paint(Graphics ^ g, Pen ^ aPen, float adj)
{
	float diam = 500.;
	//g->DrawEllipse(aPen, currX * adj - diam / 2.f, currY * adj - diam / 2.f, diam, diam);
	//g->DrawLine(aPen, currX * adj - diam / 2.f, currY * adj,
	//	currX * adj + diam / 2.f, currY * adj);
	//g->DrawLine(aPen, currX * adj, currY * adj - diam / 2.f,
	//	currX * adj, currY * adj + diam / 2.f);

	g->TranslateTransform(currX * adj, currY * adj);
	g->RotateTransform(currAngle * 180.f / PI);

	g->DrawEllipse(aPen, -diam / 2.f, -diam / 2.f, diam, diam);
	g->DrawLine(aPen, -diam / 2.f, 0.f, diam / 2.f, 0.f);
	g->DrawLine(aPen, 0.f, -diam / 2.f, 0.f, diam / 2.f);

	g->RotateTransform(-currAngle * 180.f / PI);
	g->TranslateTransform(-currX * adj, -currY * adj);
}

void Axle::step(AxleLocation* drivingObject)
{	// the axle is being moved by a gear. Get new position of axle by referencing
	// the gear's current and previous positions and the relative positionings
}

void Axle::step(Axle * drivingObject)
{	// in future development, an axle could drive another axle ???

	//

}


void Axle::step(Gear2D *drivingGear)
{	
	// move me
	// move other gears 

	prevX = currX;
	prevY = currY;
	prevAngle = currAngle;
	double deltaAngle = (drivingGear->currAngle - drivingGear->prevAngle);
	currAngle +=  deltaAngle;

	AxleLocation *currAxleLoc;
	Gear2D *currGear;


	for (int i = 0; i < (int)itsGears.size(); i++) {
		currAxleLoc = itsGears[i];
		currGear = currAxleLoc->theGear;

		if (currGear != drivingGear) {
			currGear->step(this);
		}
	}

}

void Axle::step(Driver *aDriver)
{   // this move is called by a driver, so just move the axle to new position and
	// call for step of all related gears except the drivingGear.

	AxleLocation *currAxleLoc;
	Gear2D *currGear;

	double currTime = aDriver->currTime;
	double newX = aDriver->getPosition(currTime, MotionDirection::X);
	double newY = aDriver->getPosition(currTime, MotionDirection::Y);
	double newAngle = aDriver->getPosition(currTime, MotionDirection::THETA);

	prevX = currX;
	prevY = currY;
	prevAngle = currAngle;

	if (newX != -INFINITY)
		currX = newX;
	if (newY != -INFINITY)
		currY = newY;
	if (newAngle != -INFINITY)
		currAngle = newAngle;

	for (int i = 0; i < (int)itsGears.size(); i++) {
		currAxleLoc = itsGears[i];
		currGear = currAxleLoc->theGear;

		//currGear->step(currAxleLoc);
		currGear->step(this);
	}

}
void Axle::reset() {
	// sets previous and current position to the starting position
	currX = prevX = startX;
	currY = prevY = startY;
	currAngle = prevAngle = startAngle;
}

