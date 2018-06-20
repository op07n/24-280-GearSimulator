/*
Philip Baker
philipba
PS7
*/
#include "Gear2D.h"

using namespace std;
using namespace System;
using namespace System::Drawing;

Gear2D::Gear2D()
{
	partID = "";
	pitch = 0.;
	numbTeeth = 0;
	startX = 0.;
	startY = 0.;
	startAngle = 0.;  // 0 @ x-axis, CCW
	plane = 0;
	prevX = prevY = prevAngle = 0.0;
	currX = currY = currAngle = 0.0;
	setColor("255 0 0 255");  // set default color to blue
}

Gear2D::Gear2D(ifstream &input) {
	// additional constructor for the class.Takes a pre - created ifstream and
	// uses it to read coordinate information for the shape.The constructor needs 
	// to instantiate any constituent objects and/or data structures.
	readFile(input);
}

bool Gear2D::readFile(ifstream &input) {
	// overrides all data in the gear object with data read from an
	// input file.Note that the method’s parameter cannot be a string filename 
	// because the file may already be in the process of being read.A typical 
	// gear input file is attached to this assignment. Note that the order of 
	// parameters is NOT important.Function returns false if the file being read
	// does not contain the data for a gear object.

	string inString;
	int dataStart;

	partID = "";
	pitch = 0.;
	numbTeeth = 0;
	startX = 0.;
	startY = 0.;
	startAngle = 0.;  // 0 @ x-axis, CCW
	plane = 0;
	toothShape;
	prevX = prevY = prevAngle = 0.0;
	currX = currY = currAngle = 0.0;
	setColor("255 0 0 255");  // set default color to blue

	while (!input.eof()) {
		getline(input, inString);
		dataStart = (int)inString.find(":") + 1;
		if (inString.find("partID") != string::npos) {
			partID = inString.substr(dataStart + 1); // +1 is to get rid of extra space (trim wpould be better)
		}
		else if (inString.find("pitch") != string::npos) {
			pitch = stod(inString.substr(dataStart));
		}
		else if (inString.find("numbTeeth") != string::npos) {
			numbTeeth = stoi(inString.substr(dataStart));
		}
		else if (inString.find("startX") != string::npos) {
			startX = stod(inString.substr(dataStart));
		}
		else if (inString.find("startY") != string::npos) {
			startY = stod(inString.substr(dataStart));
		}
		else if (inString.find("startAngle") != string::npos) {
			startAngle = stod(inString.substr(dataStart));
		}
		else if (inString.find("plane") != string::npos) {
			plane = stoi(inString.substr(dataStart));
		}
		else if (inString.find("color") != string::npos) {
			setColor(inString.substr(dataStart));
		}
	}

	generateTooth();
	reset();
	return true;
}

void Gear2D::writeFile(ofstream &output) {
	// writes all the gear parameters to a file, using the approved format.
	output << "Gear :" << endl;
	output << "\tpartID : " << partID << endl;
	output << "\tpitch : " << pitch << endl;
	output << "\tnumbTeeth : " << numbTeeth << endl;
	output << "\tstartX : " << startX << endl;
	output << "\tstartY : " << startY << endl;
	output << "\tstartAngle : " << startAngle << endl;
	output << "\tplane : " << plane << endl;
	output << "\tcolor: " << (int)theColor.A << " " << (int)theColor.R << " " << (int)theColor.G << " " << (int)theColor.B;

}

double Gear2D::getPitchDiam() {
	// calculates and returns the pitch diameter of the gear.
	return (double)numbTeeth / pitch;// / Math::PI;
}

Axle * Gear2D::getAxle()
{
	if (itsAxles.size() > 0)
		return itsAxles.front()->theAxle;
	else
		return NULL;
}

