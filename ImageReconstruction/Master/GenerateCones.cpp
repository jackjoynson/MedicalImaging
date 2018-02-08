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


	const double ME = 511.0;
	const double C = 1.0;


	double scatterAngle = acos(1.0 - (ME*C*C*((1.0 / finalEnergy) - (1.0 / sourceEnergy))));

	DetectorType scatterDetector = detectors[scatterEvent.GetDetector()];
	DetectorType absorbDetector = detectors[absorbEvent.GetDetector()];
	double startX = scatterDetector.getDetectorXCord();
	double startZ = scatterDetector.getDetectorZCord();




	double dx = absorbDetector.getDetectorXCord() - scatterDetector.getDetectorXCord();
	double dz = absorbDetector.getDetectorZCord() - scatterDetector.getDetectorZCord();
	double detectorAngle = atan2(dx,dz);



	//double xzAngle = (scatterAngle / 2.0) - detectorAngle;
	double zDist = imageHeight + scatterDetector.getDetectorZCord();

	double xPointImagePlane = startX + (zDist*tan(-detectorAngle));


	//THIS WILL ALWAYS BE ZERO IF DETECTORS HAVE NO Y.
	double yImagePlane = 0;
	Cone newCone(startX, startZ, xPointImagePlane, yImagePlane, scatterAngle);
	return newCone;
}









vector<Cone> GenerateCones::GetCones(vector<EventEntry> scatteringEvents, vector<EventEntry> absorpionEvents, vector<DetectorType> detectors, double sourceEnergy, double imageHeight, int tolerance)
{
	vector<Cone> cones;

	//Finds sets of coincident events and calculates cones for each

	//i is the scattering event list index. Loop through each scattering event. 
	for (int i = 0; i < scatteringEvents.size(); i++)
	{

		//Find absorpion event timestamp that matches scatter event timestamp.
		for (int j = 0; j < absorpionEvents.size(); j++)
		{

			int upperLimit = absorpionEvents[j].GetTimeStamp() + tolerance;
			int lowerLimit = absorpionEvents[j].GetTimeStamp() - tolerance;
			
			if (scatteringEvents[i].GetTimeStamp() < upperLimit && scatteringEvents[i].GetTimeStamp() > lowerLimit)
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