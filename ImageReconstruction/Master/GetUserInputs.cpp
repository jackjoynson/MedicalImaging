//Gets the user inputs of the file and detector e.t.c.


#include "GetUserInputs.h"
using namespace std;


GetUserInputs::GetUserInputs()
{
    int x;
    cout << "Would you like to use the preset file? 1 for yes, 0 for no." << endl;
    cin >> x;

    if(x == 1){
        fromFile();
    }
    else{


	cout << "Enter 1 if the data is simulation, enter 0 if its real:" << endl;
	int tempIsSim;
	cin >> tempIsSim;
	if (tempIsSim > 0) _IsSimulation = true;
	else _IsSimulation = false;

	cout << "Please enter the gamma ray energy in keV:" << endl;
	cin >> _Energy;

	cout << "Enter the image slice height:" << endl;
	cin >> _ImageHeight;

	cout << "Enter the image size in meters (1m?):" << endl;
	cin >> _ImageSizeWidth;

	cout << "Enter the number of pixels per side (100?):" << endl;
	cin >> _Pixels;

	cout << "Enter the tolerance on the time:" << endl;
	cin >> _Tolerance;

    int detectorNumber;
    cout << "Please enter the number of detectors:" << endl;
    cin >> detectorNumber;
    
    
    for(int i = 1; i <= detectorNumber; i++){
        string path;
        DetectorType detector;
        double x;
        double z;
        int scatter;
        
        
        cout << "Please enter the file path of detector " << i << endl;
        cin >> path;
        _FilePaths.push_back(path);
        cout << "Please enter that detector's x coordinate (see reference) in meters" << endl;
        cin >> x;
        detector.setDetectorXCord(x);
        cout << "Please enter that detector's z coordinate (see reference) in meters" << endl;
        cin >> z;
        detector.setDetectorZCord(z);
        cout << "Is the detector of type absorption or scattering (1 for scatter, 0 for absorption)." << endl;
        cin >> scatter;
        
        
        if(scatter == 1){
            detector.setIsScatter(true);
        }
        else{
            detector.setIsScatter(false);
        }
        _Detectors.push_back(detector);
 
    
}
    }
}

void GetUserInputs::fromFile(){
    string line;
    string file;
    cout << "Input a file" << endl;
    cin >> file;

    ifstream myfile (file);
    if (myfile.is_open())
    {
        int _detectorCount;
        int _initialEnergy;
        int _tolerance;
        int _imageSize;
        int _imageHeight;
        int _pixelCount;
        double _detectorx[100];
        double _detectorz[100];
        string _detectorPath[100];
        int _detectorType[100];


        while ( myfile.good() )
        {
            getline (myfile,line);
            string detectorCount = "DetectorCount";
            size_t found = line.find(detectorCount);
            if (found != string::npos ){
                _detectorCount = stoi(line.substr(found+detectorCount.length() + 1));
            }

            string initialEnergy = "InitialEnergy";
            found = line.find(initialEnergy);
            if(found != string::npos){
                _initialEnergy = stoi(line.substr(found+initialEnergy.length()+1));
            }

            string tolerance = "Tolerance";
            found = line.find(tolerance);
            if(found != string::npos){
                _tolerance = stoi(line.substr(found+tolerance.length()+1));
            }

            string imageSize = "imageSize";
            found = line.find(imageSize);
            if(found != string::npos){
                _imageSize = stoi(line.substr(found+imageSize.length()+1));
            }

            string imageHeight = "imageHeight";
            found = line.find(imageHeight);
            if(found != string::npos){
                _imageHeight = stoi(line.substr(found+imageHeight.length()+1));
            }

            string pixelCount = "pixelCount";
            found = line.find(pixelCount);
            if(found != string::npos){
                _pixelCount = stoi(line.substr(found+pixelCount.length()+1));
            }

            string detector0x = "Detector0x";
            string detector0z = "Detector0z";
            string detectorfp0 = "Detectorfp0";
            string detector0type = "Detector0type";

            for(int i = 0; i < _detectorCount; i++){

                string thisDetectorx =detector0x.replace(8,1,to_string(i));
                found = line.find(thisDetectorx);
                if(found != string::npos){
                    _detectorx[i] = stod(line.substr(found+thisDetectorx.length()+1));
                }

                string thisDetectorz =detector0z.replace(8,1,to_string(i));
                found = line.find(thisDetectorz);
                if(found != string::npos){
                    _detectorz[i] = stod(line.substr(found+thisDetectorz.length()+1));
                }

                string thisDetectorfp =detectorfp0.replace(10,1,to_string(i));
                found = line.find(thisDetectorfp);
                if(found != string::npos){
                    _detectorPath[i] = line.substr(found+thisDetectorfp.length()+1);
                }

                string thisDetectorType = detector0type.replace(8,1,to_string(i));
                found = line.find(thisDetectorType);
                if(found != string::npos){
                    _detectorType[i] = stoi(line.substr(found+thisDetectorType.length()+1));
                }

            }
        }
        myfile.close();
        _Tolerance = _tolerance;
        _Energy = _initialEnergy;
        _ImageSizeWidth = _imageSize;
        _ImageHeight = _imageHeight;
        _Pixels = _pixelCount;

        for(int i = 0; i < _detectorCount; i++){
            _FilePaths.push_back(_detectorPath[i]);
            DetectorType dec;
            dec.setDetectorXCord(_detectorx[i]);
            dec.setDetectorZCord(_detectorz[i]);
            dec.setIsScatter(_detectorType[i]);
            _Detectors.push_back(dec);
        }

    }

    else cout << "Unable to open file";


}


