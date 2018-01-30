#ifndef Cone_h
#define Cone_h
class Cone
{

private:
	double _StartX, _StartY;
	double _XImagePlane;
	double _HalfAngle;

public:

	Cone(double startX, double startY, double xImagePlane, double halfAngle);
	
	double GetStartX()
	{
		return _StartX;
	}

	double GetStartY()
	{
		return _StartY;
	}




	double GetXImagePlane()
	{
		return _XImagePlane;
	}



	double GetHalfAngle()
	{
		return _HalfAngle;
	}





	void SetStartX(double startX)
	{
		_StartX = startX;
	}
	void SetStartY(double startY)
	{
		_StartY = startY;
	}


	void SetXImagePlane(double xPos)
	{
		_XImagePlane = xPos;
	}


	void SetHalfAngle(double halfAngle)
	{
		_HalfAngle = halfAngle;
	}
};

#endif