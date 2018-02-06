#include "GetCoinc.h"

#include <iostream>

using namespace std;


void GetCoinc::Find(int set1, int set2, int set3)
{

	double originalDoubles = _Doubles;
	double originalTriples = _Triples;

	//Loop each in set1
	for (size_t set1Line = 0; set1Line < _Events[set1].size(); set1Line++)
	{
		unsigned int upperLim = _Events[set1][set1Line].GetTimeStamp() + _Tolerance;
		unsigned int lowerLim = _Events[set1][set1Line].GetTimeStamp() - _Tolerance;

		//Loop set2
		for (size_t set2Line = 0; set2Line < _Events[set2].size(); set2Line++)
		{
			unsigned int set2Time = _Events[set2][set2Line].GetTimeStamp();
			if (set2Time < upperLim && set2Time > lowerLim)
			{
				//HAVE A DOUBLE.
				_Doubles++;

				// Check 3 for triples.
				for (size_t set3Line = 0; set3Line < _Events[set3].size(); set3Line++)
				{
					unsigned int set3Time = _Events[set3][set3Line].GetTimeStamp();
					if (set3Time < upperLim && set3Time > lowerLim)
					{
						//HAVE TRIPLE SO.
						_Triples++;
						_Doubles--;
						break;
					}
				}

				break; //Found a double or triple so break
			}

		}

		cout << "Found " << (_Doubles - originalDoubles) << " doubles between file " << set1+1 << " and file " << set2+1 << endl;
		cout << "Found " << (_Triples - originalTriples) << " triples between files " << set1+1 << ", " << set2+1 << " and " << set3+1 << endl;
		originalDoubles = _Doubles;

		//Loop set 3 for doubles
		for (size_t set3Line = 0; set3Line < _Events[set3].size(); set3Line++)
		{
			unsigned int set3Time = _Events[set3][set3Line].GetTimeStamp();
			if (set3Time < upperLim && set3Time > lowerLim)
			{
				_Doubles++;
				break;
			}
		}

		cout << "Found " << (_Doubles - originalDoubles) << " doubles between file " << set2+1 << " and file " << set3+1 << endl;



	}



}



GetCoinc::GetCoinc(vector<vector<EventEntry> > events, unsigned int tolerance)
{
	_Doubles = 0;
	_Triples = 0;
	_Events = events;
	_Tolerance = tolerance;
}


GetCoinc::~GetCoinc()
{
}
