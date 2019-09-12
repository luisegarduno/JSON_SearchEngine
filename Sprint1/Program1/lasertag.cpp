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

    //Player * thePlayer[TeamA.getNumOfMembers()];// + TeamB.getNumOfMembers()];


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
    ifstream verbLow(matchFileName.c_str());

    //char * readLow = new char[7];
    //verbLow.getline(readLow,7);

    int totalNumberOfTags;
    verbLow >> totalNumberOfTags;


    char * theLine;// = new char [totalNumberOfTags];
    int lineCount = 0;
    while(lineCount != totalNumberOfTags){
        theLine = new char[25];
        verbLow.getline(theLine,25,'\0');
        //cout << "Line[" << lineCount << "]: " << endl;// theLine[0] << endl;
        lineCount++;
        cout << theLine << endl;
    }

    //DSString totalNumOfTagsInGame(readLow);
    //DSString fileLines;
    //char * fileLine = new char[100];

    //int lineNumber = 0;


    verbLow.close();
    //delete [] readLow;
}

void LaserTag::verbosityMedium(DSString& matchFileName,const DSString& outputFile){
    if(DEBUG)cout << "Medium Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
    ifstream verbMed(matchFileName.c_str());

    char * readMed = new char[7];
    verbMed.getline(readMed,7);

    DSString totalNumOfTagsInGame(readMed);

    verbMed.close();

    delete [] readMed;
}

void LaserTag::verbosityHigh(DSString& matchFileName,const DSString& outputFile){
    if(DEBUG)cout << "High Verbosity(" <<  matchFileName << ") -> " << outputFile << endl;
    ifstream verbHigh(matchFileName.c_str());

    char * readHigh = new char[7];
    verbHigh.getline(readHigh,7);

    DSString totalNumOfTagsInGame(readHigh);



    verbHigh.close();

    delete [] readHigh;
}
