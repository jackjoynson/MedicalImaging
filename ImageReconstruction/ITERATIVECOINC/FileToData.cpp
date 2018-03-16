#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "FileToData.h"
#include "DetectorType.h"
#include "EventEntry.h"

using namespace std;

FileToData::FileToData(bool usingCompass) 
{
	_UsingCompass = usingCompass;
}


vector<EventEntry> GetDataFromMCS(vector<string> files, int fileIndex, bool lookForHeader, double constant, double gradient, bool isScat, double scatLim, double absLim, bool useLims)
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
			double time;
			double energy;

			std::istringstream iss(line);
			iss >> time >> energy;

			energy = (energy - constant) / gradient;
			EventEntry newEventEntry(time, energy, fileIndex);

			if (useLims)
			{
				if (isScat)
				{
					if (energy < scatLim) eventList.push_back(newEventEntry);
				}
				else
				{
					if (energy > absLim) eventList.push_back(newEventEntry);
				}
			}
			else
			{
				eventList.push_back(newEventEntry);
			}

		}
		else
		{
			//HEADER3 IS THE END OF THE HEADER DATA SO SET PASSED TRUE.
			if (line.find("HEADER3:") == 0) passedHeader = true;
		}
	}
	return eventList;
}

vector<EventEntry> GetDataFromCompass(vector<string> files, int fileIndex, bool lookForHeader, double constant, double gradient, bool isScat, double scatLim, double absLim, bool useLims)
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
			double time;
			double energy;
			string flag;
			string split;

			std::istringstream iss(line);
			std::getline(iss, split, ';');
			time = stod(split);

			std::getline(iss, split, ';');
			energy = stod(split);


			energy = (energy - constant) / gradient;
			EventEntry newEventEntry(time, energy, fileIndex);

			if (useLims)
			{
				if (isScat)
				{
					if (energy < scatLim) eventList.push_back(newEventEntry);
				}
				else
				{
					if (energy > absLim) eventList.push_back(newEventEntry);
				}
			}
			else
			{
				eventList.push_back(newEventEntry);
			}

		}
		else
		{
			//Only one line
			passedHeader = true;
		}
	}
	return eventList;
}



///The boolean scatter should be set to true if scattering data is required. Otherwise it will return absorbion.
vector<EventEntry> FileToData::GetData(vector<string> files, int fileIndex, bool lookForHeader, double constant, double gradient, bool isScat, double scatLim, double absLim, bool useLims)
{
	if (_UsingCompass)
	{
		return GetDataFromCompass(files, fileIndex, lookForHeader, constant, gradient, isScat, scatLim, absLim, useLims);
	}
	else 
	{
		return GetDataFromMCS(files, fileIndex, lookForHeader, constant, gradient, isScat, scatLim, absLim, useLims);
	}
}


