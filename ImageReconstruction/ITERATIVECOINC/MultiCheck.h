#ifndef MultiCheck_h
#define MultiCheck_h


#include "DetectorType.h"
#include "EventEntry.h"

#include <string>
#include <vector>
#include <fstream>

class MultiCheck
{
public:
	MultiCheck(vector<vector<EventEntry> > events, double tolerance, vector<double> offset, string fileName, int numZeros);
	~MultiCheck();
	void Find(double checkTime, int setNum, bool first, ofstream& stream);

private:

	int _AllFileCoinc, _NumZeros;
	vector<int> _Energies;
	vector<vector<EventEntry> > _Events;
	double _Tolerance;
	string _FileName;
	vector<double> _Offsets;
};

#endif
