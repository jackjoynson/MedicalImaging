#include "calculatetheta.h"

CalculateTheta::CalculateTheta(vector<EventEntry> Events)
{

    for(int i = 0; i < Events.size(); i++){     //For all events
        EventEntry thisEvent = Events[i];
        double Energy = thisEvent.GetEnergy();
        double TotalEnergy = thisEvent.GetTotalEnergy();


        double Theta;
        double cosTheta = 1.0 - (Energy*0.511)/(TotalEnergy*TotalEnergy-TotalEnergy*Energy);

        if(fabs(cosTheta) <= 1.0){

            Theta = acos(cosTheta);

            if(Theta <= 1.57 && Theta >= 0){
                 _Thetas.push_back(Theta);
                 _validThetaCount++;
            }
            else{

            }
        }
        else{
            _invalidThetaCount++;
        }

    }

}

