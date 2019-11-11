#include "flightplanner.h"

FlightPlanner::FlightPlanner() : flightNumber(1){         // Default Constructor
}

// The names of the of the command line arguments are used to create &
// instantiate private DSStrings that are the file names
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
    streamFlightData >> numberOfFlights;

    char temp[100];
    streamFlightData.getline(temp,100);

    double theCost = 0.0,theTime = 0.0;
    DSString theOrigin(""),theDestination(""),theAirline("");

    char * buffer = new char[100];

    for(int i = 0; i < numberOfFlights; i++){
        for(int j = 0; j < 5; j++){
            if(j == 0){
                streamFlightData.getline(buffer,100,'|');
                theOrigin = buffer;
            }
            if(j == 1){
                streamFlightData.getline(buffer,100,'|');
                theDestination = buffer;
            }
            if(j == 2){
                streamFlightData >> theCost;
                streamFlightData.getline(buffer,100,'|');
            }
            if(j == 3){
                streamFlightData >> theTime;
                streamFlightData.getline(buffer,100,'|');
            }
            if(j == 4){
                streamFlightData.getline(buffer,100);
                theAirline = buffer;
            }
        }
        FlightData newFlight(theOrigin,theDestination,theCost,theTime,theAirline);
        flightPaths.add(newFlight);

        FlightData reversedFlight(theDestination,theOrigin,theCost,theTime,theAirline);
        flightPaths.add(reversedFlight);
    }
    streamFlightData.close();
    delete [] buffer;
}

void FlightPlanner::requestedRoutes(){
    streamPathsToCalculate.open(pathsToCalculateFile.c_str());

    if(!streamPathsToCalculate.is_open()){
        cout << "Paths To Calculate File is not open. Please check command line input" << endl;
        exit(-1);
    }

    int numberOfRequested;
    streamPathsToCalculate >> numberOfRequested;

    char temp[100];
    streamPathsToCalculate.getline(temp,100);

    DSString theOrigin(""),theDestination(""),sortType("");
    char * buffer = new char[100];

    for(int i = 0; i < numberOfRequested; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
                streamPathsToCalculate.getline(buffer,100,'|');
                theOrigin = buffer;
            }

            if(j == 1){
                streamPathsToCalculate.getline(buffer,100,'|');
                theDestination = buffer;
            }

            if(j == 2){
                streamPathsToCalculate.getline(buffer,100);
                sortType = buffer;
            }
        }
        RequestRoute newRoute(theOrigin,theDestination,sortType);
        DSVector<iterator> findAllRoutes = findRoutes(newRoute);
        DSVector<Route> allFlightRoutes = getRouteFromStack(findAllRoutes);
        allFlightRoutes = routeSorter(allFlightRoutes,sortType);
        outputRouteToFile(allFlightRoutes,newRoute);

    }

    streamPathsToCalculate.close();
    delete [] buffer;
}



// REMEMBER LIFO, LAST IN, FIRST OUT ---> SO the 'TOP' will be the LAST IN,
// Thus we make the last item appended be declared as the head
// USING nodePtr = DSNode<FlightData>*;             USING customStackIterator = DSStack<nodePtr>;
DSVector<FlightPlanner::iterator> FlightPlanner::findRoutes(RequestRoute requestedRoute){ // TO SEE HIGH LEVEL STEPS FOR ITERATIVE BACKTRACKING
    iterator currentIterator;                                                               // GO TO LINE
    DSStack< DSLinkedList<FlightData> > routeOnStack; // create a stack containing routes
    DSVector<iterator> currentStackInVector;

    routeOnStack.push(flightPaths.getAllOrigins(requestedRoute.getRequestedOrigin()));
    nodePtr currentNodeOnStack =  routeOnStack.topValue().head;

    do{
        if(currentNodeOnStack == nullptr){
            bool allRoutesFound = false;

            while(currentNodeOnStack == nullptr){
                routeOnStack.pop();

                if(routeOnStack.isEmpty()){
                    allRoutesFound = true;
                    break;
                }

                currentNodeOnStack = currentIterator.pop();
                currentNodeOnStack = currentNodeOnStack->next;
                while(currentNodeOnStack != nullptr && checkStack(currentIterator,currentNodeOnStack->data.getDestination())){
                    currentNodeOnStack = currentNodeOnStack->next;
                }
            }

            if(allRoutesFound){
                break;
            }
        }

        // **********************TOP IS DESTINATION***********************************
        // If Node located on stack contains getDestination that's the same as the requested Destination
        if(currentNodeOnStack->data.getDestination() == requestedRoute.getRequestedDestination()){
            currentIterator.push(currentNodeOnStack);
            currentStackInVector.pushBack(currentIterator);

            currentIterator.pop();
            currentNodeOnStack = currentNodeOnStack->next;
            while(currentNodeOnStack != nullptr && checkStack(currentIterator,currentNodeOnStack->data.getDestination())){
                currentNodeOnStack = currentNodeOnStack->next;
            }
        }
        // **********************************************************************

        // ********************Adding LinkedList to DSStack *********************//
        if(currentNodeOnStack != nullptr){
            currentIterator.push(currentNodeOnStack);

            routeOnStack.push(flightPaths.getAllOrigins(currentNodeOnStack->data.getDestination()));
            currentNodeOnStack = routeOnStack.topValue().head;

            while(currentNodeOnStack != nullptr && checkStack(currentIterator,currentNodeOnStack->data.getDestination())){
                currentNodeOnStack = currentNodeOnStack->next;
            }
        }
        // *********************************************************************//


    }while(true);

    return currentStackInVector;
}

