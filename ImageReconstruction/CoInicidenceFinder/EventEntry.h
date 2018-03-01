#ifndef EventEntry_h
#define EventEntry_h

#include <vector>

class EventEntry
{

private:
	unsigned int _TimeStamp;
	double _Energy;
	int _Detector;


public:
	EventEntry(unsigned int timeStamp, double energy, int detector);

	int GetTimeStamp()
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

	void SetTimeStamp(unsigned int timeStamp)
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
