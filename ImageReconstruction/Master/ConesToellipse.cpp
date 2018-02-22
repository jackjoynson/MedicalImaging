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

#define PI 3.14159265359

ConesToEllipse::ConesToEllipse()
{

}

/////
//ConesToEllipse::ConesToEllipse(Vector3D plane, vector<Cone> cones):
//    _cones(cones),
//    _plane(plane)
//{
//    //Normal of the plane
//    Vector3D planeNormal(0,0,1);


//    for(int i = 0; i < _cones.size(); i++){

//        //Convert cone into a vector
//        Cone thisCone = _cones[i];
//        double coneAxisX = thisCone.GetStartX() - thisCone.GetXImagePlane();
//        double coneAxisY = thisCone.GetStartY() - thisCone.GetYImagePlane();
//        Vector3D coneAxis(coneAxisX,coneAxisY,plane.getZ());            //Vector of the cone axis

//        //Vector of where the cone intersects the plane
//        Vector3D planePoint(0,0,plane.getZ());
//        Vector3D coneVertex(thisCone.GetStartX(),thisCone.GetYImagePlane(),0);


//        //Angles for calculating
//        double cosTheta = planeNormal.Dot(coneAxis)/(norm(planeNormal)*norm(coneAxis));
//        double cosThetaSq = cosTheta*cosTheta;
//        double sinAlpha = sin(thisCone.GetHalfAngle());
//        double sinAlphaSq = sinAlpha*sinAlpha;
//        double cosAlpha = sqrt(1.0 - sinAlphaSq);

//        double t = planeNormal.Dot(planePoint - coneVertex);
//        double b = cosThetaSq - sinAlphaSq;
//        double h = t/b;

//        double diffX = coneAxis.getX()-cosTheta*planeNormal.getX();
//        double diffY = coneAxis.getY()-cosTheta*planeNormal.getY();
//        double diffZ = coneAxis.getZ()-cosTheta*planeNormal.getZ();
//        Vector3D diff(diffX,diffY,diffZ);

//        Vector3D ellipseU = diff/norm(diff);

//        Vector3D center(coneVertex.getX() + h*cosTheta*coneAxis.getX() - h*sinAlphaSq*planeNormal.getX(),
//                        coneVertex.getY() + h*cosTheta*coneAxis.getY() - h*sinAlphaSq*planeNormal.getY(),
//                        coneVertex.getZ() + h*cosTheta*coneAxis.getZ() - h*sinAlphaSq*planeNormal.getZ()
//                        );



//        Vector3D u(coneAxis.getX()-cosTheta*planeNormal.getX(),
//                    coneAxis.getY()-cosTheta*planeNormal.getY(),
//                    coneAxis.getZ()-cosTheta*planeNormal.getZ());


//        Vector3D majorAxis = normalize(u);
//        Vector3D minorAxis = cross(planeNormal,ellipseU);
//        double majorRadius = fabs(h) * sinAlpha*cosAlpha;
//        double minorRadius = t*sinAlpha/sqrt(fabs(b));

//        if(cosTheta > sinAlpha || cosTheta == 0){
//            //Ellipse
//            Ellipse thisEllipse(center,majorAxis,minorAxis,majorRadius,minorRadius);
//            _ellipses.push_back(thisEllipse);
//        }
//        else
//        {
//            cout << "Ellipse " << i << " is invalid" << endl;
//        }

//    }

//}

//ConesToEllipse::ConesToEllipse(Vector3D plane, vector<Cone> cones):
//    _cones(cones),
//    _plane(plane)
//{

//    for(int i = 0; i < _cones.size(); i++){
//        Cone thisCone = _cones[i];
//        double theta = thisCone.GetHalfAngle();

//        double omega = atan2(thisCone.GetYImagePlane(),thisCone.GetXImagePlane());

//        if(thisCone.GetXImagePlane() < 0){
//            omega += PI;
//        }

//        //omega in 3rd quadrant is negative, but in 0,1,2 are positive.


//        double a = plane.getZ();
//        double phi2 = atan(fabs(thisCone.GetXImagePlane()/a));
//        double phi1 = theta - phi2;
//        double u = a*tan(phi1);
//        double v = a*tan(phi2);
//        double rmin = u+v;
//        double rmax;
//        double majorRadius;
//        double minorRadius;


//        //For calculating the major and minor axis
//        double coneAxisX = thisCone.GetXImagePlane() - thisCone.GetStartX();
//        double coneAxisY = thisCone.GetYImagePlane() - thisCone.GetStartY();
//        Vector3D coneAxis(coneAxisX,coneAxisY,plane.getZ());            //Vector of the cone axis

