#include "MultiCheck.h"

#include <iostream>
#include <fstream>

using namespace std;


void MultiCheck::Find(double checkTime, int setNum, bool first, ofstream& stream)
{
	if (setNum < _Events.size())
	{
		double upperLim = checkTime + _Tolerance;
		double lowerLim = checkTime - _Tolerance;


		//Loop set2
		for (size_t line = 0; line < _Events[setNum].size(); line++)
		{

			double time = _Events[setNum][line].GetTimeStamp() + _Offsets[setNum];
			if ((time > lowerLim && time < upperLim) || first)
			{
				_Energies.push_back(_Events[setNum][line].GetEnergy());
				Find(time, setNum + 1, false, stream);
				//break;
			}
		}
	}
	else 
	{
		_AllFileCoinc++;
		stream << checkTime;

		for (int i = 1; i < _Energies.size(); i++)		
			stream << '\t' << _Energies[i];
		
		stream << '\n';
		_Energies.clear();
	}
}






MultiCheck::MultiCheck(vector<vector<EventEntry> > events, double tolerance, vector<double> offsets, string fileName)
{

	_Events = events;
	_Tolerance = tolerance;
	_Offsets = offsets;
	_FileName = fileName;

	ofstream saveFile(_FileName, std::ios_base::app);

	cout << "Searching..." << endl;
	Find(0.0, 0, true, saveFile);

	cout << "Found " << _AllFileCoinc << " events which occured in all detectors..." << endl;
}


MultiCheck::~MultiCheck()
{	
}


