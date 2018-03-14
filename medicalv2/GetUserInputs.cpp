//Gets the user inputs of the file and detector e.t.c.


#include "GetUserInputs.h"
using namespace std;


GetUserInputs::GetUserInputs(bool useCCData)
{
	if (!useCCData)
	{
		int x;
		cout << "Would you like to use the preset file? 1 for yes, 0 for no." << endl;
		cin >> x;

		if (x == 1) fromFile();
		else fromConsole(useCCData);		
	}
	else 
	{
		fromConsole(useCCData);
	}
}


void GetUserInputs::fromConsole(bool useCCData)
{
	if (useCCData)
	{
		_DoesHaveHeaders = false;
	}
	else 
	{
		cout << "Enter 1 if the data has headers, enter 0 if not:" << endl;
		int tempHasHeaders;
		cin >> tempHasHeaders;
		if (tempHasHeaders > 0) _DoesHaveHeaders = true;
		else _DoesHaveHeaders = false;
	}

	cout << "Please enter the gamma ray energy in keV:" << endl;
	cin >> _Energy;

	cout << "Enter the image slice height:" << endl;
	cin >> _ImageHeight;

	cout << "Enter the image size in meters (1m?):" << endl;
	cin >> _ImageSizeWidth;

	cout << "Enter the number of pixels per side (100?):" << endl;
	cin >> _Pixels;

	if (!useCCData)
	{
		cout << "Enter the tolerance on the time:" << endl;
		cin >> _Tolerance;
	}

	int detectorNumber;
	cout << "Please enter the number of detectors:" << endl;
	cin >> detectorNumber;


	for (int i = 1; i <= detectorNumber; i++) {
		string path;
		DetectorType detector;
		double x;
        double y;
		double z;
		int scatter;

		if (!useCCData)
		{
			cout << "Please enter the file path of detector " << i << endl;
			cin >> path;
			_FilePaths.push_back(path);
		}

		cout << "Please enter that detector's x coordinate (see reference) in meters" << endl;
		cin >> x;
		detector.setDetectorXCord(x);
        cout << "Please enter that detector's y coordinate (see reference) in meters" << endl;
        cin >> y;
        detector.setDetectorYCord(y);
		cout << "Please enter that detector's z coordinate (see reference) in meters" << endl;
		cin >> z;
		detector.setDetectorZCord(z);
		cout << "Is the detector of type absorption or scattering (1 for scatter, 0 for absorption)." << endl;
		cin >> scatter;


		if (scatter == 1) {
			detector.setIsScatter(true);
		}
		else {
			detector.setIsScatter(false);
		}
		_Detectors.push_back(detector);


	}
}

void GetUserInputs::fromFile(){
    string line;
    string file;
    cout << "Input a file" << endl;
    cin >> file;

   // file = 'Users/ziyuewang/Desktop/Settings.txt';
    ifstream myfile (file);
    if (myfile.is_open())
    {
        int detectorCount;
        double initialEnergy;
        double tolerance;
        double imageSize;
        double imageHeight;
        int pixelCount;
		bool isSimualtionData = false;
        //double _detectorx[100];
        //double _detectorz[100];
        //string _detectorPath[100];
        //int _detectorType[100];

        vector<double> _detectorx;
        vector<double> _detectorz;
        vector<double> _detectory;
        vector<string> _detectorPath;
        vector<int> _detectorType;
        

        while ( myfile.good() )
        {
            getline (myfile,line);
            string detectorCountStr = "DetectorCount";
            size_t found = line.find(detectorCountStr);
            if (found != string::npos ){
                detectorCount = stoi(line.substr(found+detectorCountStr.length() + 1));
            }

            string initialEnergyStr = "InitialEnergy";
            found = line.find(initialEnergyStr);
            if(found != string::npos){
                initialEnergy = stod(line.substr(found+initialEnergyStr.length()+1));
            }

			string isSimStr = "IsSimulationData";
			found = line.find(isSimStr);
			if (found != string::npos) {
				string isSimResult = line.substr(found + isSimStr.length() + 1);
				isSimualtionData = (isSimResult == "True" || isSimResult == "true") ? true : false;
			}

            string toleranceStr = "Tolerance";
            found = line.find(toleranceStr);
            if(found != string::npos){
                tolerance = stod(line.substr(found+toleranceStr.length()+1));
            }

            string imageSizeStr = "ImageSize";
            found = line.find(imageSizeStr);
            if(found != string::npos){
                imageSize = stod(line.substr(found+imageSizeStr.length()+1));
            }

            string imageHeightStr = "ImageHeight";
            found = line.find(imageHeightStr);
            if(found != string::npos){
                imageHeight = stod(line.substr(found+imageHeightStr.length()+1));
            }

            string pixelCountStr = "PixelCount";
            found = line.find(pixelCountStr);
            if(found != string::npos){
                pixelCount = stoi(line.substr(found+pixelCountStr.length()+1));
            }

            string detector0xStr = "Detector0x";
            string detector0yStr = "Detector0y";
            string detector0zStr = "Detector0z";
            string detectorfp0Str = "Detectorfp0";
            string detector0typeStr = "Detector0type";

            for(int i = 0; i < detectorCount; i++){

                string thisDetectorxStr =detector0xStr.replace(8,1,to_string(i));
                found = line.find(thisDetectorxStr);
                if(found != string::npos){
                    _detectorx.push_back(stod(line.substr(found+thisDetectorxStr.length()+1)));
                }

                string thisDetectoryStr =detector0yStr.replace(8,1,to_string(i));
                found = line.find(thisDetectoryStr);
                if(found != string::npos){
                    _detectory.push_back(stod(line.substr(found+thisDetectoryStr.length()+1)));
                }

                string thisDetectorzStr =detector0zStr.replace(8,1,to_string(i));
                found = line.find(thisDetectorzStr);
                if(found != string::npos){
                    _detectorz.push_back(stod(line.substr(found+thisDetectorzStr.length()+1)));
                }

                string thisDetectorfpStr =detectorfp0Str.replace(10,1,to_string(i));
                found = line.find(thisDetectorfpStr);
                if(found != string::npos){
                    _detectorPath.push_back(line.substr(found+thisDetectorfpStr.length()+1));
                }

                string thisDetectorTypeStr = detector0typeStr.replace(8,1,to_string(i));
                found = line.find(thisDetectorTypeStr);
                if(found != string::npos){
                    _detectorType.push_back(stoi(line.substr(found+thisDetectorTypeStr.length()+1)));
                }

            }
        }
        myfile.close();
        _Tolerance = tolerance;
        _Energy = initialEnergy;
        _ImageSizeWidth = imageSize;
        _ImageHeight = imageHeight;
        _Pixels = pixelCount;
		_DoesHaveHeaders = isSimualtionData;

        for(int i = 0; i < detectorCount; i++){
            _FilePaths.push_back(_detectorPath.front());
            _detectorPath.erase(_detectorPath.begin());
            DetectorType dec;
            dec.setDetectorXCord(_detectorx.front());
            _detectorx.erase(_detectorx.begin());
            dec.setDetectorYCord(_detectory.front());
            _detectory.erase(_detectory.begin());
            dec.setDetectorZCord(_detectorz.front());
            _detectorz.erase(_detectorz.begin());
            dec.setIsScatter(_detectorType.front());
            _detectorType.erase(_detectorType.begin());
            _Detectors.push_back(dec);
            
        }

    }

    else cout << "Unable to open file";


}


