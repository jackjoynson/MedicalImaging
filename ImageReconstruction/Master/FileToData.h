#ifndef FileToData_h
#define FileToData_h

#include "DetectorType.h"
#include "EventEntry.h"

#include <string>
#include <vector>

class FileToData
{
public:
	FileToData();
	vector<EventEntry> GetData(vector<string> files, vector<DetectorType> detectors, bool scatter);
};

#endif