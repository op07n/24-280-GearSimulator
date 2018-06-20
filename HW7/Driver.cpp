#include "Driver.h"

using namespace std;

using namespace System::Windows::Forms::DataVisualization;

void Driver::loadChart(Charting::Series ^ aSeries, MotionDirection wantedDirection)
{
	vector<DataPoint> *targetVector;

	switch (wantedDirection) {
	case MotionDirection::X:
		targetVector = &transX;
		break;
	case MotionDirection::Y:
		targetVector = &transY;
		break;
	case MotionDirection::THETA:
		targetVector = &rotTheta;
		break;
	}

	aSeries->Points->Clear();
	for (int i = 0; i < (int)targetVector->size(); i++)
		aSeries->Points->AddXY((*targetVector)[i].time, (*targetVector)[i].value);

}












void Driver::startSim(System::Windows::Forms::Panel ^thePanel, int pauseTime)
{
	timeStepForSim = 5.;

	double endTime;   // needs to be taken from maximums of all movements

	if (transX.size() > 0)
		endTime = transX.back().time;
	else
		endTime = -INFINITY;

	if (transY.size() > 0 && transY.back().time > endTime)
		endTime = transY.back().time;
	if (rotTheta.size() > 0 && rotTheta.back().time > endTime)
		endTime = rotTheta.back().time;


	while (currTime <= endTime) {
		// advance simulation time
		currTime += timeStepForSim;

		// move the axle to new position
		drivenAxle->step(this);

		thePanel->Refresh();

		//sleep_for(nanoseconds(pauseTime));
		System::Threading::Thread::Sleep(pauseTime);
	}

}

void Driver::reverseSim(System::Windows::Forms::Panel ^thePanel, int pauseTime)
{
	timeStepForSim = 5.;

	

	while (currTime >= 0) {
		
		// advance simulation time
		currTime -= timeStepForSim;

		// move the axle to new position
		drivenAxle->step(this);

		thePanel->Refresh();

		//sleep_for(nanoseconds(pauseTime));
		System::Threading::Thread::Sleep(pauseTime);
	}

}

void Driver::stepSim(System::Windows::Forms::Panel ^ thePanel) {
	timeStepForSim = 5.;

	double endTime;   // needs to be taken from maximums of all movements

	if (transX.size() > 0)
		endTime = transX.back().time;
	else
		endTime = -INFINITY;

	if (transY.size() > 0 && transY.back().time > endTime)
		endTime = transY.back().time;
	if (rotTheta.size() > 0 && rotTheta.back().time > endTime)
		endTime = rotTheta.back().time;

	currTime += timeStepForSim;

	if (currTime <= endTime) {
		drivenAxle->step(this);
		thePanel->Refresh();
	}

}

















void Driver::takeNextStep()
{
}

void Driver::reset()
{
	currTime = 0;
}

void Driver::removeMotion(MotionDirection wantedDirection)
{
	switch (wantedDirection) {
	case MotionDirection::X:
		transX.clear();
		break;
	case MotionDirection::Y:
		transY.clear();
		break;
	case MotionDirection::THETA:
		rotTheta.clear();
		break;
	}
}

Driver::Driver()
{
	transX.clear();
	transY.clear();
	rotTheta.clear();
}

bool Driver::readFile(ifstream & input)
{
	string inString;
	int dataStart;

	MotionDirection currDirection;
	MotionType currType;
	vector<DataPoint> currDataVector;
	double currInitPos, currInitVel, currInitAccel;

	string paramValue;
	double numericValue;

	while (!input.eof()) {
		getline(input, inString);
		dataStart = (int)inString.find(":") + 1;
		paramValue = inString.substr(dataStart);
		if (inString.find("Direction") != string::npos) {
			if (paramValue.find("THETA") != string::npos)
				currDirection = MotionDirection::THETA;
			else if (paramValue.find("X") != string::npos)
				currDirection = MotionDirection::X;
			else if (paramValue.find("Y") != string::npos)
				currDirection = MotionDirection::Y;
		}
		else if (inString.find("Data Values") != string::npos) {
			if (paramValue.find("POSITION") != string::npos)
				currType = MotionType::POSITION;
			else if (paramValue.find("VELOCITY") != string::npos)
				currType = MotionType::VELOCITY;
			else if (paramValue.find("ACCELERATION") != string::npos)
				currType = MotionType::ACCELERATION;
		}
		else if (inString.find("Cyclic") != string::npos) {
			isCyclic = (paramValue.find("YES") != string::npos);
		}
		else if (inString.find("Initial") != string::npos) {
			numericValue = stod(paramValue);
			if (inString.find("Position") != string::npos)
				currInitPos = numericValue;
			else if (inString.find("Velocity") != string::npos)
				currInitVel = numericValue;
			else if (inString.find("Acceleration") != string::npos)
				currInitAccel = numericValue;
		}
		else if (inString.find("Start Data") != string::npos) {
			int i = 0;
			double currTime, currValue;
			currDataVector.clear();

			getline(input, inString);
			while (!input.eof() && inString.find("End Data") == string::npos) {
				dataStart = (int)inString.find("\t") + 1;
				currTime = stod(inString.substr(0, dataStart));
				startTime = currTime;
				currValue = stod(inString.substr(dataStart));
				currDataVector.push_back(DataPoint());
				currDataVector.back().time = currTime;
				currDataVector.back().value = currValue;

				getline(input, inString);
			}

		}
	}

	// now that all data is read in, it must be placed somewhere
	vector<DataPoint>* targetVector;
	InitialValues *targetInit;

	switch (currDirection) {
	case MotionDirection::X:
		transX.clear();
		targetVector = &transX;
		targetInit = &initialX;
		break;
	case MotionDirection::Y:
		transY.clear();
		targetVector = &transY;
		targetInit = &initialY;
		break;
	case MotionDirection::THETA:
		rotTheta.clear();
		targetVector = &rotTheta;
		targetInit = &initialTheta;
		break;
	}

	// store initial values
	targetInit->initPos = currInitPos;
	targetInit->initVel = currInitVel;
	targetInit->initAccel = currInitAccel;

	// store data values (integrate as needed)
	switch (currType) {
	case MotionType::POSITION:               // copy data directly
											 //targetVector->resize(currDataVector.size());
		*targetVector = currDataVector;
		break;
	case MotionType::VELOCITY:               // integrate once
		integrate(currDataVector, *targetVector, currInitPos);
		break;
	case MotionType::ACCELERATION:           // integrate twice
		vector<DataPoint> tempVelocity;
		integrate(currDataVector, tempVelocity, currInitVel);
		integrate(tempVelocity, *targetVector, currInitPos);
		break;
	}

	return true;
}

