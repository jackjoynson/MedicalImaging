#include <vector>
#include <cmath>

#include "FilterEvents.h"
#include "EventEntry.h"
#include "Cone.h"
#include "GenerateCone.h"

using namespace std;

FilterEvents::FilterEvents()
{}














vector<Cone> FilterEvents::GetCones(vector<EventEntry> scatteringEvents, vector<EventEntry> absorpionEvents, vector<DetectorType> detectors, double sourceEnergy, double imageHeight, int tolerance)
{
	vector<Cone> cones;

	//Finds sets of coincident events and calculates cones for each

	//i is the scattering event list index. Loop through each scattering event. 
	for (int i = 0; i < scatteringEvents.size(); i++)
	{

		//Find absorpion event timestamp that matches scatter event timestamp.
		for (int j = 0; j < absorpionEvents.size(); j++)
		{

			int upperLimit = absorpionEvents[j].GetTimeStamp() + tolerance;
			int lowerLimit = absorpionEvents[j].GetTimeStamp() - tolerance;
			
			if (scatteringEvents[i].GetTimeStamp() <= upperLimit && scatteringEvents[i].GetTimeStamp() >= lowerLimit)
			{
				//We have a pair so calculate the cone. 
				Cone newCone = GenerateCone::CalculateCone(scatteringEvents[i], absorpionEvents[j], detectors, sourceEnergy, imageHeight);
				cones.push_back(newCone);

				break; //Break to new absorpion event.
			}
		}

	}


	return cones;
}
