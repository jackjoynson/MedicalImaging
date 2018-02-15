#include "GetUserInputs.h"
#include "FileToData.h"
#include "GenerateCones.h"
#include "GetCoinc.h"

#include <string>
using namespace std;




int main()
{

	cout << "Conincident pair finder" << endl;

    GetUserInputs GUI;
	vector<std::string> files = GUI.getFilePaths();
	vector<bool> isScatters = GUI.getIsScatters();


	cout << "Enter the time tolerance window size:" << endl;
	double tolerance;
	cin >> tolerance;
	tolerance = tolerance / 2.0;

	cout << "Enter a time offset to be applied to file 2 (For random event checking):" << endl;
	double timeOffset;
	cin >> timeOffset;

	cout << "Enter 1 if the data files have headers: " << endl;
	int tempHeaders;
	cin >> tempHeaders;
	bool lookForHeader = (tempHeaders == 1) ? true : false;

	cout << "Enter a valid file name to output to:" << endl;
	string fileName;
	cin >> fileName;


	FileToData FTD;

	vector<vector<EventEntry> > events;
	for (size_t i = 0; i < files.size(); i++)
	{
		vector<EventEntry> newEvents = FTD.GetData(files, i, lookForHeader);
		events.push_back(newEvents);
		cout << "File " << i + 1 << " has " << newEvents.size() << " events" << endl;
	}


	GetCoinc GC(events, tolerance, timeOffset, isScatters, fileName);

	for (int outter = 0; outter < files.size(); outter++)
	{
		for (int inner = 0; inner < files.size(); inner++)
			if (inner > outter) GC.Find(outter, inner);
	}
	




	cout << "Found " << GC.GetDoubles() << " total coincident pairs." << endl
		;



	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
