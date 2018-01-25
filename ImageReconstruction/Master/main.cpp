#include "GetUserInputs.h"
#include "FileToData.h"
#include "GenerateCones.h"

#include <string>

int main()
{
    GetUserInputs GUI;
	vector<std::string> files = GUI.getFilePaths();
	vector<DetectorType> detectors = GUI.getDetectors();


	FileToData FTD;
	vector<EventEntry> scatteringEvents = FTD.GetData(files, detectors, true);
	vector<EventEntry> absorbEvents = FTD.GetData(files, detectors, false);


	GenerateCones coneGenerator;
	vector<Cone> cones = coneGenerator.GetCones(scatteringEvents, absorbEvents, detectors);




	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
