#include "lasertag.h"
#include "team.h"
#include "player.h"
#include "dsstring.h"
#include "linkedlist.h"
#include <iostream>

LaserTag::LaserTag(){
    //cout << "\nin default LaserTag constructor" << endl;
}

LaserTag::LaserTag(char * argv[]){
    LinkedList teamA;
    DSString ATeamFileName(argv[1]);        // ATeamFileName(argv[1]) = 'cowboys.txt'
    Team TeamA(ATeamFileName,teamA);              // TeamA(ATeamFileName) = 'The Cowboys'
    //teamA.print();

    LinkedList teamB;
    DSString BTeamFileName(argv[2]);        // BTeamFileName(argv[2]) = 'sharks.txt'
    Team TeamB(BTeamFileName,teamB);              // TeamB(BTeamFileName) = 'The Sharks'
    //teamA.print();



    DSString matchFileName(argv[3]);
    DSString outputFile(argv[4]);
    DSString verbosity(argv[5]);

    int aPoints = verbosityLow(matchFileName,outputFile,teamA,teamB);
    cout << aPoints << endl;

    switch(verbosity[1]){
        case 'l':
            //verbosityLow(matchFileName,outputFile,teamA,teamB);
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

int LaserTag::verbosityLow(DSString& matchFileName,DSString& outputFile, LinkedList& teamA,LinkedList& teamB){

    ifstream verbLow(matchFileName.c_str());

    int totalNumberOfTags;
    int a[5];
    verbLow >> totalNumberOfTags;

    int lineCount = 0;
    int pointsToAdd = 0;
    int totalA = 0, totalB = 0;
    while(lineCount != totalNumberOfTags){
        verbLow >> a[0] >> a[1] >> a[2] >> a[3];
        pointsToAdd = getPointValue(a[3]);
        //cout << a[0] << " " << a[1] << " " << a[2] << " " << pointsToAdd << endl;
        bool aChecker = teamA.checkTeam(a[0] - 1);
        if(aChecker == false){
            teamB.getPlayer(a[0] - 1,pointsToAdd,aChecker);
            totalB += pointsToAdd;
        }
        if(aChecker == true) {
            teamA.getPlayer(a[0] - 1,pointsToAdd,aChecker);
            totalA += pointsToAdd;
        }
        lineCount++;
    }

    verbLow.close();

    cout << totalA << endl;
    cout << totalB << endl;

    fstream aFile(outputFile.c_str());

    aFile << "testing" << endl;
    aFile.close();
    return totalA;
}


void LaserTag::verbosityMedium(DSString& matchFileName,DSString& outputFile){
    fstream aFile(outputFile.c_str());
    aFile.close();

    ifstream verbMed(matchFileName.c_str());

    int totalNumberOfTags;
    verbMed >> totalNumberOfTags;

    int a[5];

    int lineCount = 0;
    int pointsToAdd = 0;
    while(lineCount != totalNumberOfTags){
        verbMed >> a[0] >> a[1] >> a[2] >> a[3];
        pointsToAdd = getPointValue(a[3]);
        cout << a[0] << " " << a[1] << " " << a[2] << " " << pointsToAdd << endl;
        lineCount++;
    }


    verbMed.close();
}

void LaserTag::verbosityHigh(DSString& matchFileName,DSString& outputFile){
    fstream aFile(outputFile.c_str());
    aFile.close();

    ifstream verbHigh(matchFileName.c_str());

    int totalNumberOfTags;
    verbHigh >> totalNumberOfTags;
    int a[5];

    int lineCount = 0;
    int pointsToAdd = 0;
    while(lineCount != totalNumberOfTags){
        verbHigh >> a[0] >> a[1] >> a[2] >> a[3];
        pointsToAdd = getPointValue(a[3]);
        cout << a[0] << " " << a[1] << " " << a[2] << " " << pointsToAdd << endl;
        lineCount++;
    }

    verbHigh.close();
}

int LaserTag::getPointValue(int a){
    switch(a){
        case 1:
            //cout << "Back" << endl;
            return 5;
        case 2:
            //cout << "Chest" << endl;
            return 8;
        case 3:
            //cout << "Shoulder" << endl;
            return 7;
        case 4:
            //cout << "Laser gun" << endl;
            return 4;
        default:
            //cout << "Invalid point area" << endl;
            return 0;
    }
}