bool FlightPlanner::checkStack(iterator currentStack, DSString aCity){
    nodePtr top = nullptr;

    while(!currentStack.isEmpty()){
        top = currentStack.pop();
        if(top->data.getOrigin() == aCity || top->data.getDestination() == aCity){
            return true;
        }
    }
    return false;
}

DSVector<Route> FlightPlanner::getRouteFromStack(DSVector<iterator> routeOnStackVector){
    DSStack<FlightData> routeOnStack;
    DSVector<Route> routeOnVector;

    for(int counter = 0; counter < routeOnStackVector.getSize(); counter++){
        while(!routeOnStackVector.isEmpty()){
            DSNode<FlightData>* currentFlightPtr = routeOnStackVector[counter].pop();
            routeOnStack.push(currentFlightPtr->data);
        }

        Route flightRoute;
        double totalTime = 0.0;
        double totalCost = 0.0;

        FlightData newFlightPlan = routeOnStack.pop();

        flightRoute.addAllCities(newFlightPlan.getOrigin());
        flightRoute.addAllAirlines(newFlightPlan.getAirline());

        flightRoute.addAllCities(newFlightPlan.getDestination());
        flightRoute.addAllAirlines(newFlightPlan.getAirline());

        totalCost += newFlightPlan.getCost();
        totalTime += newFlightPlan.getTime();

        while(!routeOnStack.isEmpty()){
            newFlightPlan = routeOnStack.pop();
            flightRoute.addAllCities(newFlightPlan.getDestination());
            flightRoute.addAllAirlines(newFlightPlan.getAirline());
            totalCost += newFlightPlan.getCost();
            totalTime += newFlightPlan.getTime();
        }

        flightRoute.setFinalCost(totalCost);
        flightRoute.setFinalTime(totalTime);

        routeOnVector.pushBack(flightRoute);
    }

    return routeOnVector;
}

DSVector<Route> FlightPlanner::routeSorter(DSVector<Route> graphVector, DSString requestedSort){
    DSVector<Route> flightRouteVect;
        if(requestedSort == "T"){
            int smallestIndex;
            for(int counter = 0; counter  < graphVector.getSize() - 1; counter++){
                smallestIndex = counter;
                for(int j = counter + 1; j < graphVector.getSize(); j++){
                    if(graphVector[j].getFinalTime() < graphVector[smallestIndex].getFinalTime()){
                        smallestIndex = j;
                    }
                }
                if(smallestIndex != counter){
                    Route temp = graphVector[counter];
                    graphVector[counter] = graphVector[smallestIndex];
                    graphVector[smallestIndex] = temp;
                }
            }
        }

        else if(requestedSort == "C"){
            int smallestIndex;
            for(int counter = 0; counter < graphVector.getSize() - 1; counter++){
                smallestIndex = counter;
                for(int j = counter + 1; j < graphVector.getSize(); j++){
                    if(graphVector[j].getFinalCost() < graphVector[smallestIndex].getFinalCost())
                        smallestIndex = j;
                }
                if(smallestIndex != counter){
                    Route temp = graphVector[counter];
                    graphVector[counter] = graphVector[smallestIndex];
                    graphVector[smallestIndex] = temp;
                }
            }
        }

        for(int i = 0; i < 3 && i < graphVector.getSize(); i++){
            flightRouteVect.pushBack(graphVector[i]);
        }

        return flightRouteVect;
}

void FlightPlanner::outputRouteToFile(DSVector<Route> graphVector, RequestRoute finalRoutes){

    streamOutputFile << "Flight " << flightNumber << ": " << finalRoutes.getRequestedOrigin() << ", " << finalRoutes.getRequestedDestination();
    if(finalRoutes.getRequestedSort() == "C"){
        streamOutputFile << " (Cost)\n" << endl;
    }

    else if(finalRoutes.getRequestedSort() == "T"){
        streamOutputFile << " (Time)\n" << endl;
    }

    for(int counter = 0; counter < graphVector.getSize(); counter++){
            graphVector[counter].printToFile(counter + 1, streamOutputFile);
    }

    if(graphVector.getSize() == 0){
        streamOutputFile << "No routes found.\n";
    }
    streamOutputFile << "\n";

    flightNumber++;


}

void FlightPlanner::openOutputFile(){
    streamOutputFile.open(flightEfficiencyFile.c_str());
    if(!streamOutputFile.is_open()){
        cout << "Paths To Calculate File is not open. Please check command line input" << endl;
        exit(-1);
    }
}

void FlightPlanner::closeOutputFile(){
    streamOutputFile.close();
}




/*
1. Push source to DSStack

2. while(stackIsNotEmpty)

    3. if(top == destination)
            |
            --> if TRUE: Store path & pop
            |
            --> if FALSE: step thru iterators of top:
                     |
                     --> if iterator == nullptr
                     |          |
                     |          --> if TRUE: pop top & reset Iterator
                     |          |
                     |          --> if FALSE: continue
                     |
                     |
                     --> if city on stack
                                |
                                --> if TRUE: continue
                                |
                                --> if FALSE: push city, Go to step #3
*/
















