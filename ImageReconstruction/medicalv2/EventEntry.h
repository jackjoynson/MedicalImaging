#ifndef EventEntry_h
#define EventEntry_h

class EventEntry
{

private:
	unsigned int _TimeStamp;
	unsigned int _Energy;
	int _Detector;

public:
	EventEntry(unsigned int timeStamp, unsigned int energy, int detector);

	int GetTimeStamp()
	{
		return _TimeStamp;
	}

	int GetEnergy()
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
	void SetEnergy(unsigned int energy)
	{
		_Energy = energy;
	}
	void SetDetector(int detector)
	{
		_Detector = detector;
	}
};

#endif
