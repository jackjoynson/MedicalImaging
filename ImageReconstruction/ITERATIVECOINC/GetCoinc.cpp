#include "GetCoinc.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void GetCoinc::Find(int set1, int set2, bool overrideType)
{
	if (_IsScatters[set1] != _IsScatters[set2] || overrideType)
	{
		ofstream saveFile(_FileName,std::ios_base::app);
		saveFile << setprecision(12);

		int doubles = 0;
		size_t startPoint = 0;

		//Loop each in set1
		for (size_t set1Line = 0; set1Line < _Events[set1].size(); set1Line++)
		{
			double time = _Events[set1][set1Line].GetTimeStamp() + _Offsets[set1];
			double upperLim = time + _Tolerance;
			double lowerLim = time - _Tolerance;


			//Loop set2
			for (size_t set2Line = startPoint; set2Line < _Events[set2].size(); set2Line++)
			{

				double set2Time = _Events[set2][set2Line].GetTimeStamp() + _Offsets[set2];
				if (set2Time > lowerLim)
				{
					if (set2Time < upperLim)
					{

						if (EnergiesValid(set1, set1Line, set2, set2Line))
						{
							
							doubles++;
							//Output(set1, set2, _Events[set1][set1Line].GetEnergy(), _Events[set2][set2Line].GetEnergy(), time, set2Time, saveFile);
						}

						if (_UseSmartStart) startPoint = set2Line;
						break;
					}
					else if (_UseUpperCutOff && set2Time > upperLim)
					{
						break;
					}
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


bool GetCoinc::EnergiesValid(int set1, size_t set1Line, int set2, size_t set2Line)
{
	if (_UseCheckSum)
	{
		double energySum = _Events[set1][set1Line].GetEnergy() + _Events[set2][set2Line].GetEnergy();

		return (energySum < _InitialEnergy + _CheckSumTolerance && energySum > _InitialEnergy - _CheckSumTolerance);
	}
	return true;
}

GetCoinc::GetCoinc(vector<vector<EventEntry> > events, double tolerance, vector<double> offsets, vector<bool> isScatters, string fileName, bool useUpperCutOff, bool useSmartStart, double initialEnergy, double checkTolerance, bool useCheckSum)
{
	_Doubles = 0;
	_Triples = 0;
	_Events = events;
	_Tolerance = tolerance;
	_Offsets = offsets;
	_IsScatters = isScatters;
	_IsOutputting = (fileName.length() > 0) ? true : false;
	_FileName = fileName;
	_UseUpperCutOff = useUpperCutOff;
	_UseSmartStart = useSmartStart;
	_UseCheckSum = useCheckSum;
	_InitialEnergy = initialEnergy;
	_CheckSumTolerance = checkTolerance;
}


GetCoinc::~GetCoinc()
{	
}


void GetCoinc::Output(int set1, int set2, double energy1, double energy2, double time1, double time2, ofstream& stream)
{
	if (_IsOutputting)
	{
		stream << set1 << ' ' 
			<< set2 << ' ' 
			<< energy1 << ' ' 
			<< energy2 << ' '
			<< time1 << ' '
			<< time2 << ' '	<< '\n';
	}
}

