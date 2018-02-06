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
    
    vector<string> GetFilePaths(){
        return _FilePaths;
    }
    vector<DetectorType> GetDetectors(){
        return _Detectors;
    }

	double GetEnergy()
	{
		return _Energy;
	}
    
	double GetImageHeight()
	{
		return _ImageHeight;
	}

	double GetImageSizeWidth()
	{
		return _ImageSizeWidth;
	}

	int GetPixels()
	{
		return _Pixels;
	}

private:
    vector<string> _FilePaths;
    vector<DetectorType> _Detectors;
	double _Energy; //in keV.
	double _ImageHeight;
	double _ImageSizeWidth;
	int _Pixels;
};


#endif /* GetUserInputs_h */
