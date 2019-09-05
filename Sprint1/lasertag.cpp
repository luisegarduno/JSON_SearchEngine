#include "lasertag.h"
#include "team.h"
#include "dsstring.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

LaserTag::LaserTag(){
    cout << "in default LaserTag constructor" << endl;
}

LaserTag::LaserTag(const int argc,char * argv[]){

    DSString teamAFile(argv[1]);
    Team TeamA(teamAFile);
    DSString TeamB(argv[2]);
    DSString matchFile(argv[3]);
}
