#include "calculatetheta.h"

CalculateTheta::CalculateTheta(vector<EventEntry> Events)
{

    for(int i = 0; i < Events.size(); i++){     //For all events
        EventEntry thisEvent = Events[i];
        double Energy = thisEvent.GetEnergy();
        double TotalEnergy = thisEvent.GetTotalEnergy();


        double Theta;
        double cosTheta = fabs((Energy*0.511)/(TotalEnergy*TotalEnergy-TotalEnergy*Energy));

        if(cosTheta <= 1.0){
            Theta = acos((Energy*0.511)/(TotalEnergy*TotalEnergy-TotalEnergy*Energy));
            _Thetas.push_back(Theta);
        }
        else{
            _invalidThetaCount++;
        }

    }

}

