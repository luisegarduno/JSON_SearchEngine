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

    int totalNumberOfTags;
    int a[5];
    verbLow >> totalNumberOfTags;
    //verbLow >> a;

    char * theLine;// = new char [totalNumberOfTags];
    int lineCount = 0;
    //DSString * aString = new DSString[totalNumberOfTags];
    while(lineCount != totalNumberOfTags){
        theLine = new char[15];
        verbLow >> a[0] >> a[1] >> a[2] >> a[3];
        cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
        //verbLow.getline(theLine,15,'\n');
        //aString[lineCount] = theLine;
        //cout << "line: " << lineCount << "\t " << aString[lineCount] << endl;
        lineCount++;
    }
    //cout << aString[0] << endl;
    //cout << theLine << endl;


    verbLow.close();
}

void LaserTag::verbosityMedium(DSString& matchFileName,const DSString& outputFile){
    ifstream verbMed(matchFileName.c_str());

    int totalNumberOfTags;
    verbMed >> totalNumberOfTags;


    verbMed.close();
}

void LaserTag::verbosityHigh(DSString& matchFileName,const DSString& outputFile){
    ifstream verbHigh(matchFileName.c_str());




    verbHigh.close();
}
