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
		double offset;


		cout << "Please enter the file path of the detector file. Must be very short (I.e. put on C drive) " << i << endl;
		cin >> path;
		cout << "Enter 1 if scatter, 0 if absorber:" << endl;
		int temp;
		cin >> temp;

		bool isScatter = (temp == 1) ? true : false;

		cout << "Enter the time offset for this file: " << endl;
		cin >> offset;

		_FilePaths.push_back(path);
		_IsScatter.push_back(isScatter);
		_Offsets.push_back(offset);

	}
}


