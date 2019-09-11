#include "lasertag.h"
#include "team.h"
#include "dsstring.h"
#include <iostream>

const bool DEBUG = false;

LaserTag::LaserTag(){
    if(DEBUG)cout << "\nin default LaserTag constructor" << endl;
}

LaserTag::LaserTag(char * argv[]){

    DSString ATeamFileName(argv[1]);        // ATeamFileName(argv[1]) = 'cowboys.txt'
    Team TeamA(ATeamFileName);              // TeamA(ATeamFileName) = 'The Cowboys'
    //TeamA.addPlayers(TeamA.getNumOfMembers());

    DSString BTeamFileName(argv[2]);        // BTeamFileName(argv[2]) = 'sharks.txt'
    //Team TeamB(BTeamFileName);              // TeamB(BTeamFileName) = 'The Sharks'

    Player * thePlayer[TeamA.getNumOfMembers()];// + TeamB.getNumOfMembers()];

    int aPlayerNum = 0;

    ifstream theFile(ATeamFileName.c_str());

    for(int i = 0; i < TeamA.getNumOfMembers(); i++){
        aPlayerNum = TeamA.getTeamMember()->getMemberID_AsInt();
        thePlayer[aPlayerNum] = new Player(theFile);
    }
    theFile.close();

    cout << thePlayer[1]->getName() << endl;

    //Player * allPlayers[totalNumberOfPlayers];

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
}

void LaserTag::verbosityLow(DSString& matchFileName,const DSString& outputFile){
    if(DEBUG)cout << "Low Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
    ifstream verbLow(matchFileName.c_str());

    char * readLow = new char[7];
    verbLow.getline(readLow,7);

    DSString totalNumOfTagsInGame(readLow);
    if(DEBUG)cout << totalNumOfTagsInGame << endl;


    verbLow.close();

    delete [] readLow;
}

void LaserTag::verbosityMedium(DSString& matchFileName,const DSString& outputFile){
    if(DEBUG)cout << "Medium Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
    ifstream verbMed(matchFileName.c_str());

    char * readMed = new char[7];
    verbMed.getline(readMed,7);

    DSString totalNumOfTagsInGame(readMed);
    if(DEBUG)cout << totalNumOfTagsInGame << endl;






    verbMed.close();

    delete [] readMed;
}

void LaserTag::verbosityHigh(DSString& matchFileName,const DSString& outputFile){
    if(DEBUG)cout << "High Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
    ifstream verbHigh(matchFileName.c_str());

    char * readHigh = new char[7];
    verbHigh.getline(readHigh,7);

    DSString totalNumOfTagsInGame(readHigh);
    if(DEBUG)cout << totalNumOfTagsInGame << endl;




    verbHigh.close();

    delete [] readHigh;
}
