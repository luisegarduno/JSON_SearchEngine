#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "dsstring.h"
#include "flightdata.h"
#include "dslinkedlist.h"
#include "adjacencylist.h"

#define TEST true

using namespace std;

class missingFilesException{
    public:
        const char * what() {
            return "Missing/invalid number of arguments";
        }
};

int runCatchTests(int argc, char* argv[]){
    // Runs test.cpp using Catch2 lib
    return Catch::Session().run(argc,argv);
}


int main(int argc, char * argv[]){
    try {
            if(argc != 4 && argc != 1){                 // if argument counter != 4 or 1,
                throw missingFilesException{};          // throw custom exception
            }
            else if(TEST && argc == 1){
                return runCatchTests(argc, argv);
            }
            else {

                DSString dallas = "Dallas";
                DSString austin = "Austin";
                DSString chicago = "Chicago";
                DSString houston = "Houston";


                DSString spirit = "Sprit";
                DSString american = "American";
                DSString united = "United";

                FlightData flight1(dallas,austin,98.0,47.0,spirit);
                FlightData flight2(dallas,austin,98.0,59.0,american);
                FlightData flight3(austin,houston,95.0,39.0,united);
                FlightData flight4(dallas,houston,101.0,51.0,spirit);
                FlightData flight5(austin,chicago,144.0,192.0,american);

                AdjacencyList<FlightData> newList;
                newList.add(flight1);
                newList.add(flight1.flightDataReversed());
                newList.add(flight2);
                newList.add(flight2.flightDataReversed());
                newList.add(flight3);
                newList.add(flight3.flightDataReversed());
                newList.add(flight4);
                newList.add(flight4.flightDataReversed());
                newList.add(flight5);
                newList.add(flight5.flightDataReversed());

                newList.printAdjacencyList();
            }
        }

        catch (missingFilesException& e) {              // catches custom exception message
            cout << e.what() << endl;
        }

    return 0;
}

