#ifndef FileToData_h
#define FileToData_h

#include "DetectorType.h"
#include "EventEntry.h"

#include <string>
#include <vector>

class FileToData
{
public:
	FileToData(bool IsSimulation);
	vector<EventEntry> GetData(vector<string> files, vector<DetectorType> detectors, bool scatter);
private:
	bool _IsSimulation;
};

#endif