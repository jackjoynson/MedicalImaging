
#define _USE_MATH_DEFINES
#include <cmath>  
#include <vector>
#include <algorithm>

#include "GenerateMatrix.h"

using namespace std;

GenerateMatrix::GenerateMatrix()
{}


bool BeenPoint(vector<int> xV, vector<int> yV, int x, int y)
{
	for (int i = 0; i < xV.size(); i++)
	{
		return (xV[i] == x && yV[i] == y);
	}

}

vector<vector<int> > GenerateMatrix::GetValues(vector<Ellipse> ellipses)
{
	double width = 1; //meter
	double height = 1; //meter
	int matrixIntervals = 100; //Matrix intervals

	//Any offset. Currently centered around (0,0)
	double xOffset = 0.5;
	double yOffset = 0.5;


	int thetaIntervals = 1000;
	double thetaH = 2 * M_PI / thetaIntervals;

	//first index is x. Second is y.
	vector<vector<int> > matrix;

	//Allocate to size
	matrix.resize(matrixIntervals);
	for (int i = 0; i < matrixIntervals; i++)
		matrix[i].resize(matrixIntervals);
	


	//Loop through each Ellipse
	for (size_t ellipseIndex = 0; ellipseIndex < ellipses.size(); ellipseIndex++)
	{

		//ANGLE TAKEN CLOCKWISE FROM TOP

		vector<int> xIndexes;
		vector<int> yIndexes;


		Ellipse ellipse = ellipses[ellipseIndex];
		double thetaRotation = atan2(ellipse.GetMinorAxis().getX(), ellipse.GetMinorAxis().getY());

		for (int thetaStep = 0; thetaStep < thetaIntervals; thetaStep++)
		{
			double theta = (thetaH * thetaStep) + thetaRotation;

			//Calculate ellipse point at specified theta.

			Vector3D center = ellipse.GetCenter();

			double a = ellipse.GetMajorRadius();
			double b = ellipse.GetMinorRadius();

			double radius = a*b / sqrt(pow(a*sin(theta), 2.0) + pow(b*cos(theta), 2.0));

			double x = center.getX() + sin(theta)*radius;
			double y = center.getY() + cos(theta)*radius;

			int xIndex = round((x + xOffset)*matrixIntervals);
			int yIndex = round((y + yOffset)*matrixIntervals);

			//Check within image plane
			if (xIndex > 0 && xIndex < matrixIntervals && yIndex > 0 && yIndex < matrixIntervals)
			{
				xIndexes.push_back(xIndex);
				yIndexes.push_back(yIndex);

				//Check not counted this point before - keeps density equal
				if (!BeenPoint(xIndexes,yIndexes,xIndex,yIndex))
				{
					matrix[xIndex][yIndex]++;
				}
			}
			//ELSE NOT WITHIN GRID.
		}

	}



	return matrix;
}