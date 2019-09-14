#include "lasertag.h"
#include "dsstring.h"
#include "linkedlist.h"
#include <iostream>

LaserTag::LaserTag(){
    cout << "Default LaserTag constructor" << endl;
}

LaserTag::LaserTag(char * argv[]){
    LinkedList teamA;                               // creates a Linked List for TeamA
    DSString ATeamFileName(argv[1]);                // ATeamFileName(argv[1]) = 'cowboys.txt'
    Team TeamA(ATeamFileName,teamA);

    LinkedList teamB;                               // creates a Linked List for TeamB
    DSString BTeamFileName(argv[2]);                // BTeamFileName(argv[2]) = 'sharks.txt'
    Team TeamB(BTeamFileName,teamB);                // TeamB is used to construct the Linked List

    DSString matchFileName(argv[3]);                // "match.txt"
    DSString outputFile(argv[4]);                   // "output.txt"
    DSString verbosity(argv[5]);                    // "vlow" / "vmed" / "vhigh"

    int aPoints = verbosityPartOne(matchFileName,teamA,teamB);      // collects points for TeamA
    TeamA.setTeamPoints(aPoints);

    int bPoints = verbosityPartTwo(matchFileName,teamA,teamB);      // collects points for TeamB
    TeamB.setTeamPoints(bPoints);

    switch(verbosity[1]){                           // a switch statement is used to determine the verbosity
        case 'l':
            verbosityLow(outputFile,TeamA,TeamB);
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

int LaserTag::verbosityPartOne(DSString& matchFileName, LinkedList& teamA,LinkedList& teamB){
    ifstream verbLow(matchFileName.c_str());

    int totalNumberOfTags, a[5];
    verbLow >> totalNumberOfTags;


    int totalA = 0;
    int lineCount = 0, pointsToAdd = 0;
    while(lineCount != totalNumberOfTags){
        verbLow >> a[0] >> a[1] >> a[2] >> a[3];
        pointsToAdd = getPointValue(a[3]);
        bool aChecker = teamA.checkTeam(a[0] - 1);
        if(aChecker == true) {
            teamA.getPlayer(a[0] - 1,pointsToAdd,aChecker);
            totalA += pointsToAdd;
        }
        lineCount++;
    }
    verbLow.close();
    verbLow.clear();

    return totalA;
}

int LaserTag::verbosityPartTwo(DSString& matchFileName, LinkedList& teamA,LinkedList& teamB){
    ifstream verbLow(matchFileName.c_str());

    int totalNumberOfTags, a[5];
    verbLow >> totalNumberOfTags;

    int lineCount = 0, pointsToAdd = 0;
    int totalB = 0;
    while(lineCount != totalNumberOfTags){
        verbLow >> a[0] >> a[1] >> a[2] >> a[3];
        pointsToAdd = getPointValue(a[3]);
        bool aChecker = teamA.checkTeam(a[0] - 1);
        if(aChecker == false){
            teamB.getPlayer(a[0] - 1,pointsToAdd,aChecker);
            totalB += pointsToAdd;
        }
        lineCount++;
    }

    verbLow.close();

    return totalB;
}

void LaserTag::verbosityLow(DSString& outputFile,Team& TeamA,Team& TeamB){
    fstream aFile(outputFile.c_str());

    aFile << TeamA.getTeamName() << ": " << TeamA.getTeamPoints() << " points\n";
    aFile << TeamB.getTeamName() << ": " << TeamB.getTeamPoints() << " points\n";

    if(TeamA.getTeamPoints() < TeamB.getTeamPoints())
        aFile << "Overall Winners: " << TeamB.getTeamName();

    if(TeamA.getTeamPoints() > TeamB.getTeamPoints())
        aFile << "Overall Winners: " << TeamA.getTeamName();

    if(TeamA.getTeamPoints() < TeamB.getTeamPoints())
        aFile << "Overall Winners: It's a Draw!";

    aFile.close();
}


void LaserTag::verbosityMedium(DSString& matchFileName,DSString& outputFile){
    fstream aFile(outputFile.c_str());
    aFile.close();

    ifstream verbMed(matchFileName.c_str());

    int totalNumberOfTags, a[5];;
    verbMed >> totalNumberOfTags;

    int lineCount = 0, pointsToAdd = 0;
    while(lineCount != totalNumberOfTags){
        verbMed >> a[0] >> a[1] >> a[2] >> a[3];
        pointsToAdd = getPointValue(a[3]);
        lineCount++;
    }

    verbMed.close();
}

void LaserTag::verbosityHigh(DSString& matchFileName,DSString& outputFile){
    fstream aFile(outputFile.c_str());
    aFile.close();

    ifstream verbHigh(matchFileName.c_str());

    int totalNumberOfTags, a[5];
    verbHigh >> totalNumberOfTags;


    int lineCount = 0, pointsToAdd = 0;
    while(lineCount != totalNumberOfTags){
        verbHigh >> a[0] >> a[1] >> a[2] >> a[3];
        pointsToAdd = getPointValue(a[3]);
        lineCount++;
    }

    verbHigh.close();
}

int LaserTag::getPointValue(int a){
    switch(a){
        case 1:                                                                 // "Back" - 5 Points
            return 5;
        case 2:                                                                 // "Chest" - 8 Points
            return 8;
        case 3:                                                                 // "Shoulder" - 7 Points
            return 7;
        case 4:                                                                 // "Laser gun" - 4 Points
            return 4;
        default:                                                                // "Invalid point area"
            return 0;
    }
}
