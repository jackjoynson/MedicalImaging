//Gets the user inputs of the file and detector e.t.c.

#include "GetUserInputs.h"
using namespace std;


GetUserInput::GetUserInput()
{

    int detectorNumber;
    cout << "Please enter the number of detectors" << endl;
    cin >> detectorNumber;
    
    
    for(int i = 1; i <= detectorNumber; i++){
        string path;
        DetectorType detector;
        double x;
        double y;
        int scatter;
        
        
        cout << "Please enter the file path of detector " << i << endl;
        cin >> path;
        FilePath.push_back(path);
        cout << "Please enter that detector's x coordinate (see reference) in meters" << endl;
        cin >> x;
        detector.setDetectorXCord(x);
        cout << "Please enter that detector's y coordinate (see reference) in meters" << endl;
        cin >> y;
        detector.setDetectorYCord(y);
        cout << "Is the detector of type absorption or scattering (1 for scatter, 0 for absorption)." << endl;
        cin >> scatter;
        
        
        if(scatter == 1){
            detector.setIsScatter(true);
        }
        else{
            detector.setIsScatter(false);
        }
        detectors.push_back(detector);
 
    
}
}


