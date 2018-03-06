#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>

#include "ReadCCData.h"
#include "EventEntry.h"
#include "Cone.h"
#include "GenerateCone.h"

using namespace std;

ReadCoincData::ReadCoincData(){}



vector<Cone> ReadCoincData::GetCones(string file, vector<DetectorType> detectors, double sourceEnergy, double imageHeight, bool hasHeaders)
{
	//READ EACH LINE. Create scatter and absorb event

	vector<Cone> cones;
	ifstream infile(file);

	//Set false if experimental and waits till finds header. True just gets data.
	bool passedHeader = !hasHeaders;

	std::string line;
	while (std::getline(infile, line))
	{
		if (passedHeader)
		{
			//Not a header so split and create entry.
			double time1, time2, energy1, energy2;
			int num1, num2;

			std::istringstream iss(line);
			iss >> num1 >> num2 >> energy1 >> energy2 >> time1 >> time2;

			EventEntry event1(time1, energy1, num1);
			EventEntry event2(time2, energy2, num2);

			if (detectors[num1].getIsScatter())
			{
				Cone newCone = GenerateCone::CalculateCone(event1, event2, detectors, sourceEnergy, imageHeight);
				cones.push_back(newCone);
			}
			else 
			{
				//Flipped order of events.
				Cone newCone = GenerateCone::CalculateCone(event2, event1, detectors, sourceEnergy, imageHeight);
				cones.push_back(newCone);
			}

		}
		else
		{
			//HEADER3 IS THE END OF THE HEADER DATA SO SET PASSED TRUE.
			if (line.find("HEADER3:") == 0) passedHeader = true;
		}
	}



	return cones;
}
