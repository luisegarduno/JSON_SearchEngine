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
                double cost = 15.99;
                double time = 68.2;
                DSString airline = "American";

                //cout << "here 1" << endl;
                FlightData newFlightData(dallas,austin,cost,time,airline);

                //cout << "out flightData" << endl;

                AdjacencyList<FlightData> newList;
                newList.add(newFlightData);

            }
        }

        catch (missingFilesException& e) {              // catches custom exception message
            cout << e.what() << endl;
        }

    return 0;
}

