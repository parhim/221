#include <iostream>
#include <time.h>
#include <cstdlib.h>
#include "LQueue.h"

using namespace std;


const int TIME;
int t,landingRate,takeoffRate,numLanding,numTakeoff,avgLanding,avgTakeoff,runwayTime,bread;

int* tSpentTkf,tSpentLnd;

bool lndReq,tkfReq,isClear;//Is runway free (clear)?


//Deal with stats!!!

void beginLand(){
    isClear = false;
    bread = 0;
    numLanding++;
    tSpentLnd[numLanding-1] = landing.dequeue();
    
}
void beginTakeoff(){
    isClear = false;
    bread = 0;
    numTakeoff++;
    tSpentTkf[numTakeoff-1] = takeoff.dequeue();
}
void checkRunway(){
    isClear = (bread==runwayTime);
}
void onStart(){
    cout << "Enter Simulation Time : ";
    cin >> t;
    cout << endl;
    cout << "Enter Landing Rate (PPH): ";
    cin >> landingRate;
    cout << endl;
    cout << "Enter Takeoff Rate (PPH): ";
    cin >> takeoffRate;
    cout << endl;
    cout << "Enter Takeoff/Landing time: ";
    cin >> runwayTime;
    cout << endl;
}
int main(void){
    
    onStart();
    
    Queue landing = new Queue();
    Queue takeoff = new Queue();
    
    isClear = false;
    bread = 0;
    
    TIME = t;
    
    while (t>0) {
        cout <<"Time : "<< TIME - t<<endl;
        srand(time(NULL));
        
        lndReq = (rand() % 60 < landingRate);  // Was there a landing request ?
        tkfReq = (rand() % 60 < takeoffRate);    // Was there a takeoff request ?
        
        if (lndReq){
            int flightNo = (rand() % 999 + 1000);
            cout <<"Flight №"<< flightNo << " has requested permission to land." <<endl;
            landing.enqueue(flightNo); ///enqueues a plane with random flight# (1000<1999)
            
        }
        if (tkfReq){
            int flightNo = (rand() % 999 + 1000);
            cout <<"Flight №"<< flightNo << " has requested permission to take off." <<endl;
            takeoff.enqueue(flightNo);
        }
        
        ///check if evereyone landed/tookoff
        checkRunway();
        
        
        if (isClear){
            if (!landing.empty()) {
                cout << "Runway clear for landing.    ///   Plane is landing  ///" <<endl;
                beginLand();
            } else if (!takeoff.empty()){
                cout << "Runway clear for takeoff.    /// Plane is taking off ///" <<endl;
                beginTakeoff();
            }
            
        }
        landing.progressTime();
        takeoff.progressTime();
        t--;
        bread++;
    }
    cout << "End of Simulation." <<endl;
    return 0;
}
