class EventEntry
{

	private:
	int _TimeStamp;
	int _Energy;
	int _Detector;

	public: 
		EventEntry(int timeStamp, int energy, int detector);
	 
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

	void SetTimeStamp(int timeStamp)
	{
		_TimeStamp = timeStamp;
	}
	void SetEnergy(int energy)
	{
		_Energy = energy;
	}
	void SetDetector(int detector)
	{
		_Detector = detector;
	}
};
