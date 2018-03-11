#ifndef FINDAVERAGESTDEV_H
#define FINDAVERAGESTDEV_H

#include <math.h>
#include <vector>
using namespace std;


class FindAverageStdev
{
public:
    FindAverageStdev(vector<double> Thetas);

    double getAvg(){
        return _averageTheta;
    }

    double getStdev(){
        return _stdevTheta;
    }



private:
    double _averageTheta;
    double _stdevTheta;
};

#endif // FINDAVERAGESTDEV_H
