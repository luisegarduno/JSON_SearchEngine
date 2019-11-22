#include <iostream>
#include "parser.h"

using namespace std;

class missingFilesException{
    public:
        const char * what() {
            return "Missing/invalid number of arguments";
        }
};

int main(int argc, char *argv[]){
    try {
        if(argc != 3)                           // if argument counter != 3,
            throw missingFilesException{};      // throw custom exception

        else {
            Parser newParse = Parser(argv);
            cout << "Number of files Indexed: " << newParse.getSizeOfFolder() << endl;
            cout << "done" << endl;
        }
     }

    catch (missingFilesException& e) {              // catches custom exception message
        cout << e.what() << endl;
    }

    return 0;
}
