
#ifndef Ellipse_h
#define Ellipse_h


class Ellipse
{
private:
	double _CenterX, _CenterY, _XAxisRadius, _YAxisRadius;

public:

	Ellipse(double centerX, double centerY, double xRadius, double yRadius);


	double GetCenterX()
	{
		return _CenterX;
	}
	double GetCenterY()
	{
		return _CenterY;
	}

	double GetXRadius()
	{
		return _XAxisRadius;
	}
	double GetYRadius()
	{
		return _YAxisRadius;
	}


	void SetCenterX(double centerX)
	{
		_CenterX = centerX;
	}
	void SetCenterY(double centerY)
	{
		_CenterY = centerY;
	}
	void SetXRadius(double xRadius)
	{
		_XAxisRadius = xRadius;
	}
	void SetYRadius(double yRadius)
	{
		_YAxisRadius = yRadius;
	}
};

#endif