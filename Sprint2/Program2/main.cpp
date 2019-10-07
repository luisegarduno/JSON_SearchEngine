#define CATCH_CONFIG_RUNNER
#include <cstring>
#include <iostream>
#include "catch.hpp"
#include "dsstring.h"
#include "dsvector.h"
#include "classifier.h"

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
            if(argc != 6){                              // if argument counter != 6,
                throw missingFilesException{};          // throw custom exception
            }
            else {
                if(TEST && argc == 1){
                    return runCatchTests(argc, argv);
                }
                else{
                    Classifier test(argv);

                }
            }
        }

        catch (missingFilesException& e) {              // catches custom exception message
            cout << e.what() << endl;
        }

    return 0;
}
