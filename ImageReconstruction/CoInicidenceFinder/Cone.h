#ifndef Cone_h
#define Cone_h
class Cone
{

private:
	double _StartX, _StartY, _StartZ;
	double _DirectionX, _DirectionY, _DirectionZ;
	double _HalfAngle;

public:

	Cone(double startX, double startY, double startZ, double directionX, double directionY, double directionZ, double halfAngle);
	
	double GetStartX()
	{
		return _StartX;
	}

	double GetStartY()
	{
		return _StartY;
	}

	double GetStartZ()
	{
		return _StartZ;
	}




	double GetDirectionX()
	{
		return _DirectionX;
	}

	double GetDirectionY()
	{
		return _DirectionY;
	}

	double GetDirectionZ()
	{
		return _DirectionZ;
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
	void SetStartZ(double startZ)
	{
		_StartZ = startZ;
	}


	void SetDirectionX(double dirX)
	{
		_DirectionX = dirX;
	}
	void SetDirectionY(double dirY)
	{
		_DirectionY = dirY;
	}
	void SetDirectionZ(double dirZ)
	{
		_DirectionZ = dirZ;
	}


	void SetHalfAngle(double halfAngle)
	{
		_HalfAngle = halfAngle;
	}
};

#endif