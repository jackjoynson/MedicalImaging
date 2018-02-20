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
        return _FilePaths;
    }
    
	vector<bool> getIsScatters()
	{
		return _IsScatter;
	}
    
	vector<double> getOffsets()
	{
		return _Offsets;
	}

private:
    vector<string> _FilePaths;
	vector<bool> _IsScatter;
	vector<double> _Offsets;
};


#endif /* GetUserInputs_h */
