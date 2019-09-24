#define CATCH_CONFIG_RUNNER
#include <cstring>
#include <iostream>
#include "catch.hpp"

#define TEST true

using namespace std;

int runCatchTests(int argc, char* argv[]){
    // This line of code causes the Catch library to
    // run the tests in the project.
    return Catch::Session().run(argc,argv);
}


int main(int argc, char * argv[]){


    if(TEST && argc == 1){
        return runCatchTests(argc, argv);
    }
    else{
        cout << "6" << endl;
    }


    return 0;
}
