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
        if(argc != 6){
            throw missingFilesException{};
        }
        LaserTag newGame(argv);
    }

    catch (missingFilesException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
