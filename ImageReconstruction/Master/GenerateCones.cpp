#include <vector>

#include "GenerateCones.h"
#include "EventEntry.h"
#include "Cone.h"

using namespace std;

GenerateCones::GenerateCones()
{}


Cone CalculateCone(EventEntry scatterEvent, EventEntry absorbEvent, vector<DetectorType> detectors)
{

}

vector<Cone> GenerateCones::GetCones(vector<EventEntry> scatteringEvents, vector<EventEntry> absorpionEvents, vector<DetectorType> detectors)
{
	vector<Cone> cones;

	//Finds sets of coincident events and calculates cones for each

	//i is the scattering event list index. Loop through each scattering event. 
	for (int i = 0; i < scatteringEvents.size(); i++)
	{

		//Find absorpion event timestamp that matches scatter event timestamp.
		for (int j = 0; j < absorpionEvents.size(); j++)
		{
			if (absorpionEvents[j].GetTimeStamp() == scatteringEvents[i].GetTimeStamp())
			{
				//We have a pair so calculate the cone. 
				Cone newCone = CalculateCone(scatteringEvents[i], absorpionEvents[j], detectors);
				cones.push_back(newCone);

				break; //Break to new absorpion event.
			}
		}

	}


	return cones;
}