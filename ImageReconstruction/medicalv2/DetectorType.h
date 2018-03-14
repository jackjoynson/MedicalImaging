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
        detectorXCord = x;
    }
    void setDetectorYCord(double y){
        detectorYCord = y;
    }

    void setDetectorZCord(double z){
        detectorZCord = z;
    }
    double getDetectorXCord(){
        return detectorXCord;
    }
    double getDetectorYCord(){
        return detectorYCord;
    }
    double getDetectorZCord(){
        return detectorZCord;
    }
    
    void setIsScatter(bool x){
        isScatter = x;
    }
    
    bool getIsScatter(){
        return isScatter;
    }
    
private:

    double detectorXCord;
    double detectorZCord;
    double detectorYCord;
    bool isScatter;         //if not scatter, is absorber by default.
    
    
    
};



#endif /* DetectorType_hpp */
