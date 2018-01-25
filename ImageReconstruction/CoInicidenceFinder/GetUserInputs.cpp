//Gets the user inputs of the file and detector e.t.c.


#include "GetUserInputs.h"
using namespace std;


GetUserInputs::GetUserInputs()
{

	int detectorNumber;
	cout << "Please enter the number of detectors" << endl;
	cin >> detectorNumber;


	for (int i = 1; i <= detectorNumber; i++) 
	{
		string path;
		int scatter;


		cout << "Please enter the file path of the detector file. Must be very short (I.e. put on C drive) " << i << endl;
		cin >> path;
		filePath.push_back(path);

	}
}


