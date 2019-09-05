#include "lasertag.h"
#include "team.h"
#include "dsstring.h"
#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::ifstream;

LaserTag::LaserTag(){
    cout << "in default LaserTag constructor" << endl;
}

LaserTag::LaserTag(char * argv[]){

    DSString TeamA;
    DSString TeamB;
    ifstream aFile;
    aFile.open(argv[1]);
    aFile >> TeamA;
    cout << TeamA << endl;


}
