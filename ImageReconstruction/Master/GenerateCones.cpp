#include <vector>
#include <cmath>

#include "GenerateCones.h"
#include "EventEntry.h"
#include "Cone.h"

using namespace std;

GenerateCones::GenerateCones()
{}




Cone CalculateCone(EventEntry scatterEvent, EventEntry absorbEvent, vector<DetectorType> detectors, double sourceEnergy, double imageHeight)
{
	double finalEnergy = absorbEvent.GetEnergy();


	const double ME = 9.10938e-31;
	const double C = 299792458.0;


	double scatterAngle = acos(1.0 - (ME*C*C*((1.0 / finalEnergy) - (1.0 / sourceEnergy))));

	DetectorType scatterDetector = detectors[scatterEvent.GetDetector()];
	DetectorType absorbDetector = detectors[absorbEvent.GetDetector()];
	double startX = scatterDetector.getDetectorXCord();
	double startY = scatterDetector.getDetectorYCord();

	//Work out xImagePlane value
	double dx = absorbDetector.getDetectorXCord() - scatterDetector.getDetectorXCord();
	double dy = absorbDetector.getDetectorYCord() - scatterDetector.getDetectorYCord();
	double detectorAngle = atan(dy / dx);

	double lineY = imageHeight - absorbDetector.getDetectorYCord();
	double lineX = lineY / tan(detectorAngle);
	double xImagePlane = absorbDetector.getDetectorXCord() - lineX;

	Cone newCone(startX, startY, xImagePlane, scatterAngle);
	return newCone;
}









vector<Cone> GenerateCones::GetCones(vector<EventEntry> scatteringEvents, vector<EventEntry> absorpionEvents, vector<DetectorType> detectors, double sourceEnergy, double imageHeight)
{
	vector<Cone> cones;

	//Finds sets of coincident events and calculates cones for each

	//i is the scattering event list index. Loop through each scattering event. 
	for (int i = 0; i < scatteringEvents.size(); i++)
	{

		//Find absorpion event timestamp that matches scatter event timestamp.
		for (int j = 0; j < absorpionEvents.size(); j++)
		{

			//MAY NEED TO ADD TOLERANCE HERE
			if (absorpionEvents[j].GetTimeStamp() == scatteringEvents[i].GetTimeStamp())
			{
				//We have a pair so calculate the cone. 
				Cone newCone = CalculateCone(scatteringEvents[i], absorpionEvents[j], detectors, sourceEnergy, imageHeight);
				cones.push_back(newCone);

				break; //Break to new absorpion event.
			}
		}

	}


	return cones;
}