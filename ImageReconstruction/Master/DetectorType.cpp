//
//  DetectorType.cpp
//  
//
//  Created by ziyue wang on 23/01/2018.
//

#include "DetectorType.h"

DetectorType::DetectorType(){
    
}

DetectorType::DetectorType(double x, double z, bool scatter){
    detectorXCord = x;
    detectorZCord = z;
    isScatter = scatter;
}
