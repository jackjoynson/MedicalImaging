#ifndef GetCoinc_h
#define GetCoinc_h


#include "DetectorType.h"
#include "EventEntry.h"

#include <string>
#include <vector>

class GetCoinc
{
public:
	GetCoinc(vector<vector<EventEntry> > events, unsigned int tolerance);
	~GetCoinc();
	void Find(int set1, int set2, int set3);

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
	unsigned int _Tolerance;
};

#endif
