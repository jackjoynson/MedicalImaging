#include <vector>

#include "GenerateCones.h"
#include "EventEntry.h"
#include "Cone.h"

using namespace std;

GenerateCones::GenerateCones()
{}













vector<Cone> GenerateCones::GetCones(vector<EventEntry> scatteringEvents, vector<EventEntry> absorpionEvents, vector<DetectorType> detectors, int tolerance)
{
	vector<Cone> cones;

	//Finds sets of coincident events and calculates cones for each

	//i is the scattering event list index. Loop through each scattering event. 
	for (int i = 0; i < scatteringEvents.size(); i++)
	{

		//Find absorpion event timestamp that matches scatter event timestamp.
		for (int j = 0; j < absorpionEvents.size(); j++)
		{
			double upperLim = scatteringEvents[i].GetTimeStamp() + tolerance;
			double lowerLim = scatteringEvents[i].GetTimeStamp() - tolerance;

			if (absorpionEvents[j].GetTimeStamp() < upperLim && absorpionEvents[j].GetTimeStamp() > lowerLim)
			{
				
				cones.push_back(newCone);

				break; //Break to new absorpion event.
			}
		}

	}


	return cones;
}