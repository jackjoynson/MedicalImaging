#ifndef GetCoinc_h
#define GetCoinc_h


#include "DetectorType.h"
#include "EventEntry.h"

#include <string>
#include <vector>
#include <fstream>

class GetCoinc
{
public:
	GetCoinc(vector<vector<EventEntry> > events, double tolerance, double timeOffset, vector<bool> isScatter, string fileName);
	~GetCoinc();
	void Output(int set1, int set2, size_t line1, size_t line2, ofstream& stream);
	void Find(int set1, int set2);
	void UpdateEvents(vector<vector<EventEntry> > events)
	{
		_Events = events;
	}

	int GetDoubles() 
	{
		return _Doubles;
	}

	int GetTriples()
	{
		return _Triples;
	}

private:

	int _Doubles, _Triples;
	vector<vector<EventEntry> > _Events;
	double _Tolerance, _TimeOffset;
	vector<bool> _IsScatters;
	string _FileName;
	bool _IsOutputting;
};

#endif
