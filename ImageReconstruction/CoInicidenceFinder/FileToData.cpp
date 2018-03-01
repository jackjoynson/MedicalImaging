#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "FileToData.h"
#include "DetectorType.h"
#include "EventEntry.h"

using namespace std;

FileToData::FileToData() 
{

}

///The boolean scatter should be set to true if scattering data is required. Otherwise it will return absorbion.
vector<EventEntry> FileToData::GetData(vector<string> files, int fileIndex, bool lookForHeader, double constant, double gradient)
{
	vector<EventEntry> eventList;



	ifstream infile(files[fileIndex]);

	bool passedHeader = !lookForHeader;
	std::string line;
	while (std::getline(infile, line))
	{
		if (passedHeader)
		{
			//Not a header so split and create entry.
			unsigned int time;
			double energy;

			std::istringstream iss(line);
			iss >> time >> energy;

			energy = (energy - constant) / gradient;

			EventEntry newEventEntry(time, energy, fileIndex);
			eventList.push_back(newEventEntry);
		}
		else
		{
			//HEADER3 IS THE END OF THE HEADER DATA SO SET PASSED TRUE.
			if (line.find("HEADER3:") == 0) passedHeader = true;
		}
	}


	return eventList;
}
