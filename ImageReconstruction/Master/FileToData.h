#include "DetectorType.h"
#include "EventEntry.h"

class FileToData
{
public:
	vector<EventEntry> GetData(vector<string> files, vector<DetectorType> detectors, bool scatter);
};
