/*
Philip Baker
philipba
PS7
*/

#pragma once
#include "Axle.h"

#include <string>
#include <fstream>
#include <vector>

#define MAX_DATA_SIZE 1000
class Axle;

enum class MotionDirection { X, Y, THETA };
enum class MotionType { POSITION, VELOCITY, ACCELERATION };

struct DataPoint {
	double time;
	double value;
};

struct InitialValues {
	double initPos;
	double initVel;
	double initAccel;
};

class Driver
{
	
private:

	bool isCyclic;
	Axle *drivenAxle;

	InitialValues initialX, initialY, initialTheta;
	std::vector<DataPoint> transX;
	std::vector<DataPoint> transY;
	std::vector<DataPoint> rotTheta;


protected:
	void integrate(std::vector<DataPoint> &source, std::vector<DataPoint> &destination, double initialValue);
	// uses trapezoid rule to obtain numeric integral of data in source and places it in destination

	void differentiate(std::vector<DataPoint> &source, std::vector<DataPoint> &destination, double initialValue);
	// calculates numeric differential of data in source and places it in destination

public:
	double timeStepForSim;
	double currTime;
	double startTime;

	Driver();

	Driver(std::ifstream &input) {
		readFile(input);
	}

	bool readFile(std::ifstream &input);
	// takes a pre-created ifstream and uses it to read information
	// about the movement the driver object will apply to the axle object.If the driver already has
	// direction data corresponding to the data provided in the file, it will be over-written with the data
	// read from the input file. Other direction data in the driver object will not be affected. 
	// Order of parameters is NOT important.Function returns false if the file being read does not contain 
	// the data for a driver object.

	void writeFile(std::ofstream &output, MotionDirection wantedDirection, MotionType wantedType);
	// writes all the motion parameters to a file, using the proper format.The
	//	wantedDirection indicates whether the motion data to be outputted should be X, Y, or THETA.
	//	The wantedType indicates whether the motion data should be output as POSITION, VELOCITY,
	//	or ACCELERATION

	double getPosition(double wantedTime, MotionDirection wantedDirection);
	// calculates and returns the position of the axle at the wantedTime in the wantedDirection.
	// Interpolates as needed.Returns –INFINITY(negative infinity) if value is unavailable.

	void loadChart(System::Windows::Forms::DataVisualization::Charting::Series ^aSeries,
		MotionDirection wantedDirection);

	void startSim(System::Windows::Forms::Panel ^ thePanel, int pauseTime);

	void takeNextStep();
	void reset();

	void setAxle(Axle *anAxle) {
		drivenAxle = anAxle;
	}

	void removeMotion(MotionDirection wantedDirection);


	void stepSim(System::Windows::Forms::Panel ^ thePanel);
	void reverseSim(System::Windows::Forms::Panel ^ thePanel, int pauseTime);
};