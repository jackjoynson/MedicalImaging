#ifndef FileToData_h
#define FileToData_h

#include "DetectorType.h"
#include "EventEntry.h"

#include <string>
#include <vector>

class FileToData
{
public:
	FileToData(bool usingCompass);
	vector<EventEntry> GetData(vector<string> files, int fileIndex, bool lookForData, double constant, double gradient, bool isScat, double scatLim, double absLim, bool useLims);
private:
	bool _UsingCompass;
};

#endif