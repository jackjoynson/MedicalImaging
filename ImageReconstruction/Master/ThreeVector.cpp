//
//  ThreeVector.cpp
//  
//
//  Created by ziyue wang on 25/01/2018.
//

#include "ThreeVector.h"
#include <math.h>

ThreeVector::ThreeVector(){
    
}

ThreeVector::ThreeVector(double X, double Y, double Z){
    directionX = X;
    directionY = Y;
    directionZ = Z;
}

ThreeVector::Dot(const ThreeVector & o) const{
    return directionX*o.directionX + directionY*o.directionY + directionZ*o.directionZ;
}

void ThreeVector::Cross(const ThreeVector & o) const{
    directionX = directionY*o.directionZ - directionZ*o.directionY;
    directionY = directionZ*o.directionX - directionX*o.directionZ;
    directionZ = directionX*o.directionY - directionY*o.directionX;
    
}

void ThreeVector::Norm(const ThreeVector) const{
    double sum = directionX*directionX+directionY*directionY+directionZ*directionZ;
    directionX = directionX/sqrt(sum);
    directionY = directionY/sqrt(sum);
    directionZ = directionZ/sqrt(sum);
    
}







