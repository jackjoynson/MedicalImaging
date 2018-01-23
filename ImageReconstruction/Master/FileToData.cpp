#include <vector>
#include <string>
#include <fstream>

#include "FileToData.h"
#include "DetectorType.h"
#include "EventEntry.h"

using namespace std;

FileToData::FileToData() 
{

}


vector<EventEntry> FileToData::GetData(vector<string> files, vector<DetectorType> detectors, bool scatter)
{
	vector<EventEntry> eventList;

	for (int fileIndex = 0; fileIndex < files.size(); fileIndex++)
	{
		if (detectors[fileIndex].getIsScatter() == scatter)
		{
			ifstream infile(files[fileIndex]);
			int time, energy;
			while (infile >> time >> energy)
			{
				EventEntry newEventEntry(time, energy, fileIndex);
				eventList.push_back(newEventEntry);
			}
		}

	}

	return eventList;
}
