using namespace std;

class EventEntry
{

	private int _TimeStamp;
	
	private int _Energy;

	private int _Detector;

	public EventEntry(int timeStamp, int energy, int detector)
	{
		_TimeStamp = timeStamp;

		_Energy = energy;

		_Detector = detector;
	}
	

	
	public int GetTimeStamp()
	{
		return _TimeStamp;
	}

	public int GetEnergy()
	{
		return _Energy;
	}

	public int GetDetector()
	{
		return _Detector;
	}

	
	public void SetTimeStamp(int timeStamp)
	{
		_TimeStamp = timeStamp;
	}
	public void SetEnergy(int energy)
	{
		_Energy = energy;
	}
	public void SetDetector(int detector)
	{
		_Detector = detector;
	}
};

	
