#include "GetUserInputs.h"
#include "FileToData.h"
#include "GenerateCones.h"
#include "GetCoinc.h"

#include <string>
using namespace std;

using namespace std;



int main()
{

	cout << "Conincident pair/triplet finder" << endl;

    GetUserInputs GUI;
	vector<std::string> files = GUI.getFilePaths();


	cout << "Enter the time tolerance:" << endl;
	unsigned int tolerance;
	cin >> tolerance;

	FileToData FTD;

	vector<vector<EventEntry> > scatteringEvents;
	for (size_t i = 0; i < files.size(); i++)
	{
		vector<EventEntry> events = FTD.GetData(files, true, i);
		scatteringEvents.push_back(events);
		cout << "File " << i + 1 << " has " << events.size() << " events" << endl;
	}


	GetCoinc GC(scatteringEvents, tolerance);

	if (files.size() == 2)
	{
		files.push_back("fake");
		vector<EventEntry> events;
		scatteringEvents.push_back(events);

		GC.UpdateEvents(scatteringEvents);
		GC.Find(0, 1, 2);
	}
	else if(files.size() == 3)
	{
		GC.Find(0, 1, 2);
	}
	else if (files.size() == 4)
	{
		GC.Find(0, 1, 2);
		GC.Find(0, 1, 3);
		GC.Find(0, 2, 3);
		GC.Find(1, 2, 3);
	}
	else {
		cout << "INVALID NUMBER OF FILES SELECTED..." << endl;
	}




	cout << "Found " << GC.GetDoubles() << " coincident pairs." << endl
		<< "Found " << GC.GetTriples() << " coincident triplets." << endl;



	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
