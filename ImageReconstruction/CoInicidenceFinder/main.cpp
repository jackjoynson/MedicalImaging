#include "GetUserInputs.h"
#include "FileToData.h"
#include "GenerateCones.h"
#include "GetCoinc.h"
#include "MultiCheck.h"

#include <string>
using namespace std;


void FilterUsingLimits(vector<vector<EventEntry> > events, vector<bool> isScat, double scatLims, double absLims)
{
	for (int d = 0; d < events.size(); d++)
	{
		if (isScat[d])
		{
			for (int i = 0; i < events[d].size(); i++)
			{
				if (events[d][i].GetEnergy() > scatLims)
				{
					events[d].erase(events[d].begin() + i);
				}
			}
		}
		else 
		{
			for (int i = 0; i < events[d].size(); i++)
			{
				if (events[d][i].GetEnergy() < absLims)
				{
					events[d].erase(events[d].begin() + i);
				}
			}
		}
		
	}
}



int main()
{

	cout << "Conincident pair finder" << endl;

    GetUserInputs GUI;
	vector<std::string> files = GUI.getFilePaths();
	vector<bool> isScatters = GUI.getIsScatters();
	vector<double> offsets = GUI.getOffsets();
	vector<double> calGrads = GUI.getCalGradients();
	vector<double> calConsts = GUI.getCalConstants();


	cout << "Enter the time tolerance window size:" << endl;
	double tolerance;
	cin >> tolerance;
	tolerance = tolerance / 2.0;

	cout << "Enter 1 if the data files have headers: " << endl;
	int tempHeaders;
	cin >> tempHeaders;
	bool lookForHeader = (tempHeaders == 1) ? true : false;

	cout << "Enter a valid file name to output to:" << endl;
	string fileName;
	cin >> fileName;

	cout << "Enter 1 to override checking only scatter with absorber" << endl;
	int tempOverride;
	cin >> tempOverride;
	bool overrideType = (tempOverride == 1) ? true : false;

	cout << "Enter 1 to only check for coincidence events in all files:" << endl;
	int tempMulti;
	cin >> tempMulti;
	bool multi = (tempMulti == 1) ? true : false;

	cout << "Enter 1 to add limits to scatter and absorption energy:" << endl;
	int tempLimits;
	cin >> tempLimits;
	bool useLimts = (tempLimits == 1) ? true : false;

	double upperScatLim = 0.0;
	double lowerAbsLim = 0.0;
	if (useLimts)
	{
		cout << "Enter the upper scattering energy limit:" << endl;
		cin >> upperScatLim;
		cout << "Enter the lower absorption energy limit:" << endl;
		cin >> lowerAbsLim;
	}





	FileToData FTD;
	vector<vector<EventEntry> > events;
	for (size_t i = 0; i < files.size(); i++)
	{
		vector<EventEntry> newEvents = FTD.GetData(files, i, lookForHeader, calConsts[i], calGrads[i]);
		events.push_back(newEvents);
		cout << "File " << i + 1 << " has " << newEvents.size() << " events" << endl;
	}


	if (useLimts) FilterUsingLimits(events, isScatters, upperScatLim, lowerAbsLim);




	if (multi)
	{
		MultiCheck MC(events, tolerance, offsets, fileName);
	}
	else 
	{
		GetCoinc GC(events, tolerance, offsets, isScatters, fileName);
		for (int outter = 0; outter < files.size(); outter++)
		{
			for (int inner = 0; inner < files.size(); inner++)
				if (inner > outter) GC.Find(outter, inner, overrideType);
		}
		cout << "Found " << GC.GetDoubles() << " total coincident pairs." << endl;
	}


	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
