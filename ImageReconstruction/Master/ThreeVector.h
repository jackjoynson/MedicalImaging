//
//  ThreeVector.h
//  
//
//  Created by ziyue wang on 25/01/2018.
//

#ifndef ThreeVector_h
#define ThreeVector_h

#include <stdio.h>

class ThreeVector
{
public:
    ThreeVector();
    ThreeVector(double X, double Y, double Z);
    ~ThreeVector();
    
    
    //Setters and getters
    double getDirectionX(){
        return directionX;
    }
    double getDirectionY(){
        return directionX;
    }
    double getDirectionZ(){
        return directionX;
    }
    
    void setDirectionX(double X){
        directionX = X;
    }
    void setDirectionY(double Y){
        directionY = Y;
    }
    void setDirectionZ(double Z){
        directionZ = Z;
    }
    
    const ThreeVector operator+ ()
    
    
    
    
    
    
    
    
    
private:
    double directionX, directionY, directionZ;
    double X,Y,Z;
    
}

#endif /* ThreeVector_h*/
