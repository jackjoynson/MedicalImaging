#ifndef EventEntry_h
#define EventEntry_h

#include <vector>

class EventEntry
{

private:
	double _TimeStamp;
	double _Energy;
	double _PosX, _PosY, _PosZ;
	int _Detector;


public:
	EventEntry(double timeStamp, double energy, int detector, double posX, double posY, double posZ);

	double GetTimeStamp()
	{
		return _TimeStamp;
	}

	double GetEnergy()
	{
		return _Energy;
	}

	int GetDetector()
	{
		return _Detector;
	}

	double GetPosX()
	{
		return _PosX;
	}
	double GetPosY()
	{
		return _PosY;
	}
	double GetPosZ()
	{
		return _PosZ;
	}


	void SetTimeStamp(double timeStamp)
	{
		_TimeStamp = timeStamp;
	}
	void SetEnergy(double energy)
	{
		_Energy = energy;
	}
	void SetDetector(int detector)
	{
		_Detector = detector;
	}
};

#endif
