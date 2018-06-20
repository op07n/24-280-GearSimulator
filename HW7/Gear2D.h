/*
Philip Baker
philipba 
PS7
*/
#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "Line2D.h"
#include "Shape2D.h"
#include "Axle.h"
#include "AxleLocation.h"

const double PI = 3.14159265;
const double ADDENDUMFACTOR = 1.0; // addendum = 1/pitch
const double DEDENDUMFACTOR = 1.25; // dedendum = 1.25/pitch
const double MESHTOLERANCE = 0.1; // inches
const double EPSILON = 10e-8;
const double PITCHANGLE = 20.0;

// removed from here since it is not strictly needed 
// and it interferes with GUI libraries. Moved to .cpp
//using namespace std;  

// this namespace is needed for GUI to work
using namespace System::Drawing;

struct GearColor {
	unsigned char A;
	unsigned char R;
	unsigned char G;
	unsigned char B;
};

class AxleLocation;
class Axle;

class Gear2D
{
public:
	std::string partID;
	GearColor theColor;
	double pitch;  // teeth per inch
	int	numbTeeth;
	double startX;
	double startY;
	double startAngle;  // 0 @ x-axis, CCW
	int plane;
	Shape2D toothShape;
	double prevX, prevY, prevAngle;
	double currX, currY, currAngle;
	std::vector< AxleLocation * > itsAxles;
	std::vector< Gear2D * > itsMeshedGears;
	//Drawing2D::GraphicsPath *toothPath;

public:
	Gear2D();

	Gear2D(std::ifstream &input);
	// additional constructor for the class.Takes a pre - created ifstream and
	// uses it to read coordinate information for the shape.The constructor needs 
	// to instantiate any constituent objects and/or data structures.

	bool readFile(std::ifstream &input);
	// overrides all data in the gear object with data read from an
	// input file.Note that the method’s parameter cannot be a string filename 
	// because the file may already be in the process of being read.A typical 
	// gear input file is attached to this assignment. Note that the order of 
	// parameters is NOT important.Function returns false if the file being read
	// does not contain the data for a gear object.

	void writeFile(std::ofstream &output);
	// writes all the gear parameters to a file, using the approved format.

	double getPitchDiam();
	// calculates and returns the pitch diameter of the gear.

	bool setPitch(double newPitch) {
		pitch = newPitch;
		generateTooth();
		return pitch;
	}

	int setNumbTeeth(int newNumbTeeth) {
		numbTeeth = newNumbTeeth;
		generateTooth();
		return numbTeeth;
	}

	void setPartID(std::string newID) {
		partID = newID;
	}

	void setPlane(int newPlane) {
		plane = newPlane;
	}

	void setStartX(double newStart) {
		startX = currX = prevX = newStart;

	}

	void setStartY(double newStart) {
		startY = currY = prevY = newStart;
	}

	void setStartAngle(double newStart) {
		startAngle = currAngle = prevAngle = newStart;
	}

	std::string getPartID() {
		return partID;
	}

	double getPitch() {
		return pitch;
	}

	int getNumbTeeth() {
		return numbTeeth;
	}

	int getPlane() {
		return plane;
	}

	double getStartX() {
		return startX;
	}

	double getStartY() {
		return startY;
	}

	double getStartAngle() {
		return startAngle;
	}

	void preview(Graphics ^ g, Pen ^ aPen, float adj);
	// bool generateToothFull(Drawing2D::GraphicsPath ^ toothPath, float angle);
	//bool generateToothFull(Drawing2D::GraphicsPath ^ toothPath);
	//bool generateToothFull();

	//void setColor(Color ^newColor);
	void setColor(Color newColor);
	void setColor(std::string colorValues);

	Color getColor() {
		return Color::FromArgb(theColor.A, theColor.R, theColor.G, theColor.B);
	}

	Axle *getAxle();

	bool generateTooth();
	// using the gear’s parameters, generates the geometry of a single tooth, 
	// using the center of the gear as the origin.Although you may want to work
	// out the involute geometry, you are NOT required to do so for PS4. 
	// A representative straight-edge tooth is perfectly acceptable.
	// Use the constants described in the UML diagram.The geometry generated 
	// will be stored in the toothShape variable. Returns false if there is 
	// insufficient information to generate tooth geometry.

	void paint(Graphics ^g, Pen ^aPen, float adj = 1000.);
	// generates the geometry of the gear in its current state on the given
	// geometric space.

	void reset();
	// sets previous and current position to the starting position

	bool canCalculate() {
		// used to determine if gear has enough information to calculate geometry
		return pitch > EPSILON && numbTeeth > 1;
	}

	void paintPartID(Graphics ^ g, Pen ^ aPen, float adj);
	void step(Gear2D *gear);
	void step(Axle *anAxle);

	bool canMesh(Gear2D *otherGear);
	void unmeshAll();

	void addAxle(AxleLocation *anAxleLoc) {
		itsAxles.push_back(anAxleLoc);
	}
	void addMeshedGear(Gear2D *theGear) {
		itsMeshedGears.push_back(theGear);
		theGear->itsMeshedGears.push_back(this);
	}

	bool unmeshGear(Gear2D *otherGear);

};

