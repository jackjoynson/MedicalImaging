#ifndef CALCULATETHETA_H
#define CALCULATETHETA_H

#include "ReadCCData.h"
#include <math.h>

#include <vector>

class CalculateTheta
{
public:
    CalculateTheta(vector<EventEntry> Events);

    vector<double> getThetas(){
        return _Thetas;
    }

    int getInvalidThetaCount(){
        return _invalidThetaCount;
    }
    int getValidThetaCount(){
        return _validThetaCount;
    }


private:
    vector<double> _Thetas;
    int _invalidThetaCount;
    int _validThetaCount;

};

#endif // CALCULATETHETA_H
