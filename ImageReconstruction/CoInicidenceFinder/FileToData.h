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
	vector<EventEntry> GetData(vector<string> files, bool scatter);
};

#endif