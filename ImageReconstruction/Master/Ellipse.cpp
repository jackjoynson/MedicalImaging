using namespace std;

class Ellipse
{
	private double _CenterX, _CenterY, _XAxisRadius, _YAxisRadius;

	public double GetCenterX()
	{
		return _CenterX;
	}
	public double GetCenterY()
	{
		return _CenterY;
	}

	public double GetXRadius()
	{
		return _XAxisRadius;
	}
	public double GetYRadius()
	{
		return _YAxisRadius;
	}


	public void SetCenterX(double centerX)
	{
		_CenterX = centerX;
	}
	public void SetCenterY(double centerY)
	{
		_CenterY = centerY;
	}
	public void SetXRadius(double xRadius)
	{
		_XAxisRadius = xRadius;
	}
	public void SetYRadius(double yRadius)
	{
		_YAxisRadius = yRadius;
	}
}