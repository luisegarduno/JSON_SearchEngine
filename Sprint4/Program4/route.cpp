#include "route.h"

Route::Route() : finalCost(0.0), finalTime(0.0){
}

Route& Route::addRoute(DSStack<FlightData>& currentStack){
    FlightData newFlight;

    if(!currentStack.isEmpty()){
        newFlight = currentStack.pop();

        this->citiesInRoutes.pushBack(newFlight.getOrigin());
        this->cityAirline.pushBack(newFlight.getOrigin());

        this->citiesInRoutes.pushBack(newFlight.getDestination());
        this->cityAirline.pushBack(newFlight.getDestination());

        finalCost += newFlight.getCost();
        finalTime += newFlight.getTime();

        while(!currentStack.isEmpty()){
            newFlight = currentStack.pop();
            this->citiesInRoutes.pushBack(newFlight.getDestination());
            this->cityAirline.pushBack(newFlight.getAirline());
            finalCost += newFlight.getCost();
            finalTime += newFlight.getTime();
        }

        return *this;


    }

    else{
        return *this;
    }
}


void Route::addTimeLayover(){
    finalTime += 43.00;
}
void Route::addCostMisc(){
    finalCost += 19.00;
}

double Route::getFinalTime(){
    return finalTime;
}

double Route::getFinalCost(){
    return finalCost;
}
