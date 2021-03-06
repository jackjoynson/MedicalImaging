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
	GetCoinc(vector<vector<EventEntry> > events, double tolerance, vector<double> offset, vector<bool> isScatter, string fileName, bool useUpperCutOff, bool useSmartStart, double initialEnergy, double checkTolerance, bool useCheckSum);
	~GetCoinc();
	void Output(int set1, int set2, double energy1, double energy2, double time1, double time2, ofstream& stream);
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

	bool EnergiesValid(int set1, size_t set1Line, int set2, size_t set2Line);

	int _Doubles, _Triples;
	vector<vector<EventEntry> > _Events;
	double _Tolerance;
	vector<double> _Offsets;
	vector<bool> _IsScatters;
	string _FileName;
	bool _IsOutputting, _UseUpperCutOff, _UseSmartStart;
	double _InitialEnergy, _CheckSumTolerance;
	bool _UseCheckSum;
};

#endif
