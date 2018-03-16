#include "GetUserInputs.h"
#include "FileToData.h"
#include "GenerateCones.h"
#include "GetCoinc.h"
#include "MultiCheck.h"

#include <fstream>
#include <string>
using namespace std;


bool SettingsFileExists()
{
	ifstream ifile("Settings.txt");
	return (bool)ifile;
}


int main()
{

	cout << "Iterative Conincident pair finder" << endl;

	GetUserInputs GUI(SettingsFileExists());
	vector<string> files = GUI.getFilePaths();
	vector<bool> isScatters = GUI.getIsScatters();
	vector<double> offsets = GUI.getOffsets();
	vector<double> calGrads = GUI.getCalGradients();
	vector<double> calConsts = GUI.getCalConstants();

	double tolerance = GUI.getTolerance() / 2.0;
	bool lookForHeader = GUI.getHeaders();
	string fileName = "";
	bool overrideType = GUI.getOverRide();
	bool multiMode = GUI.getMultiMode();
	bool useLimits = GUI.getEnergyLimits();
	bool usingCompass = GUI.getUsingCompass();

	double upperScatLim = GUI.getEnergyUpperLimits();
	double lowerAbsLim = GUI.getEnergyLowerLimits();

	cout << "Enter the time offset max value" << endl;
	int max;
	cin >> max;

	cout << "Enter the iteration step" << endl;
	int step;
	cin >> step;

	FileToData FTD(usingCompass);
	vector<vector<EventEntry> > events;
	for (size_t i = 0; i < files.size(); i++)
	{
		vector<EventEntry> newEvents = FTD.GetData(files, i, lookForHeader, calConsts[i], calGrads[i], isScatters[i], upperScatLim, lowerAbsLim, useLimits);
		events.push_back(newEvents);
		cout << "File " << i + 1 << " has " << newEvents.size() << " events" << endl;
	}


	


	if (multiMode)
	{
		cout << "Enter the number of zeros before an event set is ignored:" << endl;
		int numZeros;
		cin >> numZeros;
		MultiCheck MC(events, tolerance, offsets, fileName, numZeros);
	}
	else 
	{

		for (int timeOffset = -max; timeOffset <= max; timeOffset += step)
		{
			offsets[1] = timeOffset;
			cout << "Running for time offset " << timeOffset << endl;

			GetCoinc GC(events, tolerance, offsets, isScatters, fileName, usingCompass, GUI.getUseSmartStart(), GUI.getInitEnergy(), GUI.getCheckTolerance(), GUI.getUseESC());
			for (int outter = 0; outter < files.size(); outter++)
			{
				for (int inner = 0; inner < files.size(); inner++)
					if (inner > outter) GC.Find(outter, inner, overrideType);
			}
			cout << "Found " << GC.GetDoubles() << " total coincident pairs." << endl;
		}
	}


	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