//        Vector3D majorAxis(1,0,plane.getZ());
//        Vector3D minorAxis(0,1,plane.getZ());

////        if(fabs(thisCone.GetXImagePlane()) > fabs(thisCone.GetYImagePlane())){
////            majorAxis()
////        }

//        if(phi2 > theta || phi2 == theta){
//            double alpha = phi2-theta;
//            double extraBit = a*tan(alpha);
//            rmin = v-extraBit;
//            rmax = a*tan(phi2+theta) - extraBit-v;
//            majorRadius = (rmax+rmin)/2.0;           //These are the SEMI major and MINOR axis radiuses;
//            minorRadius = sqrt(rmax*rmin);

//            Ellipse thisEllipse(FindCenter(rmin,majorRadius,coneAxis,thisCone,plane),majorAxis,minorAxis,majorRadius,minorRadius);
//            _ellipses.push_back(thisEllipse);

//        }

//		else if (phi2 < theta)      //Change this later
//		{
//			if (phi2 + theta > PI / 2 || phi2 + theta == PI / 2) {
//				//rmax = 0;           //Rmax doesn't exist, hyerbola.
//				cout << "Ellipse " << i << " is invalid" << endl;
//			}
//			else
//			{
//				double vPlusT = a*tan(phi2 + theta);
//				rmax = vPlusT - v;

//				majorRadius = (rmax + rmin) / 2.0;           //These are the SEMI major and MINOR axis radiuses;
//				minorRadius = sqrt(rmax*rmin);
//				Ellipse thisEllipse(FindCenter(rmin, majorRadius, coneAxis, thisCone, plane), majorAxis, minorAxis, majorRadius, minorRadius);
//				_ellipses.push_back(thisEllipse);
//			}



//		}


//}
//}

ConesToEllipse::ConesToEllipse(Vector3D plane, vector<Cone> cones):
    _cones(cones),
    _plane(plane)
{

    for(int i = 0; i < _cones.size(); i++){
        Cone thisCone = _cones[i];
        double theta = thisCone.GetHalfAngle();

        double omega = atan2(thisCone.GetYImagePlane(),thisCone.GetXImagePlane());


        double a = plane.getZ();
        double phi2 = atan(fabs(thisCone.GetXImagePlane()/a));
        double phi1 = theta - phi2;
        double u = a*tan(phi1)/cos(omega);
        double v = a*tan(phi2)/cos(omega);
        double rmin = u+v;
        double rmax;
        double majorRadius;
        double minorRadius;


        Vector3D majorAxis(cos(omega),sin(omega),0);
        Vector3D minorAxis(sin(omega),cos(omega),0);


        if(phi2 > theta || phi2 == theta){
            double alpha = phi2-theta;
            double extraBit = a*tan(alpha)/cos(omega);
            rmin = v-extraBit;
            rmax = a*tan(phi2+theta)/cos(omega) - extraBit-v;
            majorRadius = (rmax+rmin)/2.0;           //These are the SEMI major and MINOR axis radiuses;
            minorRadius = sqrt(rmax*rmin);

            Ellipse thisEllipse(FindCenter(rmin,majorRadius,omega,thisCone),majorAxis,minorAxis,majorRadius,minorRadius);
            _ellipses.push_back(thisEllipse);

        }

        else if (phi2 < theta)      //Change this later
        {
            if (phi2 + theta > PI / 2 || phi2 + theta == PI / 2) {
                //rmax = 0;           //Rmax doesn't exist, hyerbola.
                cout << "Ellipse " << i << " is invalid" << endl;
            }
            else
            {
                double vPlusT = a*tan(phi2 + theta)/cos(omega);
                rmax = vPlusT - v;

                majorRadius = (rmax + rmin) / 2.0;           //These are the SEMI major and MINOR axis radiuses;
                minorRadius = sqrt(rmax*rmin);
                Ellipse thisEllipse(FindCenter(rmin, majorRadius, omega, thisCone), majorAxis, minorAxis, majorRadius, minorRadius);
                _ellipses.push_back(thisEllipse);
            }

        //TODO axis and center. Magnitude should be correct
        //Center is done



        }


}
}

Vector3D ConesToEllipse::FindCenter(double rmin,double majorRadius , double omega, Cone thisCone){

    double xPos = thisCone.GetXImagePlane() - (rmin+majorRadius)*cos(omega);
    double yPos = thisCone.GetYImagePlane() - (rmin+majorRadius)*sin(omega);

    return Vector3D(xPos,yPos,0);

}
