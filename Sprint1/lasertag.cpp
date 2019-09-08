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
    //cout << "Team: " << TeamA.getTeamName() << endl;
    //cout << "Number of Team Members: " << TeamA.getNumOfMembers() << endl;

    cout << endl;

    DSString BTeamFileName(argv[2]);        // BTeamFileName(argv[2]) = 'sharks.txt'
    Team TeamB(BTeamFileName);              // TeamB(BTeamFileName) = 'The Sharks'
    //cout << "Team: " << TeamB.getTeamName() << endl;
    //cout << "Number of Team Members: " << TeamB.getNumOfMembers() << endl;


    // cout << TeamA.getIDNum() << endl; //prints 15
    // cout << TeamB.getIDNum() << endl; //prints 30
    // Since TeamA < TeamB     TeamA: 1-15     TeamB: 16-30

    DSString verbosity(argv[5]);
    if(verbosity[1] == 'l'){
        cout << "vlow" << endl;
    }
    else if(verbosity[1] == 'm'){
        cout << "vmed" << endl;
    }
    else if(verbosity[1] == 'h'){
        cout << "vhigh" << endl;
    }


    DSString matchFileName(argv[3]);
    /*
     * Match(matchFileName){
     *  open matchFile
     *  read first line to get total # of tags
     *
     *  int tags =0
     *  while  tags != # of tags
     *      istream(readfrom, save to, '\0');
     *
     * }
     * */



}
