#include "flightplanner.h"

using std::getline;

FlightPlanner::FlightPlanner(){

}

void FlightPlanner::setFileNames(char * argv[]){
    flightDataFile = argv[1];
    pathsToCalculateFile = argv[2];
    flightEfficiencyFile = argv[3];
}

void FlightPlanner::addFlightsData(){
    streamFlightData.open(flightDataFile.c_str());

    if(!streamFlightData.is_open()){
        cout << "Flight Data File is not open. Please check command line input" << endl;
        exit(-1);
    }

    int numberOfFlights;
    double theCost = 0.0,theTime = 0.0;
    DSString theOrigin(""),theDestination(""),theAirline("");
    streamFlightData >> numberOfFlights;

    char temp[100];
    streamFlightData.getline(temp,100);

    char * buffer = new char[100];


    for(int i = 0; i < numberOfFlights; i++){
        for(int j = 0; j < 5; j++){
            if(j == 0){
                streamFlightData.getline(buffer,100,'|');
                theOrigin = buffer;
                cout << "Origin: " << theOrigin << endl;
            }
            if(j == 1){
                streamFlightData.getline(buffer,100,'|');
                theDestination = buffer;
                cout << "Destination: " << theDestination << endl;
            }
            if(j == 2){
                streamFlightData >> theCost;
                streamFlightData.getline(buffer,100,'|');
                cout << "Cost: " << theCost << endl;
            }
            if(j == 3){
                streamFlightData >> theTime;
                streamFlightData.getline(buffer,100,'|');
                cout << "Time: " << theTime << endl;
            }
            if(j == 4){
                streamFlightData.getline(buffer,100);
                theAirline = buffer;
                cout << "Airline: " << theAirline << endl;
            }
        }
        FlightData newFlight(theOrigin,theDestination,theCost,theTime,theAirline);
        flightPaths.add(newFlight);
        flightPaths.add(newFlight.flightDataReversed());
        cout << endl;
    }

    flightPaths.printAdjacencyList();

    streamFlightData.close();
    delete [] buffer;
}



void FlightPlanner::requestedRoutes(){

}
