#include "EventEntry.h"

EventEntry::EventEntry(unsigned int timeStamp, unsigned int energy, unsigned int totalEnergy, int detector)
{
	_TimeStamp = timeStamp;

	_Energy = energy;

    _TotalEnergy = totalEnergy;

	_Detector = detector;
}
	
