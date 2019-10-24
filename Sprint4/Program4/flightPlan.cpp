#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "dsstring.h"
#include "dsvector.h"

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

            }
        }

        catch (missingFilesException& e) {              // catches custom exception message
            cout << e.what() << endl;
        }

    return 0;
}

