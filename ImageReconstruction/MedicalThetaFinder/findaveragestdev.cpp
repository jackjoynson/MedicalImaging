#include "findaveragestdev.h"

FindAverageStdev::FindAverageStdev(vector<double> Thetas)
{
    double TotalTheta = 0.0;
    for(int i = 0; i < Thetas.size(); i++)
    {
        TotalTheta += Thetas[i];
    }

    _averageTheta = TotalTheta/Thetas.size();

    double TotalDiffTheta = 0;
    for(int i = 0; i < Thetas.size(); i++)
    {
        TotalDiffTheta += fabs(Thetas[i] - _averageTheta);
    }

    _stdevTheta = sqrt(TotalDiffTheta/(Thetas.size() - 1))

}
