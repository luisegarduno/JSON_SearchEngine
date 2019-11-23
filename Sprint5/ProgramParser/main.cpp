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

            cout << "\n/*******************************************************************\\" << endl;
            cout << "\tTotal Nodes: " << newParse.getTotNumNodes() << endl;
            cout << "\tTotal Number of Files '" << argv[2] << "' appears in: " << newParse.getTotDocsFound() << endl;
            cout << "\tTotal Number of appearances: " << newParse.getTotNumOfAppearances() << endl;
            cout << "/*******************************************************************\\" << endl;

            cout << "Exiting Program" << endl;
        }
     }

    catch (missingFilesException& e) {              // catches custom exception message
        cout << e.what() << endl;
    }

    return 0;
}
