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

	cout << "Enter a valid file name to output to:" << endl;
	string fileName;
	cin >> fileName;


	cout << "Enter a time offset to be applied to file 2 (For random event checking):" << endl;
	double timeOffset;
	cin >> timeOffset;


	FileToData FTD;

	vector<vector<EventEntry> > events;
	for (size_t i = 0; i < files.size(); i++)
	{
		vector<EventEntry> newEvents = FTD.GetData(files, i);
		events.push_back(newEvents);
		cout << "File " << i + 1 << " has " << newEvents.size() << " events" << endl;
	}


	GetCoinc GC(events, tolerance, timeOffset, isScatters, fileName);

	if (files.size() == 2)
	{
		//files.push_back("fake");
		//vector<EventEntry> events;
		//scatteringEvents.push_back(events);

		//GC.UpdateEvents(scatteringEvents);
		GC.Find(0, 1);
	}
	else if(files.size() == 3)
	{
		GC.Find(0, 1);
		GC.Find(0, 2);
		GC.Find(1, 2);

	}
	else if (files.size() == 4)
	{
		GC.Find(0, 1);
		GC.Find(0, 2);
		GC.Find(0, 3);
		GC.Find(1, 2);
		GC.Find(1, 3);
		GC.Find(2, 3);
	}
	else {
		cout << "INVALID NUMBER OF FILES SELECTED..." << endl;
	}




	cout << "Found " << GC.GetDoubles() << " total coincident pairs." << endl
		;



	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
