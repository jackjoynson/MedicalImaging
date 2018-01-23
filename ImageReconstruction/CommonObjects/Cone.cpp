
using namespace std;

class Cone
{
	
	private double _StartX, _StartY, _StartZ;

	private double _DirectionX, _DirectionY, _DirectionZ;

	private double _HalfAngle;




	public double GetStartX()
	{
		return _StartX;
	}

	public double GetStartY()
	{
		return _StartY;
	}

	public double GetStartZ()
	{
		return _StartZ;
	}




	public double GetDirectionX()
	{
		return _DirectionX;
	}

	public double GetDirectionY()
	{
		return _DirectionY;
	}

	public double GetDirectionZ()
	{
		return _DirectionZ;
	}


	public double GetHalfAngle() 
	{
		return _HalfAngle;
	}





	public void SetStartX(double startX)
	{
		_StartX = startX;
	}
	public void SetStartY(double startY)
	{
		_StartY = startY;
	}
	public void SetStartZ(double startZ)
	{
		_StartZ = startZ;
	}


	public void SetDirectionX(double dirX)
	{
		_DirectionX = dirX;
	}
	public void SetDirectionY(double dirY)
	{
		_DirectionY = dirY;
	}
	public void SetDirectionZ(double dirZ)
	{
		_DirectionZ = dirZ;
	}


	public void SetHalfAngle(double halfAngle)
	{
		_HalfAngle = halfAngle;
	}

};