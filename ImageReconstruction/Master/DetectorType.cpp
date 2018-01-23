//
//  DetectorType.cpp
//  
//
//  Created by ziyue wang on 23/01/2018.
//

#include "DetectorType.h"

DetectorType::DetectorType(){
    
}

DetectorType::DetectorType(int x, int y, bool scatter){
    detectorXCord = x;
    detectorYCord = y;
    isScatter = scatter;
}

~DetectorType::DetectorType(){
    
}

