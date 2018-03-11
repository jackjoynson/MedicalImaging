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

private:
    vector<double> _Thetas;

};

#endif // CALCULATETHETA_H
