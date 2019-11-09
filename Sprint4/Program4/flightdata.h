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
        FlightData& operator=(const FlightData&);
        FlightData(const FlightData&);
        FlightData(DSString, DSString, double, double, DSString);
        FlightData flightDataReversed();

        // create setter & getter functions for each of the Flight Data paramter

        void setOrigin(DSString);
        void setDestination(DSString);
        void setCost(double);
        void setTime(double);
        void setAirline(DSString);

        DSString getOrigin();
        DSString getDestination();
        double getCost();
        double getTime();
        DSString getAirline();
};

#endif // FLIGHTDATA_H
