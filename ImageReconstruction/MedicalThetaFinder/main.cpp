#include <iostream>
#include "ReadCCData.h"
#include "calculatetheta.h"
#include "findaveragestdev.h"

#include <vector>

using namespace std;

int main()
{
    //Getting events
    string file;
    cout << "Please enter the filepath from the file" << endl;
    cin >> file;

    int detectorNumber;
    cout << "How many detectors?" << endl;
    cin >>  detectorNumber;

    vector<DetectorType> detectors;

    for(int i = 0; i < detectorNumber; i++){
        int type;
        cout << "Please enter the 1 if detector " << i << " is scatter, 0 if not." << endl;
        cin >> type;

        DetectorType detector;
        if(type == 1){
            detector.setIsScatter(true);
        }
        else if(type == 0){
            detector.setIsScatter(false);
        }
        else{
            cout << "Please enter a valid input" << endl;
        }
        detectors.push_back(detector);
    }




    ReadCoincData RCD;
    vector<EventEntry> Events = RCD.GetEvents(file, detectors);

    CalculateTheta CT(Events);
    vector<double> Thetas = CT.getThetas();

    FindAverageStdev FAS(Thetas);
    double AvgTheta = FAS.getAvg();
    double AvgStdev = FAS.getStdev();


    cout << "Number of invalid events from summing energies is " << RCD.getInvalidEnergyCounter() << endl;
    cout << "Number of invalid events from theta is " << CT.getInvalidThetaCount() << endl;
    cout << "Number of valid thetas & events is " << CT.getValidThetaCount() << endl;
    cout << "The average theta is " << AvgTheta << "and the average standard deviation is " << AvgStdev << endl;



}
