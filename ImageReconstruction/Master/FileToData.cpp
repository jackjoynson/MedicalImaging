#include <vector>
#include <string>
#include <fstream>

#include "FileToData.h"
#include "Detector.h"
#include "EventEntry.h"

using namespace std;

FileToData::GetData(vector<string> files, vector<Detector> detectors, bool scatter)
{
	vector<EventEntry> eventList;

	for (int fileIndex = 0; fileIndex < files.size(); fileIndex++)
	{
		if (detectors[fileIndex] == scatter)
		{
			ifstream infile(files[fileIndex]);
			int time, energy;
			while (infile >> time >> energy)
			{
				EventEntry newEventEntry(time, energy);
				eventList.push_back(newEventEntry);
			}
		}

	}

	return eventList;
}
