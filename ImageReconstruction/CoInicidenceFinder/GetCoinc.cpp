#include "GetCoinc.h"

#include <iostream>
#include <fstream>

using namespace std;


void GetCoinc::Find(int set1, int set2)
{
	if (_IsScatters[set1] != _IsScatters[set2])
	{
		ofstream saveFile(_FileName,std::ios_base::app);

		int doubles = 0;

		//Loop each in set1
		for (size_t set1Line = 0; set1Line < _Events[set1].size(); set1Line++)
		{
			double upperLim = _Events[set1][set1Line].GetTimeStamp() + _Tolerance;
			double lowerLim = _Events[set1][set1Line].GetTimeStamp() - _Tolerance;

			//double breakLim = upperLim + 10000;

			//Loop set2
			for (size_t set2Line = 0; set2Line < _Events[set2].size(); set2Line++)
			{

				double set2Time = _Events[set2][set2Line].GetTimeStamp() + _TimeOffset;
				if (set2Time > lowerLim)
				{
					if (set2Time < upperLim)
					{
						doubles++;
						Output(set1, set2, set1Line, set2Line, saveFile);
						break;
					}
					//else if (set2Time > breakLim)
					//{
					//	//above the limit
					//	break;
					//}
				}
			}
		}

		std::cout << "Found " << doubles << " doubles between files " << set1 + 1 << " and " << set2 + 1 << endl;
		_Doubles += doubles;
	}
	else
	{
		std::cout << "Did not check file " << set1 + 1 << " with " << set2 + 1 << " as they are the same type..." << endl;
	}
}



GetCoinc::GetCoinc(vector<vector<EventEntry> > events, double tolerance, double timeOffset, vector<bool> isScatters, string fileName)
{
	_Doubles = 0;
	_Triples = 0;
	_Events = events;
	_Tolerance = tolerance;
	_TimeOffset = timeOffset;
	_IsScatters = isScatters;
	_IsOutputting = (fileName.length() > 0) ? true : false;
	_FileName = fileName;
}


GetCoinc::~GetCoinc()
{	
}


void GetCoinc::Output(int set1, int set2, size_t line1, size_t line2, ofstream& stream)
{
	if (_IsOutputting)
	{
		stream << set1 + 1 << '\t' << set2 + 1 << '\t' 
			<< _Events[set1][line1].GetEnergy() << '\t' 
			<< _Events[set2][line2].GetEnergy() << '\t'
			<< _Events[set1][line1].GetTimeStamp() << '\t'
			<< _Events[set2][line2].GetTimeStamp() << '\t'
			<< '\n';
	}
}

