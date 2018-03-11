#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>

#include "ReadCCData.h"
#include "EventEntry.h"

using namespace std;

ReadCoincData::ReadCoincData(){}



vector<EventEntry> ReadCoincData::GetEvents(string file,vector<DetectorType> detectors)
{
	//READ EACH LINE. Create scatter and absorb event

    vector<EventEntry> Events;
	ifstream infile(file);


	std::string line;
	while (std::getline(infile, line))
	{
			//Not a header so split and create entry.
			double time1, time2, energy1, energy2;
			int num1, num2;

			std::istringstream iss(line);
			iss >> num1 >> num2 >> energy1 >> energy2 >> time1 >> time2;

            if(detectors[num1].getIsScatter())
            {
            EventEntry event(time1,energy1,energy1+energy2,num1);
            Events.push_back(event);
            }
            else{
                EventEntry event(time2,energy2,energy1+energy2,num2);
                Events.push_back(event);
            }


	}



    return Events;
}
