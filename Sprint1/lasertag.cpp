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

    int totalNumberOfPlayers = TeamA.getNumOfMembers() + TeamB.getNumOfMembers();
    Player * allPlayers[totalNumberOfPlayers];

    DSString matchFileName(argv[3]);
    DSString outputFile(argv[4]);

    DSString verbosity(argv[5]);
    switch(verbosity[1]){
        case 'l':
            verbosityLow(matchFileName,outputFile);
            break;
        case 'm':
            verbosityMedium(matchFileName,outputFile);
            break;
        case 'h':
            verbosityHigh(matchFileName,outputFile);
            break;
        default:
            cout << "Verbosity Error" << endl;
        break;
    }

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

void LaserTag::verbosityLow(const DSString& matchFileName,const DSString& outputFile){
    cout << "Low Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;

}

void LaserTag::verbosityMedium(const DSString& matchFileName,const DSString& outputFile){
    cout << "Medium Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
}

void LaserTag::verbosityHigh(const DSString& matchFileName,const DSString& outputFile){
    cout << "High Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
}

