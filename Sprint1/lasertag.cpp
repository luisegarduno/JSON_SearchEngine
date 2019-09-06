#include "lasertag.h"
#include "team.h"
#include "dsstring.h"
#include <iostream>

LaserTag::LaserTag(){
    cout << "\nin default LaserTag constructor" << endl;
}

LaserTag::LaserTag(char * argv[]){

    DSString ATeamFileName(argv[1]);        // ATeamFileName(argv[1]) = 'cowboys.txt'
    Team TeamA(ATeamFileName);              // TeamA(ATeamFileName) = 'The Cowboys'

    DSString BTeamFileName(argv[2]);        // BTeamFileName(argv[2]) = 'sharks.txt'
    Team TeamB(BTeamFileName);              // TeamB(BTeamFileName) = 'The Sharks'



}
