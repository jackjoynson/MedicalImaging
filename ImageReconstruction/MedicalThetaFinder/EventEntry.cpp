#include "EventEntry.h"

EventEntry::EventEntry(unsigned int timeStamp, double energy, double totalEnergy, int detector)
{
	_TimeStamp = timeStamp;

	_Energy = energy;

    _TotalEnergy = totalEnergy;

	_Detector = detector;
}
	
