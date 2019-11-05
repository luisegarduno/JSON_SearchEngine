#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

#include <iostream>
#include "dsstring.h"


class FlightData{
    private:
        DSString origin;
        DSString destination;
        double cost;
        double time;
        DSString airline;

    public:
        FlightData();
        FlightData(DSString, DSString, double, double, DSString);

        // create getter functions for each of the Flight Data paramter

        DSString getOrigin();
        DSString getDestination();
        double getCost();
        double getTime();
        DSString getAirline();
};

#endif // FLIGHTDATA_H