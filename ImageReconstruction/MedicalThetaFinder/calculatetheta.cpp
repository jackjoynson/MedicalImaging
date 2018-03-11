#include "calculatetheta.h"

CalculateTheta::CalculateTheta(vector<EventEntry> Events)
{

    for(int i = 0; i < Events.size(); i++){     //For all events
        EventEntry thisEvent = Events[i];
        double Energy = thisEvent.GetEnergy();
        double TotalEnergy = thisEvent.GetTotalEnergy();

        _Thetas[i] = acos((Energy*511)/(TotalEnergy*TotalEnergy-TotalEnergy*Energy));


    }

}

