#include <iostream>
#include "lasertag.h"

using namespace std;

class missingFilesException{
    public:
        const char * what() {
            return "Missing/invalid number of arguments";
        }
};

int main(int argc,char * argv[]){
    try {
        if(argc != 6){                              // if argument counter != 6,
            throw missingFilesException{};          // throw custom exception
        }
        LaserTag newGame(argv);                     // else, create new LaserTag
    }

    catch (missingFilesException& e) {              // catches custom exception message
        cout << e.what() << endl;
    }

    return 0;
}
