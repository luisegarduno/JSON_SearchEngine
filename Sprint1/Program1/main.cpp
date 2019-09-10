#include <iostream>
#include "lasertag.h"

using namespace std;

int main(int argc,char * argv[]){

    if(argc != 7){
        cout << argv[0] << endl;
        cout << argv[1] << endl;
        cout << "Error, missing files" << endl;
        return -1;
    }

    LaserTag newGame(argv);
    cout << endl;

    return 0;
}
