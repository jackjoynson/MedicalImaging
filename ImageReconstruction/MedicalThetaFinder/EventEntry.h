#ifndef EventEntry_h
#define EventEntry_h

class EventEntry
{

private:
	unsigned int _TimeStamp;
    double  _Energy;
    double _TotalEnergy;
	int _Detector;

public:
    EventEntry(unsigned int timeStamp, double energy, double totalEnergy, int detector);

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

    double GetTotalEnergy()
    {
        return _TotalEnergy;
    }

	void SetTimeStamp(unsigned int timeStamp)
	{
		_TimeStamp = timeStamp;
	}
    void SetEnergy(double energy)
	{
		_Energy = energy;
	}

    void SetTotalEnergy(double totalEnergy)
    {
        _TotalEnergy = totalEnergy;
    }

	void SetDetector(int detector)
	{
		_Detector = detector;
	}
};

#endif