bool Gear2D::generateTooth() {
	// using the gear’s parameters, generates the geometry of a single tooth, 
	// using the center of the gear as the origin.Although you may want to work
	// out the involute geometry, you are NOT required to do so for PS4. 
	// A representative straight-edge tooth is perfectly acceptable.
	// Use the constants described in the UML diagram.The geometry generated 
	// will be stored in the toothShape variable. Returns false if there is 
	// insufficient information to generate tooth geometry.


	float pitchDiam = getPitchDiam();

	if (pitchDiam <= TOLERANCE)
		return false;
	else {

		toothShape.removeAllPoints();

		float rbase = pitchDiam / 2. * Math::Cos(Math::PI / 180. * PITCHANGLE);
		float alpha = Math::PI / 180. * 1.5;
		float dist = 2. * rbase * Math::Sin(alpha / 2.);
		float currX, currY;
		float currRadial = rbase;
		float rotatedX, rotatedY;
		int numbPoints = 60;
		// position angle assumes with of tooth at base circle is equal to 
		// space between teeth at base circle (not quite correct since this
		// equality should be at pitch circle)
		float positionAngle = 2. * Math::PI / (float)numbTeeth / 4.;
		float addendumRadius = pitchDiam / 2. + ADDENDUMFACTOR / pitch;
		float dedendumRadius = pitchDiam / 2. - DEDENDUMFACTOR / pitch;
		int i; // declared outside for loop so that we can use its value after for loop

		for (i = 0; i <= numbPoints && currRadial < addendumRadius; i++) {
			// calculate involute coordinates
			currX = -rbase * Math::Sin(i * alpha) + i * dist * Math::Cos(i*alpha);
			currY = rbase * Math::Cos(i * alpha) + i * dist * Math::Sin(i*alpha);
			currRadial = sqrt(currX * currX + currY * currY);

			// add point on "right" edge of tooth by rotating CW a bit
			rotatedX = currX * Math::Cos(-positionAngle) - currY * Math::Sin(-positionAngle);
			rotatedY = currX * Math::Sin(-positionAngle) + currY * Math::Cos(-positionAngle);
			toothShape.addPoint(rotatedX, rotatedY, i + 1);

			// add point on "left" edge of tooth (make X negative)
			toothShape.addPoint(-rotatedX, rotatedY, i + 2);
		}
		//toothShape.addPoint(0., addendumDiam / 2., i + 1); // point in middle of top area

		toothShape.addPoint(0., currRadial, i + 1); // point in middle of top area

													// 4 points between teeth, along circle
		for (i = 1; i <= 4; i++) {
			toothShape.addPoint(rbase * Math::Sin(positionAngle * (i / 2.0 + 1.)),
				rbase * Math::Cos(positionAngle * (i / 2.0 + 1.)), 1);
		}
		return true;
	}
}

void Gear2D::paintPartID(Graphics ^g, Pen ^aPen, float adj) {

	// need to scale so that y-axis is down (otherwise text will be upside down)
	g->ScaleTransform(1, -1);

	String^ drawString = gcnew String(partID.c_str());

	// Create font and brush.
	Font^ drawFont = gcnew System::Drawing::Font("Arial", adj / 2);
	SolidBrush^ drawBrush = gcnew SolidBrush(aPen->Color);

	// Create point for upper-left corner of text.
	PointF drawPoint = PointF(150.0F, 150.0F);

	// Draw string to screen.
	g->DrawString(drawString, drawFont, drawBrush, drawPoint);

	// scale back to our normal y-axis is up
	g->ScaleTransform(1, -1);

}

void Gear2D::preview(Graphics ^g, Pen ^aPen, float adj) {
	Drawing2D::GraphicsPath^ toothPath = gcnew Drawing2D::GraphicsPath();
	SolidBrush^ drawBrush = gcnew SolidBrush(aPen->Color);
	Pen^ bluePen = gcnew Pen(Color::Blue, 3.0f);

	for (int i = 0; i < numbTeeth; i++) {
		toothShape.paint(g, aPen, adj, false);
		g->RotateTransform(360. / (float)numbTeeth);
	}
	g->FillPath(drawBrush, toothPath);
	//g->DrawPath(bluePen, toothPath);

}
void Gear2D::paint(Graphics ^g, Pen ^aPen, float adj) {
	// generates the geometry of the gear in its current state on the given
	// geometric space.

	Pen^ blackPen = gcnew Pen(Color::Black, 3.0f);
	Pen^ whitePen = gcnew Pen(Color::White, 3.0f);
	//Pen^ redPen = gcnew Pen(Color::Red, 3.0f);
	Pen^ bluePen = gcnew Pen(Color::Blue, 3.0f);

	float pitchDiam = getPitchDiam();
	//float rbase = pitchDiam / 2. * Math::Cos(Math::PI / 180. * PITCHANGLE);
	//float addedumDiam = pitchDiam + 2. * ADDENDUMFACTOR / pitch;
	//float dedendumDiam = pitchDiam - 2. * DEDENDUMFACTOR / pitch;

	//	g->DrawEllipse(blackPen, -rbase * adj, -rbase * adj, rbase * 2. * adj, rbase * 2.*adj);
	//	g->DrawEllipse(blackPen, -addedumDiam / 2. * adj, -addedumDiam / 2. * adj, addedumDiam * adj, addedumDiam*adj);
	//	g->DrawEllipse(blackPen, -dedendumDiam / 2. * adj, -dedendumDiam / 2. * adj, dedendumDiam * adj, dedendumDiam*adj);

	g->TranslateTransform(currX*adj, currY*adj);
	g->RotateTransform(currAngle / PI * 180.f);
	//g->DrawEllipse(bluePen, -pitchDiam / 2. * adj, -pitchDiam / 2. * adj, pitchDiam * adj, pitchDiam*adj);


	preview(g, aPen, adj);

	g->DrawEllipse(whitePen, -50, -50, 100, 100);
	g->RotateTransform(-currAngle / PI * 180.f);
	paintPartID(g, blackPen, adj);
	g->TranslateTransform(-currX * adj, -currY * adj);

}

