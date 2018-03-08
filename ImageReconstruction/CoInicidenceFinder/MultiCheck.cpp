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
			}
		}
		
		//Did not find so clear
		_Energies.clear();


	}
	else 
	{
		int zerosFound = 0; 
		for (int i = 0; i < _Energies.size(); i++)
		{
			if (_Energies[i] == 0)
			{
				zerosFound++;
			}
		}

		if (zerosFound <= _NumZeros)
		{
			_AllFileCoinc++;
			stream << checkTime;

			for (int i = 0; i < _Energies.size(); i++)
				stream << ' ' << _Energies[i];

			stream << '\n';
		}
		_Energies.clear();
	}
}






MultiCheck::MultiCheck(vector<vector<EventEntry> > events, double tolerance, vector<double> offsets, string fileName, int numZeros)
{

	_Events = events;
	_Tolerance = tolerance;
	_Offsets = offsets;
	_FileName = fileName;
	_NumZeros = numZeros;

	ofstream saveFile(_FileName, std::ios_base::app);

	saveFile << "Time Energies..." << '\n';

	cout << "Searching..." << endl;
	Find(0.0, 0, true, saveFile);

	cout << "Found " << _AllFileCoinc << " events which occured in all detectors..." << endl;
}


MultiCheck::~MultiCheck()
{	
}


