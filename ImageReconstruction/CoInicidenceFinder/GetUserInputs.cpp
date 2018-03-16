//Gets the user inputs of the file and detector e.t.c.
#include <sstream>

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

		cout << "Enter 1 if using compass" << endl;
		int tempCompass;
		cin >> tempCompass;
		_UsingCompass = (tempCompass == 1) ? true : false;

		if (_UsingCompass)
		{
			cout << "Enter 1 to use smart start optimisation - experimental!" << endl;
			int tempSS;
			cin >> tempSS;
			_UseSmartStart = (tempSS == 1) ? true : false;
		}
		else _UseSmartStart = false;


		int detectorNumber;
		cout << "Please enter the number of detectors" << endl;
		cin >> detectorNumber;
        
        cout << "Enter the time tolerance window size:" << endl;
        cin >> _Tolerance;
        _Tolerance = _Tolerance / 2.0;
        
        cout << "Enter 1 if the data files have headers: " << endl;
        int tempHeaders;
        cin >> tempHeaders;
        _Headers = (tempHeaders == 1) ? true : false;
        
        cout << "Enter a valid file name to output to:" << endl;
        string fileName;
        cin >> _OutputFile;
        
        cout << "Enter 1 to override checking only scatter with absorber" << endl;
        int tempOverride;
        cin >> tempOverride;
        _OverRide = (tempOverride == 1) ? true : false;
        
        cout << "Enter 1 to only check for coincidence events in all files - I.E. ONLY CHECK IF AN EVENT HAPPENS IN EVERY DETECTOR:" << endl;
        int tempMulti;
        cin >> tempMulti;
        _MultiMode = (tempMulti == 1) ? true : false;
        
        cout << "Enter 1 to add limits to scatter and absorption energy:" << endl;
        int tempLimits;
        cin >> tempLimits;
        bool _EnergyLimits = (tempLimits == 1) ? true : false;
        
        double upperScatLim = 0.0;
        double lowerAbsLim = 0.0;
        if (_EnergyLimits)
        {
            cout << "Enter the upper scattering energy limit:" << endl;
            cin >> _EnergyUpperLimit;
            cout << "Enter the lower absorption energy limit:" << endl;
            cin >> _EnergyLowerLimit;
        }


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

			string useSSStr = "SmartStart";
			found = line.find(useSSStr);
			if (found != string::npos) {
				string useSSResult = line.substr(found + useSSStr.length() + 1);
				_UseSmartStart = (useSSResult == "True" || useSSResult == "true") ? true : false;
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
                string OverRideResult = line.substr(found + OverRidestr.length() + 1);
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



            string detector0offset = "Detector0offset";
            string detectorfp0Str = "Detectorfp0";
            string detector0typeStr = "Detector0type";

            for(int i = 0; i < _DetectorNumber; i++)
			{
				stringstream thisDetectorCalMStr;
				thisDetectorCalMStr << "Detector" << i << "calM";
                found = line.find(thisDetectorCalMStr.str());
                if(found != string::npos){
                    _CalGradients.push_back(stod(line.substr(found+thisDetectorCalMStr.str().length()+1)));
                }

				stringstream thisDetectorCalKStr;
				thisDetectorCalKStr << "Detector" << i << "calK";
                found = line.find(thisDetectorCalKStr.str());
                if(found != string::npos){
                    _CalConstants.push_back(stod(line.substr(found+thisDetectorCalKStr.str().length()+1)));
                }

				stringstream offset;
				offset << "Detector" << i << "offset";
                found = line.find(offset.str());
                if(found != string::npos){
                    _Offsets.push_back(stod(line.substr(found+offset.str().length()+1)));
                }

				stringstream fp;
				fp << "Detectorfp" << i;
                found = line.find(fp.str());
                if(found != string::npos){
                    _FilePaths.push_back(line.substr(found+fp.str().length()+1));
                }

				stringstream type;
				type << "Detector" << i << "type";
                found = line.find(type.str());
                if(found != string::npos){
                    _IsScatter.push_back(stoi(line.substr(found+type.str().length()+1)));
                }

            }
        }
        myfile.close();


    }

    else cout << "Unable to open file";


}




