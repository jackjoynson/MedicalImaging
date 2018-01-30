#include "Vector3D.h"

Vector3D::Vector3D(){
    
}

Vector3D::Vector3D(double X, double Y, double Z){
    _X = X;
    _Y = Y;
    _Z = Z;
}

Vector3D::~Vector3D(){

}

double Vector3D::Dot(const Vector3D & o) const{
    return _X*o._X + _Y*o._Y + _Z*o._Z;
}

