#include "EventEntry.h"

EventEntry::EventEntry(double timeStamp, double energy, int detector, double posX, double posY, double posZ)
{
	_TimeStamp = timeStamp;

	_Energy = energy;

	_Detector = detector;

	_PosX = posX;
	_PosY = posY;
	_PosZ = posZ;
}
	
