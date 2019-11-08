#include "flightdata.h"

FlightData::FlightData() : origin(""), destination(""), cost(0.0), time(0.0), airline("") {
}

// FlightData is passed with origin,destination,cost,time, & airline to set FlightData Object variables
FlightData::FlightData(DSString originData, DSString destinationData, double costData, double timeData, DSString airlineData)
    : origin(originData), destination(destinationData), cost(costData), time(timeData), airline(airlineData) {
}

FlightData FlightData::flightDataReversed(){

    DSString newOrigin = getDestination();
    DSString newDestination = getOrigin();
    double newCost = getCost();
    double newTime = getTime();
    DSString newAirline = getAirline();

    FlightData flightReversed(newOrigin,newDestination,newCost,newTime,newAirline);

    return flightReversed;
}

FlightData::FlightData(const FlightData& original){
    *this = original;
}

FlightData& FlightData::operator=(const FlightData& original){
    setOrigin(original.origin);
    setDestination(original.destination);
    setCost(original.cost);
    setTime(original.time);
    setAirline(original.airline);
}

// Declares Origin
void FlightData::setOrigin(DSString newOrigin){
    this->origin = newOrigin;
}

// Declares Destination
void FlightData::setDestination(DSString newDestination){
    this->destination = newDestination;
}

// Declares cost of flight
void FlightData::setCost(double newCost){
   this->cost = newCost;
}

// Declares length of flight
void FlightData::setTime(double newTime){
    this->time = newTime;
}

// Declares Airline
void FlightData::setAirline(DSString newAirline){
    this->airline = newAirline;
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

