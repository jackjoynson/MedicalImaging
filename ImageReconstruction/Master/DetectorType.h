//
//  DetectorType.hpp
//  
//
//  Created by ziyue wang on 23/01/2018.
//

#ifndef DetectorType_hpp
#define DetectorType_hpp

#include <stdio.h>
using namespace std;

class DetectorType
{
public:
    DetectorType();
    DetectorType(int x, int y, bool scatter);
    ~DetectorType();
    
    void setDetectorXCord(double x){
        detectorXCord = x;
    }
    void setDetectorYCord(double y){
        detectorYCord = y;
    }
    double getDetectorXCord(){
        return detectorXCord;
    }
    double getDetectorYCord(){
        return detectorYCord;
    }
    
    void setIsScatter(bool x){
        isScatter = x;
    }
    
    bool getIsScatter(){
        return isScatter;
    }
    
private:

    double detectorXCord;
    double detectorYCord;
    bool isScatter;         //if not scatter, is absorber by default.
    
    
    
};



#endif /* DetectorType_hpp */
