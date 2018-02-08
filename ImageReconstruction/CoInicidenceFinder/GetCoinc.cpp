#include "GetCoinc.h"

#include <iostream>

using namespace std;


void GetCoinc::Find(int set1, int set2)
{

	int doubles12 = 0, doubles13 = 0, doubles23 = 0;
	int triples = 0;

	//Loop each in set1
	for (size_t set1Line = 0; set1Line < _Events[set1].size(); set1Line++)
	{
		double upperLim = _Events[set1][set1Line].GetTimeStamp() + _Tolerance;
		double lowerLim = _Events[set1][set1Line].GetTimeStamp() - _Tolerance;

		//Loop set2
		for (size_t set2Line = 0; set2Line < _Events[set2].size(); set2Line++)
		{
			//unsigned int upperLimSET2 = _Events[set2][set2Line].GetTimeStamp() + _Tolerance;
			//unsigned int lowerLimSET2 = _Events[set2][set2Line].GetTimeStamp() - _Tolerance;


			double set2Time = _Events[set2][set2Line].GetTimeStamp() + _TimeOffset;
			if (set2Time < upperLim && set2Time > lowerLim)
			{
				//HAVE A DOUBLE.
				doubles12++;

				//// Check 3 for triples.
				//for (size_t set3Line = 0; set3Line < _Events[set3].size(); set3Line++)
				//{
				//	unsigned int set3Time = _Events[set3][set3Line].GetTimeStamp();
				//	if (set3Time < upperLim && set3Time > lowerLim)
				//	{
				//		//HAVE TRIPLE SO.
				//		triples++;
				//		doubles12--;
				//		break;
				//	}
				//}

				break; //Found a double or triple so break
			}

			////2>3 doubles
			//for (size_t set3Line = 0; set3Line < _Events[set3].size(); set3Line++)
			//{
			//	unsigned int set3Time = _Events[set3][set3Line].GetTimeStamp();
			//	if (set3Time < upperLimSET2 && set3Time > lowerLimSET2)
			//	{
			//		doubles23++;
			//		break;
			//	}
			//}



		}


		////Loop set 3 for doubles
		//for (size_t set3Line = 0; set3Line < _Events[set3].size(); set3Line++)
		//{
		//	unsigned int set3Time = _Events[set3][set3Line].GetTimeStamp();
		//	if (set3Time < upperLim && set3Time > lowerLim)
		//	{
		//		doubles13++;
		//		break;
		//	}
		//}
	}

	std::cout << "Found " << doubles12 << " doubles between files " << set1 + 1 << " and " << set2 + 1 << endl
		//<< "Found " << doubles13 << " doubles between files " << set1 + 1 << " and " << set3 + 1 << endl
		//<< "Found " << doubles23 << " doubles between files " << set2 + 1 << " and " << set3 + 1 << endl
		//<< "Found " << triples << " triples between files " << set1 + 1 << ", " << set2 + 1 << " and " << set3 + 1 << endl
		;

	_Doubles += doubles12 + doubles13 + doubles23;
	_Triples += triples;
}



GetCoinc::GetCoinc(vector<vector<EventEntry> > events, double tolerance, double timeOffset)
{
	_Doubles = 0;
	_Triples = 0;
	_Events = events;
	_Tolerance = tolerance;
	_TimeOffset = timeOffset;
}


GetCoinc::~GetCoinc()
{
}
