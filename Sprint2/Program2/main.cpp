#define CATCH_CONFIG_RUNNER
#include <cstring>
#include <iostream>
#include "catch.hpp"

#define TEST true

using namespace std;

int runCatchTests(int argc, char* argv[]){
    // This line of code causes the Catch library to
    // run the tests in the project.
    cout << "runCatchTests" << endl;
    return Catch::Session().run(argc,argv);
}


int main(int argc, char * argv[]){
    cout << "1" << endl;

    if(argc > 1 && strcmp(argv[1], "-t") == 0){
        cout << "2" << endl;
        if(TEST){
            cout << "3" << endl;
            return runCatchTests(argc, argv);
        }
        cout << "4" << endl;
    }
        else if(argc > 1 && strcmp(argv[1], "-c") == 0){
            cout << "6" << endl;
        }
        cout << "7" << endl;

    return 0;
}
