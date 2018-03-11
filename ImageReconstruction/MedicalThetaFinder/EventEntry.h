#ifndef EventEntry_h
#define EventEntry_h

class EventEntry
{

private:
	unsigned int _TimeStamp;
	unsigned int _Energy;
    unsigned int _TotalEnergy;
	int _Detector;

public:
    EventEntry(unsigned int timeStamp, unsigned int energy, unsigned int totalEnergy, int detector);

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

    int GetTotalEnergy()
    {
        return _TotalEnergy;
    }

	void SetTimeStamp(unsigned int timeStamp)
	{
		_TimeStamp = timeStamp;
	}
	void SetEnergy(unsigned int energy)
	{
		_Energy = energy;
	}

    void SetTotalEnergy(unsigned int totalEnergy)
    {
        _TotalEnergy = totalEnergy;
    }

	void SetDetector(int detector)
	{
		_Detector = detector;
	}
};

#endif
