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
    double startY = scatterDetector.getDetectorYCord();




	double dx = absorbDetector.getDetectorXCord() - scatterDetector.getDetectorXCord();
    double dy = absorbDetector.getDetectorYCord() - scatterDetector.getDetectorYCord();
	double dz = absorbDetector.getDetectorZCord() - scatterDetector.getDetectorZCord();
    double detectorAngleX = atan2(dx, dz);
    double detectorAngleY = atan2(dy, dz);



	//double xzAngle = (scatterAngle / 2.0) - detectorAngle;
	double zDist = imageHeight + scatterDetector.getDetectorZCord();

    double xPointImagePlane = startX + (zDist*tan(-detectorAngleX));

    double yPointImagePlane = startY + (zDist*tan(-detectorAngleY));

	//THIS WILL ALWAYS BE ZERO IF DETECTORS HAVE NO Y.
    //double yImagePlane = 0;


    Cone newCone(startX, startY ,startZ, -xPointImagePlane, -yPointImagePlane, scatterAngle);
	return newCone;
}
