#include "GetCoinc.h"

#include <iostream>
#include <fstream>

using namespace std;


void GetCoinc::Find(int set1, int set2, bool overrideType)
{
	if (_IsScatters[set1] != _IsScatters[set2] || overrideType)
	{
		ofstream saveFile(_FileName,std::ios_base::app);

		int doubles = 0;

		//Loop each in set1
		for (size_t set1Line = 0; set1Line < _Events[set1].size(); set1Line++)
		{
			double time = _Events[set1][set1Line].GetTimeStamp() + _Offsets[set1];
			double upperLim = time + _Tolerance;
			double lowerLim = time - _Tolerance;

			//double breakLim = upperLim + 10000;

			//Loop set2
			for (size_t set2Line = 0; set2Line < _Events[set2].size(); set2Line++)
			{

				double set2Time = _Events[set2][set2Line].GetTimeStamp() + _Offsets[set2];
				if (set2Time > lowerLim)
				{
					if (set2Time < upperLim)
					{
						doubles++;
						Output(set1, set2, _Events[set1][set1Line].GetEnergy(), _Events[set2][set2Line].GetEnergy(), time, set2Time, saveFile);
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



GetCoinc::GetCoinc(vector<vector<EventEntry> > events, double tolerance, vector<double> offsets, vector<bool> isScatters, string fileName)
{
	_Doubles = 0;
	_Triples = 0;
	_Events = events;
	_Tolerance = tolerance;
	_Offsets = offsets;
	_IsScatters = isScatters;
	_IsOutputting = (fileName.length() > 0) ? true : false;
	_FileName = fileName;
}


GetCoinc::~GetCoinc()
{	
}


void GetCoinc::Output(int set1, int set2, double energy1, double energy2, double time1, double time2, ofstream& stream)
{
	if (_IsOutputting)
	{
		stream << set1 + 1 << ' ' 
			<< set2 + 1 << ' ' 
			<< energy1 << ' ' 
			<< energy2 << ' '
			<< time1 << ' '
			<< time2 << ' '	<< '\n';
	}
}