void Gear2D::reset() {
	// sets previous and current position to the starting position
	currX = prevX = startX;
	currY = prevY = startY;
	currAngle = prevAngle = startAngle;
}















void Gear2D::step(Gear2D *gear)
{	
	double gearRatio = (float)gear->numbTeeth / (float)numbTeeth;
	double deltaAngle = gear->currAngle - gear->prevAngle;
	prevAngle = currAngle;
	currAngle += - (deltaAngle * gearRatio);

	

	for (int i = 0; i < itsMeshedGears.size(); i++) {

		if (itsMeshedGears.at(i) != gear) {
			itsMeshedGears.at(i)->step(this); // step all of its gears in opposite by ratio
			//itsMeshedGears.at(i)->itsAxles[0]->theAxle->step(this); // step axle in opposite direction
		}

	}
	itsAxles[0]->theAxle->step(this);

}

void Gear2D::step(Axle * anAxle)
{	// an axle is trying to move the gear. Need to get relative position
	// to calculate new position of gear. Then, request step of other related
	// axles and any meshed-in gears.

	//Axle *anAxle = anAxleLoc->theAxle;
	float deltaX = anAxle->currX - anAxle->prevX;
	float deltaY = anAxle->currY - anAxle->prevY;
	float deltaAngle = anAxle->currAngle - anAxle->prevAngle;

	float distanceX = currX - anAxle->prevX;
	float distanceY = currY - anAxle->prevY;

	prevX = currX;
	prevY = currY;
	prevAngle = currAngle;


	currAngle += deltaAngle;

	// now step other components
	for (int i = 0; i < itsMeshedGears.size(); i++) {

		//itsMeshedGears.at(i)->itsAxles[0]->theAxle->step(this); // step axle in opposite direction
		itsMeshedGears.at(i)->step(this); // step all of its gears in opposite by ratio

	}

}






















void Gear2D::setColor(Color newColor) {
	theColor.A = newColor.A;
	theColor.R = newColor.R;
	theColor.G = newColor.G;
	theColor.B = newColor.B;
}


void Gear2D::setColor(string colorValues) {
	char *temp = _strdup(colorValues.c_str());
	char * pch;
	pch = strtok(temp, " ,.-");
	theColor.A = stoi(pch);
	pch = strtok(NULL, " ,.-");
	theColor.R = stoi(pch);
	pch = strtok(NULL, " ,.-");
	theColor.G = stoi(pch);
	pch = strtok(NULL, " ,.-");
	theColor.B = stoi(pch);

}



bool Gear2D::canMesh(Gear2D *otherGear) {
	
	double dist = Line2D::getLength(startX, startY, otherGear->startX, otherGear->startY);

	return abs(pitch - otherGear->pitch) < EPSILON && abs((getPitchDiam() + otherGear->getPitchDiam())/2  - dist)  < MESHTOLERANCE && plane == otherGear->plane;
}



void Gear2D::unmeshAll() {
	// NOT just a plain remove all since we have to eliminate a bi-directional relationship
	while (itsMeshedGears.size() > 0) {
		unmeshGear(itsMeshedGears.back()); // for a vector, it's faster to remove items from the back
	}
}

bool Gear2D::unmeshGear(Gear2D *otherGear) {
	// if otherGear is meshed to this one, remove it, ask otherGear to remove this one, and return true

	bool foundOther = false;
	unsigned int i = 0;
	while (!foundOther && i < itsMeshedGears.size()) {
		if (itsMeshedGears[i] == otherGear) {
			foundOther = true;
			itsMeshedGears.erase(itsMeshedGears.begin() + i);
		}
		i++;
	}
	if (foundOther)
		otherGear->unmeshGear(this);

	return foundOther;
}