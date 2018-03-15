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
	GetCoinc(vector<vector<EventEntry> > events, double tolerance, vector<double> offset, vector<bool> isScatter, string fileName);
	~GetCoinc();
	void Output(int set1, int set2, int set1Line, int set2Line, double time1, double time2, ofstream& stream);
	void Find(int set1, int set2, bool overrideType);
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
	double _Tolerance;
	vector<double> _Offsets;
	vector<bool> _IsScatters;
	string _FileName;
	bool _IsOutputting;
};

#endif
