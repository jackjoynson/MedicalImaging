#include <vector>
#include <cmath>

#include "GenerateCone.h"
#include "Cone.h"
#include "DetectorType.h"
#include "EventEntry.h"

using namespace std;


Cone GenerateCone::CalculateCone(EventEntry scatterEvent, EventEntry absorbEvent, vector<DetectorType> detectors, double sourceEnergy, double imageHeight)
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
	double detectorAngle = atan2(dx, dz);



	//double xzAngle = (scatterAngle / 2.0) - detectorAngle;
	double zDist = imageHeight + scatterDetector.getDetectorZCord();

	double xPointImagePlane = startX + (zDist*tan(-detectorAngle));


	//THIS WILL ALWAYS BE ZERO IF DETECTORS HAVE NO Y.
	double yImagePlane = 0;
	Cone newCone(startX, startZ, -xPointImagePlane, yImagePlane, scatterAngle);
	return newCone;
}