#ifndef ReadCCData_h
#define ReadCCData_h

#include "EventEntry.h"
#include "Cone.h"
#include "DetectorType.h"

#include <string>
#include <vector>

class ReadCoincData
{
public:
	ReadCoincData();
	vector<Cone> GetCones(string file, vector<DetectorType> detectors, double sourceEnergy, double imageHeight, int tolerance, bool isSimulation);

};

#endif