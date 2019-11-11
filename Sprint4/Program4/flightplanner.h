#ifndef FLIGHTPLANNER_H
#define FLIGHTPLANNER_H

#include "route.h"
#include <fstream>
#include <iostream>
#include "dsstack.h"
#include "dsstring.h"
#include "dsvector.h"
#include "flightdata.h"
#include "dslinkedlist.h"
#include "requestroute.h"
#include "adjacencylist.h"

using std::fstream;
using std::ifstream;
using std::getline;

class FlightPlanner{

    using nodePtr = DSNode<FlightData>*;
    using iterator = DSStack<nodePtr>;

    private:
        AdjacencyList<FlightData> flightPaths;

        DSString flightDataFile;
        DSString pathsToCalculateFile;
        DSString flightEfficiencyFile;

        ifstream streamFlightData;
        ifstream streamPathsToCalculate;

        int flightNumber;

        bool checkStack(FlightData&,iterator);

    public:
        FlightPlanner();
        void addFlightsData();
        void setFileNames(char* argv[]);
        void requestedRoutes();

        DSVector<iterator> findRoutes(RequestRoute);
        DSVector<Route> getRouteFromStack(DSVector<iterator>);
};

#endif // FLIGHTPLANNER_H
