//
//  ConesToEllipse.h
//
//
//  Created by ziyue wang on 30/01/2018.
//

#ifndef ConesToEllipse_h
#define ConesToEllipse_h

#include <vector>
#include "Cone.h"
#include "Vector3D.h"
#include "Ellipse.h"
using namespace std;

class ConesToEllipse
{
public:

    ConesToEllipse();
    ConesToEllipse(Vector3D plane, vector<Cone> cones);

//setters and getters
    void setPlane(Vector3D plane){
        _plane = plane;
    }

    Vector3D getPlane(){
        return _plane;
    }

    vector<Ellipse> getEllipses(){
        return _ellipses;
    }


//Dot and cross product for the

private:
    vector<Cone> _cones;        //Vector of cones
    vector<Ellipse> _ellipses;       //Vector of ellipses
    Vector3D _plane;        //User inputed plane.

    void MakeCones();
    Vector3D FindCenter(double rmin, double majorRadius, double omega, Cone thisCone);
};


#endif /* ConesToEllipse_h */
