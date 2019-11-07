#ifndef FLIGHTPLANNER_H
#define FLIGHTPLANNER_H

#include <fstream>
#include <iostream>
#include "dsstack.h"
#include "dsstring.h"
#include "dsvector.h"
#include "dslinkedlist.h"
#include "adjacencylist.h"

using std::fstream;
using std::ifstream;



class FlightPlanner{
    private:
        AdjacencyList<FlightData> flightPaths;

        DSString flightDataFile;
        DSString flightEfficiencyFile;
        DSString pathsToCalculateFile;

        ifstream streamFlightData;
        ifstream streamPathsToCalculate;

    public:
        FlightPlanner();
        void addFlightsData();
        void setFileNames(char* argv[]);
        void requestedRoutes();
};

#endif // FLIGHTPLANNER_H
