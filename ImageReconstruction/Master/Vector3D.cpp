#include "Vector3D.h"

Vector3D::Vector3D(){
    
}

Vector3D::Vector3D(double X, double Y, double Z){
    setX(X);
    setY(Y);
    setZ(Z);
}

Vector3D::~Vector3D(){

}

double Vector3D::Dot(const Vector3D & o) const{
    return _X*o._X + _Y*o._Y + _Z*o._Z;
}

Vector3D operator + ( Vector3D & a,  Vector3D & b){
    return Vector3D(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
}

Vector3D operator - ( Vector3D & a,  Vector3D & b){
    return Vector3D(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ());
}

Vector3D operator * (double a,  Vector3D & p){
    return Vector3D(a*p.getX(), a*p.getY(), a*p.getZ());
}


