//Gets the user inputs of the file and detector e.t.c.


#include "GetUserInputs.h"
using namespace std;


GetUserInputs::GetUserInputs(bool isFromFile)
{
	if (isFromFile)
	{
		fromFile();
	}
	else
	{
		cout << "Enter 1 to apply a calibration" << endl;
		int tempCal;
		cin >> tempCal;
		bool calibrate = (tempCal == 1) ? true : false;

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

			double constant = 0.0, gradient = 1.0;

			if (calibrate)
			{
				cout << "Enter the calibration gradient: " << endl;
				cin >> gradient;
				cout << "Enter the calibration constant: " << endl;
				cin >> constant;
			}

			_FilePaths.push_back(path);
			_IsScatter.push_back(isScatter);
			_Offsets.push_back(offset);
			_CalConstants.push_back(constant);
			_CalGradients.push_back(gradient);
		}
	}
}



void GetUserInputs::fromFile(){
    string line;

    ifstream myfile ("Settings.txt");
    if (myfile.is_open())
    {
        bool isSimualtionData = false;

        while ( myfile.good() )
        {
            getline (myfile,line);
            string detectorCountStr = "DetectorCount";
            size_t found = line.find(detectorCountStr);
            if (found != string::npos ){
                _DetectorNumber = stoi(line.substr(found+detectorCountStr.length() + 1));
            }

            string isSimStr = "Headers";
            found = line.find(isSimStr);
            if (found != string::npos) {
                string isSimResult = line.substr(found + isSimStr.length() + 1);
                _Headers = (isSimResult == "True" || isSimResult == "true") ? true : false;
            }

            string toleranceStr = "Tolerance";
            found = line.find(toleranceStr);
            if(found != string::npos){
                _Tolerance = stod(line.substr(found+toleranceStr.length()+1));
            }

            string Outputstr = "Output";
            found = line.find(Outputstr);
            if(found != string::npos){
                _OutputFile = line.substr(found+Outputstr.length()+1);
            }

            string OverRidestr = "OverRide";
            found = line.find(OverRidestr);
            if (found != string::npos) {
                string OverRideResult = line.substr(found + OverRideResult.length() + 1);
                _OverRide = (OverRideResult == "True" || OverRideResult == "true") ? true : false;
            }

            string EnergyLimitsStr = "EnergyLimits";
            found = line.find(EnergyLimitsStr);
            if (found != string::npos) {
                string EnergyLimitsResult = line.substr(found + EnergyLimitsStr.length() + 1);
                _EnergyLimits = (EnergyLimitsResult == "True" || EnergyLimitsResult == "true") ? true : false;
            }

            string UpperEnergystr = "EnergyUpperLimit";
            found = line.find(UpperEnergystr);
            if(found != string::npos){
                _EnergyUpperLimit = stod(line.substr(found+UpperEnergystr.length()+1));
            }

            string LowerEnergystr = "EnergyLowerLimit";
            found = line.find(LowerEnergystr);
            if(found != string::npos){
                _EnergyLowerLimit = stod(line.substr(found+LowerEnergystr.length()+1));
            }

            string MultiModeStr = "MultiMode";
            found = line.find(MultiModeStr);
            if (found != string::npos) {
                string MultiModeResult = line.substr(found + MultiModeStr.length() + 1);
                _MultiMode = (MultiModeResult == "True" || MultiModeResult == "true") ? true : false;
            }





            string detector0calMStr = "Detector0calM";
            string detector0calKStr = "Detector0calK";
            string detector0offset = "Detector0offset";
            string detectorfp0Str = "Detectorfp0";
            string detector0typeStr = "Detector0type";

            for(int i = 0; i < _DetectorNumber; i++)
			{

                string thisDetectorcalMStr = detector0calMStr.replace(8,1,to_string(i));
                found = line.find(thisDetectorcalMStr);
                if(found != string::npos){
                    _CalGradients.push_back(stod(line.substr(found+thisDetectorcalMStr.length()+1)));
                }

                string thisDetectorcalKstr = detector0calKStr.replace(8,1,to_string(i));
                found = line.find(thisDetectorcalKstr);
                if(found != string::npos){
                    _CalConstants.push_back(stod(line.substr(found+thisDetectorcalKstr.length()+1)));
                }

                string thisDetectorOffset = detector0offset.replace(8,1,to_string(i));
                found = line.find(thisDetectorOffset);
                if(found != string::npos){
                    _Offsets.push_back(stod(line.substr(found+thisDetectorOffset.length()+1)));
                }

                string thisDetectorfpStr = detectorfp0Str.replace(10,1,to_string(i));
                found = line.find(thisDetectorfpStr);
                if(found != string::npos){
                    _FilePaths.push_back(line.substr(found+thisDetectorfpStr.length()+1));
                }

                string thisDetectorTypeStr = detector0typeStr.replace(8,1,to_string(i));
                found = line.find(thisDetectorTypeStr);
                if(found != string::npos){
                    _IsScatter.push_back(stoi(line.substr(found+thisDetectorTypeStr.length()+1)));
                }

            }
        }
        myfile.close();


    }

    else cout << "Unable to open file";


}




