#ifndef GenerateCones_h
#define GenerateCones_h

#include "EventEntry.h"
#include "Cone.h"
#include "DetectorType.h"

#include <string>
#include <vector>

class GenerateCones
{
public:
	GenerateCones();
	vector<Cone> GetCones(vector<EventEntry> scatteringEvents, vector<EventEntry> absorpionEvents, vector<DetectorType> detectors, double sourceEnergy, double imageHeight);

};

#endif