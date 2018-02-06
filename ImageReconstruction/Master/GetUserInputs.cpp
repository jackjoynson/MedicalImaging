//Gets the user inputs of the file and detector e.t.c.


#include "GetUserInputs.h"
using namespace std;


GetUserInputs::GetUserInputs()
{
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


