#include "route.h"

Route::Route() : finalCost(0.0), finalTime(0.0){
}

void Route::addAllCities(DSString aCity){
    citiesInRoutes.pushBack(aCity);
}

void Route::addAllAirlines(DSString aAirline){
    cityAirline.pushBack(aAirline);
}

double Route::getFinalTime(){
    return finalTime;
}

double Route::getFinalCost(){
    return finalCost;
}

void Route::setFinalCost(double totalCost){
    if(totalCost > 0)
        finalCost = totalCost;
    else{
        cout << "Error: Cost" << endl;
    }
}

void Route::setFinalTime(double finalFlightTime){
    if(finalFlightTime > 0)
        finalTime = finalFlightTime;
    else{
        cout << "Error: Time" << endl;
    }
}


void Route::printToFile(int pathNumber, ofstream&outFile){
    outFile << "Path " << pathNumber << ": ";

    for(int i = 0; i < citiesInRoutes.getSize()-1; i++){
        if(i == 0){
            outFile << citiesInRoutes[i] << " -> ";
        }
        else{
            outFile << citiesInRoutes[i] << "("  << cityAirline[i - 1] << ") -> ";
        }
    }

    outFile << citiesInRoutes[citiesInRoutes.getSize()-1] << "(" << cityAirline[cityAirline.getSize() - 1]<<  "). Time: " << fixed << setprecision(0)
         << finalTime << " Cost: " << fixed << setprecision(2) << finalCost << "\n";

}
