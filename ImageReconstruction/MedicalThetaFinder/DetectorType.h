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
    DetectorType(bool scatter);
    
    void setDetectorXCord(double x){
        detectorXCord = x;
    }
    void setDetectorZCord(double z){
        detectorZCord = z;
    }
    double getDetectorXCord(){
        return detectorXCord;
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
    bool isScatter;         //if not scatter, is absorber by default.
    
    
    
};



#endif /* DetectorType_hpp */
