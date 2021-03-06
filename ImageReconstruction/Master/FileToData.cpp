#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "FileToData.h"
#include "DetectorType.h"
#include "EventEntry.h"

using namespace std;

FileToData::FileToData(bool isSimulation) 
{
	_IsSimulation = isSimulation;
}

///The boolean scatter should be set to true if scattering data is required. Otherwise it will return absorbion.
vector<EventEntry> FileToData::GetData(vector<string> files, vector<DetectorType> detectors, bool scatter)
{
	vector<EventEntry> eventList;

	for (int fileIndex = 0; fileIndex < files.size(); fileIndex++)
	{
		if (detectors[fileIndex].getIsScatter() == scatter)
		{
			ifstream infile(files[fileIndex]);

			//Set false if experimental and waits till finds header. True just gets data.
			bool passedHeader = _IsSimulation;

			std::string line;
			while (std::getline(infile, line))
			{
				if (passedHeader)
				{
					//Not a header so split and create entry.
					unsigned int time, energy;

					std::istringstream iss(line);
					iss >> time >> energy;

					EventEntry newEventEntry(time, energy, fileIndex);
					eventList.push_back(newEventEntry);
				}
				else
				{
					//HEADER3 IS THE END OF THE HEADER DATA SO SET PASSED TRUE.
					if (line.find("HEADER3:") == 0) passedHeader = true;
				}
			}
		}

	}

	return eventList;
}
