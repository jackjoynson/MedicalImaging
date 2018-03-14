
#ifndef Ellipse_h
#define Ellipse_h

#include "Vector3D.h"

class Ellipse
{
private:
	Vector3D _Center, _MajorAxis, _MinorAxis;
	double _MinorRadius, _MajorRadius;

public:

	Ellipse(Vector3D center, Vector3D majorAxis, Vector3D minorAxis, double majorRadius, double minorRadius);


	Vector3D GetCenter()
	{
		return _Center;
	}
	Vector3D GetMajorAxis()
	{
		return _MajorAxis;
	}
	Vector3D GetMinorAxis()
	{
		return _MinorAxis;
	}


	double GetMinorRadius()
	{
		return _MinorRadius;
	}
	double GetMajorRadius()
	{
		return _MajorRadius;
	}


	void SetCenter(Vector3D center)
	{
		_Center = center;
	}
	void SetMajorAxis(Vector3D axis)
	{
		_MajorAxis = axis;
	}
	void SetMinorAxis(Vector3D axis)
	{
		_MinorAxis = axis;
	}

	void SetMajorRadius(double radius)
	{
		_MajorRadius = radius;
	}
	void SetMinorRadius(double radius)
	{
		_MinorRadius = radius;
	}
};

#endif