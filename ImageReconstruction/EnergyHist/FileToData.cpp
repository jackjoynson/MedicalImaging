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

vector<EventEntry> GetTabData(vector<string> files, int fileIndex, bool lookForHeader)
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
			long long time, energy;

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


	return eventList;
}


vector<EventEntry> GetCSVData(vector<string> files, int fileIndex, bool lookForHeader)
{
	vector<EventEntry> eventList;

	ifstream infile(files[fileIndex]);
	bool passedHeader = !lookForHeader;
	std::string line;
	while (std::getline(infile, line))
	{
		if (passedHeader)
		{
			std::string split;
			unsigned int convertedTime, energy;
			long long time;

			std::istringstream ss(line);
			std::getline(ss, split,';');		
			time = stoll(split);
			convertedTime = time / 10000;

			std::getline(ss, split, ';');
			energy = stoul(split);


			EventEntry newEventEntry(convertedTime, energy, fileIndex);
			eventList.push_back(newEventEntry);
		}
		else
		{
			//HEADER3 IS THE END OF THE HEADER DATA SO SET PASSED TRUE.
			if (line.find("TIMETAG;ENERGY;FLAGS") == 0) passedHeader = true;
		}
	}


	return eventList;
}


vector<EventEntry> FileToData::GetData(vector<string> files, int fileIndex, bool lookForHeader, bool tabDelim)
{
	if(tabDelim) return GetTabData(files, fileIndex, lookForHeader);
	else return GetCSVData(files, fileIndex, lookForHeader);
}

