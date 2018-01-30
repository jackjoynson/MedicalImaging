#include "GetUserInputs.h"
#include "FileToData.h"
#include "GenerateCones.h"
#include "GetCoinc.h"

#include <string>

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
	}


	GetCoinc GC(scatteringEvents, tolerance);
	GC.Find(0,1,2);
	GC.Find(0,1,3);
	GC.Find(0,2,3);
	GC.Find(1,2,3);



	cout << "Found " << GC.GetDoubles() << " coincident pairs." << endl
		<< "Found " << GC.GetTriples() << " coincident triplets." << endl;



	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
