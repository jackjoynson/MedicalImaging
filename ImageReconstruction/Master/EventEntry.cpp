#include "EventEntry.h"

EventEntry::EventEntry(unsigned int timeStamp, unsigned int energy, int detector)
{
	_TimeStamp = timeStamp;

	_Energy = energy;

	_Detector = detector;
}
	
