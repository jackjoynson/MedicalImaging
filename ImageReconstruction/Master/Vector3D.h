//
//  Vector3D.h
//  
//
//  Created by ziyue wang on 30/01/2018.
//

#ifndef Vector3D_h
#define Vector3D_h

class Vector3D
{
public:
    Vector3D();
    Vector3D(double X, double Y, double Z);
    ~Vector3D();

    //setters and getters
    double getX(){
        return _X;
    }
    double getY(){
        return _Y;
    }
    double getZ(){
        return _Z;
    }
    void setX(double X){
        _X = X;
    }
    void setY(double Y){
        _Y = Y;
    }
    void setZ(double Z){
        _Z = Z;
    }

    double Dot(const ThreeVector &) const;

private:
    double _X, _Y, _Z;
    
};


#endif /* Vector3D_h */
