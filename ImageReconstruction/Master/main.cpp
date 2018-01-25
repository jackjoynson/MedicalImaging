#include "GetUserInputs.h"


#include <string>

int main()
{
    GetUserInputs GUI;
	vector<std::string> files = GUI.getFilePaths();
	vector<DetectorType> detectors = GUI.getDetectors();

	std::string close;
	cout << "Program complete. Enter something to close.." << endl;
	cin >> close;

	return 0;
}
