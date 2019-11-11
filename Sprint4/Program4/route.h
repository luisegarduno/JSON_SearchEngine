#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dsstack.h"
#include "dsvector.h"
#include "flightdata.h"

using std::fixed;
using std::ofstream;
using std::setprecision;

class Route{
    private:
        DSVector<DSString> citiesInRoutes;
        DSVector<DSString> cityAirline; // parallel vector to citiesInRoutes
        double finalCost;
        double finalTime;

    public:
        Route();

        Route& addRoute(DSStack<FlightData>&);
        void addAllCities(DSString);
        void addAllAirlines(DSString);

        void setFinalCost(double);      // setters
        void setFinalTime(double);

        double getFinalTime();          // getters
        double getFinalCost();

        void printToFile(int,ofstream&);

};

#endif // ROUTE_H
