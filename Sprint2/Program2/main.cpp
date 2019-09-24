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

    //if(argc > 1 && strcmp(argv[1], "-t") == 0){
        if(TEST){
            return runCatchTests(argc, argv);
        }
    //}
        //else if(argc > 1 && strcmp(argv[1], "-c") == 0){
          //  cout << "6" << endl;
        //}


    return 0;
}