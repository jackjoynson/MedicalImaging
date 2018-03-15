//
//  DetectorType.hpp
//  
//
//  Created by ziyue wang on 23/01/2018.
//

#ifndef DetectorType_h
#define DetectorType_h

#include <stdio.h>
using namespace std;

class DetectorType
{
public:
    DetectorType();
    DetectorType(double x, double y, double z, bool scatter);
    
    void setDetectorXCord(double x){
        _DetectorXCord = x;
    }
    void setDetectorYCord(double y){
        _DetectorYCord = y;
    }

    void setDetectorZCord(double z){
        _DetectorZCord = z;
    }
    double getDetectorXCord(){
        return _DetectorXCord;
    }
    double getDetectorYCord(){
        return _DetectorYCord;
    }
    double getDetectorZCord(){
        return _DetectorZCord;
    }
    
    void setIsScatter(bool x){
        isScatter = x;
    }
    
    bool getIsScatter(){
        return isScatter;
    }
    
private:

    double _DetectorXCord;
    double _DetectorZCord;
    double _DetectorYCord;
    bool isScatter;         //if not scatter, is absorber by default.
    
    
    
};



#endif /* DetectorType_hpp */
