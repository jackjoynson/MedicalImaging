#ifndef Cone_h
#define Cone_h
class Cone
{

private:
	double _StartX, _StartY;
    double _XImagePlane, _YImagePlane;
	double _HalfAngle;

public:

    Cone(double startX, double startY, double xImagePlane, double yImagePlane ,double halfAngle);
	
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

    double GetYImagePlane()
    {
        return _YImagePlane;
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

    void SetYImagePlane(double yPos)
    {
        _YImagePlane = yPos;
    }


	void SetHalfAngle(double halfAngle)
	{
		_HalfAngle = halfAngle;
	}
};

#endif
