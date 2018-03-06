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

	vector<double> getCalGradients()
	{
		return _CalGradients;
	}

	vector<double> getCalConstants()
	{
		return _CalConstants;
	}
    
    double getTolerance()
    {
        return _Tolerance;
    }
    
    bool getHeaders(){
        return _Headers;
    }
    
    string getOutputFile(){
        return _OutputFile;
    }
    
    bool getOverRide(){
        return _OverRide;
    }
    
    bool getEnergyLimits(){
        return _EnergyLimits;
    }
    
    double getEnergyUpperLimits(){
        return _EnergyUpperLimit;
    }
    
    double getEnergyLowerLimits(){
        return _EnergyLowerLimit;
    }
    
    bool getMultiMode(){
        return _MultiMode;
    }
    
private:
    int _DetectorNumber;
    double _Tolerance;
    bool _Headers;
    string _OutputFile;
    bool _OverRide;
    bool _EnergyLimits;
    double _EnergyUpperLimit;
    double _EnergyLowerLimit;
    bool _MultiMode;



    vector<string> _FilePaths;
	vector<bool> _IsScatter;
	vector<double> _Offsets;
	vector<double> _CalGradients;
    vector<double> _CalConstants;
    void fromFile();
};


#endif /* GetUserInputs_h */
