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
        if(argc != 6)
            throw missingFilesException{};
        LaserTag newGame(argv);
    }

    catch (missingFilesException& e) {
        cout << e.what() << endl;
    }

    cout << "\n--------------------------------" << endl;
    cout << "PROGRAM HAS TERMINATED CORRECTLY" << endl;
    cout << "--------------------------------" << endl;

    return 0;
}

/*fstream aFile(outputFile.c_str());
aFile << teamNameA << ": " << totalA << " points\n";
aFile << teamNameB << ": " << totalB << " points\n";
if(totalA > totalB){
    aFile << "Overall Winners: " << teamNameA;
}
if(totalA > totalB){
    aFile << "Overall Winners: " << teamNameB;
}
if(totalA == totalB){
    aFile << "Overall Winners: it's a draw!";
}
aFile.close();*/
