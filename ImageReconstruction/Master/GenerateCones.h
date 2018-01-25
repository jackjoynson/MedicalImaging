#ifndef GenerateCones_h
#define GenerateCones_h

#include "EventEntry.h"
#include "Cone.h"

#include <string>
#include <vector>

class GenerateCones
{
public:
	GenerateCones();
	vector<Cone> GetCones(vector<EventEntry> scatteringEvents, vector<EventEntry> absorpionEvents);
};

#endif