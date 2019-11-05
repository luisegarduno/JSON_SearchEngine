#include "flightdata.h"

FlightData::FlightData() : origin(""), destination(""), cost(0.0), time(0.0), airline("") {
}

// FlightData is passed with origin,destination,cost,time, & airline to set FlightData Object variables
FlightData::FlightData(DSString originData, DSString destinationData, double costData, double timeData, DSString airlineData)
    : origin(originData), destination(destinationData), cost(costData), time(timeData), airline(airlineData) {
}

// returns name of Origin City
DSString FlightData::getOrigin(){
    return origin;
}

// returns name of Destination City
DSString FlightData::getDestination(){
    return destination;
}

// returns cost of flight
double FlightData::getCost(){
    return cost;
}


// returns length of flight (in minutes)
double FlightData::getTime(){
    return time;
}

// returns name of airline
DSString FlightData::getAirline(){
    return airline;
}
