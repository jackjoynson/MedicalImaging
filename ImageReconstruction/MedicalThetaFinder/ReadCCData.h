#ifndef ReadCCData_h
#define ReadCCData_h

#include "EventEntry.h"
#include "DetectorType.h"

#include <string>
#include <vector>
using namespace std;

class ReadCoincData
{
public:
	ReadCoincData();
    vector<EventEntry> GetEvents(string file, vector<DetectorType> detectors);



};

#endif
