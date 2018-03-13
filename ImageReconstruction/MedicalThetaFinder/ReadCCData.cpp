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

    _InvalidEnergyCounter = 0;

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

            double totalEnergy = energy1+energy2;
            if(totalEnergy == 0.662){

            if(detectors[num1].getIsScatter())
            {
            EventEntry event(time1,energy1,totalEnergy,num1);
            Events.push_back(event);
            }
            else{
                EventEntry event(time2,energy2,totalEnergy,num2);
                Events.push_back(event);
            }

            }
            else{
            _InvalidEnergyCounter++;
            }

	}



    return Events;
}
