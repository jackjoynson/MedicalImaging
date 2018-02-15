//Gets the user inputs of the file and detector e.t.c.


#include "GetUserInputs.h"
using namespace std;


GetUserInputs::GetUserInputs()
{



	string path;


	cout << "Please enter the file path of the detector file. Must be very short (I.e. put on C drive) " << endl;
	cin >> path;


	_FilePaths.push_back(path);
	_IsScatter.push_back(true);


}


