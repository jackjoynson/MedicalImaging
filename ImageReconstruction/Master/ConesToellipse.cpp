//
//  ConesToEllipse.cpp
//
//
//  Created by ziyue wang on 23/01/2018.
//

#include <stdio.h>
#include "ConesToEllipse.h"
#include <cmath>
#include <iostream>

ConesToEllipse::ConesToEllipse()
{

}

ConesToEllipse::ConesToEllipse(Vector3D plane, vector<Cone> cones):
    _cones(cones),
    _plane(plane)
{
    //Normal of the plane
    Vector3D planeNormal(0,0,1);


    for(int i = 0; i < _cones.size(); i++){

        //Convert cone into a vector
        Cone thisCone = _cones[i];
        double coneAxisX = thisCone.GetStartX() - thisCone.GetXImagePlane();
        double coneAxisY = thisCone.GetStartY() - thisCone.GetYImagePlane();
        Vector3D coneAxis(coneAxisX,coneAxisY,plane.getZ());            //Vector of the cone axis

        //Vector of where the cone intersects the plane
        Vector3D planePoint(0,0,plane.getZ());
        Vector3D coneVertex(thisCone.GetStartX(),thisCone.GetYImagePlane(),0);


        //Angles for calculating
        double cosTheta = planeNormal.Dot(coneAxis)/(norm(planeNormal)*norm(coneAxis));
        double cosThetaSq = cosTheta*cosTheta;
        double sinAlpha = sin(thisCone.GetHalfAngle());
        double sinAlphaSq = sinAlpha*sinAlpha;
        double cosAlpha = sqrt(1.0 - sinAlphaSq);

        double t = planeNormal.Dot(planePoint - coneVertex);
        double b = cosThetaSq - sinAlphaSq;
        double h = t/b;

        double diffX = coneAxis.getX()-cosTheta*planeNormal.getX();
        double diffY = coneAxis.getY()-cosTheta*planeNormal.getY();
        double diffZ = coneAxis.getZ()-cosTheta*planeNormal.getZ();
        Vector3D diff(diffX,diffY,diffZ);

        Vector3D ellipseU = diff/norm(diff);

        Vector3D center(coneVertex.getX() + h*cosTheta*coneAxis.getX() - h*sinAlphaSq*planeNormal.getX(),
                        coneVertex.getY() + h*cosTheta*coneAxis.getY() - h*sinAlphaSq*planeNormal.getY(),
                        coneVertex.getZ() + h*cosTheta*coneAxis.getZ() - h*sinAlphaSq*planeNormal.getZ()
                        );



        Vector3D u(coneAxis.getX()-cosTheta*planeNormal.getX(),
                    coneAxis.getY()-cosTheta*planeNormal.getY(),
                    coneAxis.getZ()-cosTheta*planeNormal.getZ());


        Vector3D majorAxis = normalize(u);
        Vector3D minorAxis = cross(planeNormal,ellipseU);
        double majorRadius = fabs(h) * sinAlpha*cosAlpha;
        double minorRadius = t*sinAlpha/sqrt(fabs(b));

        if(cosTheta > sinAlpha || cosTheta == 0){
            //Ellipse
            Ellipse thisEllipse(center,majorAxis,minorAxis,majorRadius,minorRadius);
            _ellipses.push_back(thisEllipse);
        }
        else{
            cout << "Ellipse " << i << "is invalid" << endl;
        }

    }

}
