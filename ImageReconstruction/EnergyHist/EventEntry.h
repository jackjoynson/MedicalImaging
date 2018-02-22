#ifndef EventEntry_h
#define EventEntry_h

#include <vector>

class EventEntry
{

private:
	long long _TimeStamp;
	long long _Energy;
	int _Detector;


public:
	EventEntry(long long timeStamp, long long energy, int detector);

	long long GetTimeStamp()
	{
		return _TimeStamp;
	}

	long long GetEnergy()
	{
		return _Energy;
	}

	int GetDetector()
	{
		return _Detector;
	}

	void SetTimeStamp(long long timeStamp)
	{
		_TimeStamp = timeStamp;
	}
	void SetEnergy(long long energy)
	{
		_Energy = energy;
	}
	void SetDetector(int detector)
	{
		_Detector = detector;
	}
};

#endif
