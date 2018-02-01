//
//  Vector3D.h
//  
//
//  Created by ziyue wang on 30/01/2018.
//

#ifndef Vector3D_h
#define Vector3D_h


#include <cmath>

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

    double Dot(const Vector3D &) const;



    //Operators
//    Vector3D & operator = (const Vector3D &);
//    Vector3D & operator += (const Vector3D &);
//    Vector3D & operator -= (const Vector3D &);
//    Vector3D operator - () const;
//    Vector3D & operator *= (double);


private:
    double _X, _Y, _Z;
    
};

Vector3D operator + ( Vector3D &,  Vector3D &);
Vector3D operator - ( Vector3D &,  Vector3D &);

Vector3D operator * (double a, Vector3D &);
Vector3D operator * (Vector3D &, double a);
Vector3D operator / (double a, Vector3D &);
Vector3D operator / (Vector3D &, double a);

Vector3D cross (Vector3D &, Vector3D &);

Vector3D normalize (Vector3D &);

double norm (Vector3D &);

///Dodgy, fix this later.

//Vector3D & Vector3D::operator = (const Vector3D & p){
//    _X = p._X;
//    _Y = p._Y;
//    _Z = p._Z;
//    return this;
//}

//Vector3D & Vector3D::operator += (const Vector3D & p){
//    _X += p._X;
//    _Y += p._Y;
//    _Z += p._Z;
//    return *this;
//}

//Vector3D & Vector3D::operator -=(const Vector3D & p){
//    _X -= p._X;
//    _Y -= p._Y;
//    _Z -= p._Z;
//    return *this;
//}

//Vector3D Vector3D::operator -() const{
//    return Vector3D(-_X,-_Y,-_Z);
//}

//Vector3D& Vector3D::operator *=(double a){
//    _X *= a;
//    _Y *= a;
//    _Z *= a;
//    return *this;
//}




#endif /* Vector3D_h */
