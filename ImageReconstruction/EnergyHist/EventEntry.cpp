#include "EventEntry.h"

EventEntry::EventEntry(long long timeStamp, long long energy, int detector)
{
	_TimeStamp = timeStamp;

	_Energy = energy;

	_Detector = detector;
}
	
