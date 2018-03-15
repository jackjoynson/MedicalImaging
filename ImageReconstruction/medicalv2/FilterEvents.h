#ifndef FilterEvents_h
#define FilterEvents_h

#include "EventEntry.h"
#include "Cone.h"
#include "DetectorType.h"

#include <string>
#include <vector>

class FilterEvents
{
public:
	FilterEvents();
	vector<Cone> GetCones(vector<EventEntry> scatteringEvents, vector<EventEntry> absorpionEvents, vector<DetectorType> detectors, double sourceEnergy, double imageHeight, int tolerance);

};

#endif