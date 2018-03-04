#ifndef GenerateCone_h
#define GenerateCone_h

#include "Cone.h"
#include "EventEntry.h"
#include "DetectorType.h"


class GenerateCone
{
public:
	static Cone CalculateCone(EventEntry scatterEvent, EventEntry absorbEvent, vector<DetectorType> detectors, double sourceEnergy, double imageHeight);
private:
	GenerateCone(){}
};

#endif