void Driver::writeFile(ofstream & output, MotionDirection wantedDirection, MotionType wantedType)
{
	vector<DataPoint>* targetVector;
	InitialValues *targetInit;

	string directionText;
	string typeText;

	switch (wantedDirection) {
	case MotionDirection::X:
		targetVector = &transX;
		targetInit = &initialX;
		directionText = "X";
		break;
	case MotionDirection::Y:
		targetVector = &transY;
		directionText = "Y";
		targetInit = &initialY;
		break;
	case MotionDirection::THETA:
		targetVector = &rotTheta;
		directionText = "THETA";
		targetInit = &initialTheta;
		break;
	}

	if (targetVector->size() > 0) {
		vector<DataPoint> tempValues;

		switch (wantedType) {
		case MotionType::POSITION:               // copy data directly
			tempValues = *targetVector;
			typeText = "POSITION";
			break;
		case MotionType::VELOCITY:               // differentiate once
			differentiate(*targetVector, tempValues, targetInit->initVel);
			typeText = "VELOCITY";
			break;
		case MotionType::ACCELERATION:           // differentiate twice
			vector<DataPoint> tempVelocity;
			differentiate(*targetVector, tempVelocity, targetInit->initVel);
			differentiate(tempVelocity, tempValues, targetInit->initAccel);
			typeText = "ACCELERATION";
			break;
		}

		output << "Movement:" << endl << endl;

		output << "Direction: " << directionText << endl;
		output << "Data Values : " << typeText << endl;
		output << "Cyclic : " << (isCyclic ? "YES" : "NO") << endl;
		output << "Initial Position : " << targetInit->initPos << endl;
		output << "Initial Velocity : " << targetInit->initVel << endl;
		output << "Initial Acceleration : " << targetInit->initAccel << endl << endl;

		output << "Start Data :" << endl;

		for (int i = 0; i < (int)tempValues.size(); i++)
			output << tempValues[i].time << "\t" << tempValues[i].value << endl;

		output << "End Data :" << endl;

	}

}

double Driver::getPosition(double wantedTime, MotionDirection wantedDirection)
{
	vector <DataPoint>* targetVector;
	int first, last, middle;

	// make targetVector point to correct data
	switch (wantedDirection) {
	case MotionDirection::X:
		targetVector = &transX;
		break;
	case MotionDirection::Y:
		targetVector = &transY;
		break;
	case MotionDirection::THETA:
		targetVector = &rotTheta;
		break;
	}

	// first, check to see if there are enough values in data
	if (targetVector->size() < 2)
		return -INFINITY;

	// then, check to see if wantedTime is within data bounds
	// this will need to be reworked for cyclical movements
	if (wantedTime < targetVector->front().time || wantedTime > targetVector->back().time)
		return -INFINITY;

	// find the time segment near wantedTime. Use binary search
	first = 0;
	last = (int)targetVector->size() - 1;
	middle = (first + last) / 2;
	bool foundSegment = false;

	while (!foundSegment) {
		if (wantedTime < (*targetVector)[middle].time)
			last = middle - 1;
		else if ((*targetVector)[middle + 1].time < wantedTime)
			first = middle + 1;
		else
			foundSegment = true;

		middle = (first + last) / 2;
	}

	double lowerT = (*targetVector)[middle].time;
	double upperT = (*targetVector)[middle + 1].time;
	double lowerV = (*targetVector)[middle].value;
	double upperV = (*targetVector)[middle + 1].value;

	return lowerV + (wantedTime - lowerT) / (upperT - lowerT) * (upperV - lowerV);
}

void Driver::integrate(vector<DataPoint>& source, vector<DataPoint>& destination, double initialValue)
{
	double deltaT;
	destination.clear();
	destination.push_back(DataPoint());
	destination.front().time = source.front().time;
	destination.front().value = initialValue;
	for (int i = 1; i < (int)source.size(); i++) {
		destination.push_back(DataPoint());
		destination[i].time = source[i].time;
		deltaT = source[i].time - source[i - 1].time;
		destination[i].value = destination[i - 1].value + (source[i - 1].value + source[i].value) / 2. * deltaT;
	}

}

void Driver::differentiate(vector<DataPoint>& source, vector<DataPoint>& destination, double initialValue)
{
	double deltaT;
	destination.clear();
	destination.push_back(DataPoint());
	destination.front().time = source.front().time;
	destination.front().value = initialValue;
	for (int i = 1; i < (int)source.size(); i++) {
		destination.push_back(DataPoint());
		destination[i].time = source[i].time;
		deltaT = source[i].time - source[i - 1].time;
		destination[i].value = (source[i].value - source[i - 1].value) / deltaT;
	}

}

