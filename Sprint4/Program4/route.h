#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include "dsstack.h"
#include "dsvector.h"
#include "flightdata.h"

class Route{
    private:
        DSVector<DSString> citiesInRoutes;
        DSVector<DSString> cityAirline; // parallel vector to citiesInRoutes
        double finalCost;
        double finalTime;

    public:
        Route();

        Route& addRoute(DSStack<FlightData>&);

        void addTimeLayover();    // setters
        void addCostMisc();

        double getFinalTime();          // getters
        double getFinalCost();

};

#endif // ROUTE_H
