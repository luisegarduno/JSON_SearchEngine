#ifndef FLIGHTPLANNER_H
#define FLIGHTPLANNER_H

#include <iostream>
#include "dsstack.h"
#include "dsstring.h"
#include "dsvector.h"
#include "adjacencylist.h"



class FlightPlanner{
    private:
        DSString flightDataFile;
        DSString flightEfficiencyFile;
        DSString pathsToCalculateFile;

    public:
        FlightPlanner();
        void addFlightsData();
        void setFileNames(char* argv[]);
        void requestedRoutes();
};

#endif // FLIGHTPLANNER_H
