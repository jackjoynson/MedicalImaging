#include "GetUserInputs.h"
#include "FileToData.h"
#include "GenerateCones.h"

#include <string>
using namespace std;

int main()
{

	cout << "Conincident pair/triplet finder" << endl;

    GetUserInputs GUI;
	vector<std::string> files = GUI.getFilePaths();


	cout << "Enter the time tolerance:" << endl;
	unsigned int tolerance;
	cin >> tolerance;

	FileToData FTD;
	vector<EventEntry> scatteringEvents = FTD.GetData(files, true);


	int numberDoubles = 0;
	int numberTriples = 0;

	//i is the scattering event list index. Loop through each scattering event. 
	for (size_t i = 0; i < scatteringEvents.size(); i++)
	{
		bool foundOne = false;

		//Find absorpion event timestamp that matches scatter event timestamp.
		for (size_t j = 0; j < scatteringEvents.size(); j++)
		{
			if (i != j)
			{
				unsigned int upperLim = scatteringEvents[i].GetTimeStamp() + tolerance;
				unsigned int lowerLim = scatteringEvents[i].GetTimeStamp() - tolerance;

				if (scatteringEvents[j].GetTimeStamp() < upperLim && scatteringEvents[j].GetTimeStamp() > lowerLim)
				{
					if (foundOne)
					{
						numberTriples++;
					}
					else 
					{
						foundOne = true;
						numberDoubles++;
					}


				}
			}
		}

	}


	cout << "Found " << numberDoubles << " coincident pairs." << endl
		<< "Found " << numberTriples << " coincident triplets." << endl;



	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
