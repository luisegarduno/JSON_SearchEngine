#include "lasertag.h"
#include "team.h"
#include "dsstring.h"
#include <iostream>

LaserTag::LaserTag(){
    cout << "\nin default LaserTag constructor" << endl;
}

LaserTag::LaserTag(char * argv[]){

    DSString ATeamFileName(argv[2]);        // ATeamFileName(argv[1]) = 'cowboys.txt'
    Team TeamA(ATeamFileName);              // TeamA(ATeamFileName) = 'The Cowboys'

    DSString BTeamFileName(argv[3]);        // BTeamFileName(argv[2]) = 'sharks.txt'
    Team TeamB(BTeamFileName);              // TeamB(BTeamFileName) = 'The Sharks'

    int totalNumberOfPlayers = TeamA.getNumOfMembers() + TeamB.getNumOfMembers();
    Player * allPlayers[totalNumberOfPlayers];

    DSString matchFileName(argv[4]);
    DSString outputFile(argv[5]);

    DSString verbosity(argv[6]);
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

void LaserTag::verbosityLow(DSString& matchFileName,const DSString& outputFile){
    cout << "Low Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
    ifstream verbLow(matchFileName.c_str());

    char * readLow = new char[7];
    verbLow.getline(readLow,7);

    DSString totalNumOfTagsInGame(readLow);
    cout << totalNumOfTagsInGame << endl;


    verbLow.close();

    delete [] readLow;
}

void LaserTag::verbosityMedium(DSString& matchFileName,const DSString& outputFile){
    cout << "Medium Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
    ifstream verbMed(matchFileName.c_str());

    char * readMed = new char[7];
    verbMed.getline(readMed,7);

    DSString totalNumOfTagsInGame(readMed);
    cout << totalNumOfTagsInGame << endl;






    verbMed.close();

    delete [] readMed;
}

void LaserTag::verbosityHigh(DSString& matchFileName,const DSString& outputFile){
    cout << "High Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
    ifstream verbHigh(matchFileName.c_str());

    char * readHigh = new char[7];
    verbHigh.getline(readHigh,7);

    DSString totalNumOfTagsInGame(readHigh);
    cout << totalNumOfTagsInGame << endl;




    verbHigh.close();

    delete [] readHigh;
}
