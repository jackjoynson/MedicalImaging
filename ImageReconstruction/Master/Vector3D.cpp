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

Vector3D operator * (Vector3D & p, double a){
    return Vector3D(a*p.getX(), a*p.getY(), a*p.getZ());
}

Vector3D operator / (double a,  Vector3D & p){
    return Vector3D(p.getX()/a, p.getY()/a, p.getZ()/a);
}

Vector3D operator / (Vector3D & p, double a){
    return Vector3D(p.getX()/a, p.getY()/a, p.getZ()/a);
}

Vector3D cross (Vector3D & a, Vector3D & b){
    double x = a.getY()*b.getZ()-a.getZ()*b.getY();
    double y = a.getZ()*b.getX()-a.getX()*b.getZ();
    double z = a.getX()*b.getY()-a.getY()*b.getX();
    return Vector3D(x,y,z);
}

Vector3D normalize (Vector3D & a){
    double sum = a.getX()*a.getX() + a.getY()*a.getY() + a.getZ()*a.getZ();
    double sqrtSum = sqrt(sum);
    return Vector3D(a.getX()/sqrtSum,a.getY()/sqrtSum,a.getZ()/sqrtSum);
}

double norm (Vector3D & a){
    return sqrt(a.getX()*a.getX() + a.getY()*a.getY() + a.getZ()*a.getZ());
}










