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
#include <vector>
#include <stdio.h>

using namespace std;

class GetUserInputs
{
public:
    GetUserInputs();
    
    vector<string> getFilePaths()
	{
        return filePath;
    }
    
    
private:
    vector<string> filePath;
};


#endif /* GetUserInputs_h */