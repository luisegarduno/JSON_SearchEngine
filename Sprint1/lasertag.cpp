#include "lasertag.h"
#include "team.h"
#include "dsstring.h"
#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::ifstream;

LaserTag::LaserTag(){
    cout << "\nin default LaserTag constructor" << endl;
}

LaserTag::LaserTag(char * argv[]){

    DSString ATeamName(argv[1]);
    Team TeamA(ATeamName);

    DSString BTeamName(argv[2]);
    Team TeamB(BTeamName);



}
