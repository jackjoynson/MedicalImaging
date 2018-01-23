//
//  GetUserInputs.h
//  
//
//  Created by ziyue wang on 23/01/2018.
//

#ifndef GetUserInputs_h
#define GetUserInputs_h

#include <fstream>
#include "DetectorType.h"
#include <string>
#include <iostream>
using namespace std;

class GetUserInputs
{
public:
    GetUserInputs();
    
    vector<string> getFilePaths(){
        return filePath;
    }
    vector<DetectorType> getDetectors(){
        return detectors;
    }
    
    
private:
    vector<string> filePath;
    vector<DetectorType> detectors;
}


#endif /* GetUserInputs_h */