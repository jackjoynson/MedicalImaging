#include "EventEntry.h"

EventEntry::EventEntry(unsigned int timeStamp, double energy, int detector)
{
	_TimeStamp = timeStamp;

	_Energy = energy;

	_Detector = detector;
}
	
