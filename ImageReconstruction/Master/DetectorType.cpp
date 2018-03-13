//
//  DetectorType.cpp
//  
//
//  Created by ziyue wang on 23/01/2018.
//

#include "DetectorType.h"

DetectorType::DetectorType(){
    
}

DetectorType::DetectorType(double x, double y, double z, bool scatter){
    detectorXCord = x;
    detectorYCord = y;
    detectorZCord = z;
    isScatter = scatter;
}
