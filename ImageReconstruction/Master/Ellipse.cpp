#include "Ellipse.h"


Ellipse::Ellipse(Vector3D center, Vector3D majorAxis, Vector3D minorAxis, double majorRadius, double minorRadius)
{
	SetCenter(center);
	SetMajorAxis(majorAxis);
	SetMinorAxis(minorAxis);
	SetMajorRadius(majorRadius);
	SetMinorRadius(minorRadius);
}