#include <iostream>
#include "lasertag.h"

LaserTag::LaserTag(){
    cout << "Default LaserTag constructor" << endl;
}

LaserTag::LaserTag(char * argv[]){
    DSString ATeamFileName(argv[1]);                    // ATeamFileName(argv[1]) = 'cowboys.txt'
    Team TeamA(ATeamFileName,teamA);

    DSString BTeamFileName(argv[2]);                    // BTeamFileName(argv[2]) = 'sharks.txt'
    Team TeamB(BTeamFileName,teamB);                    // TeamB is used to construct the Linked List

    DSString matchFileName(argv[3]);                    // "match.txt"
    DSString outputFile(argv[4]);                       // "output.txt"
    DSString verbosity(argv[5]);                        // "vlow" / "vmed" / "vhigh"

    int aPoints = verbosityPartOne(matchFileName);      // collects points for TeamA
    TeamA.setTeamPoints(aPoints);

    int bPoints = verbosityPartTwo(matchFileName);      // collects points for TeamB
    TeamB.setTeamPoints(bPoints);

    switch(verbosity[1]){                               // a switch statement is used to determine the verbosity
        case 'l':                                       // output Low Verbosity
            verbosityLow(outputFile,TeamA,TeamB);
            break;
        case 'm':                                       // output Medium Verbosity
            verbosityMedium(outputFile,TeamA,TeamB);
            break;
        case 'h':                                       // output High Verbosity
            verbosityHigh(outputFile,TeamA,TeamB);
            break;
        default:
            cout << "Verbosity Error" << endl;
        break;
    }
}

int LaserTag::verbosityPartOne(DSString& matchFileName){
    ifstream verbTags(matchFileName.c_str());           // open match file

    int totalNumberOfTags, a[5];                        // a[0]: player tagging, a[1]: player getting tagged
                                                        // a[2]: time tagged after game started, a[3]: body area tagged
    verbTags >> totalNumberOfTags;                      // gets total number of tags


    int totalA = 0;                                     // total number of points for TeamA
    int lineCount = 0, pointsToAdd = 0;
    while(lineCount != totalNumberOfTags){
        verbTags >> a[0] >> a[1] >> a[2] >> a[3];
        pointsToAdd = getPointValue(a[3]);
        bool aChecker = teamA.checkTeam(a[0] - 1);
        if(aChecker == true) {
            teamA.getPlayer(a[0] - 1,pointsToAdd,aChecker);
            totalA += pointsToAdd;
        }
        lineCount++;
    }
    verbTags.close();                                   // closes match file
    verbTags.clear();                                   // clears match file flags

    return totalA;                                      // returns total number of points obtained by TeamA
}

int LaserTag::verbosityPartTwo(DSString& matchFileName){
    ifstream verbTags(matchFileName.c_str());

    int totalNumberOfTags, a[5];
    verbTags >> totalNumberOfTags;                      // gets total number of tags/lines in match file

    int lineCount = 0, pointsToAdd = 0;
    int totalB = 0;
    while(lineCount != totalNumberOfTags){              // while lineCount does not exceed totalNumberofTags
        verbTags >> a[0] >> a[1] >> a[2] >> a[3];
        pointsToAdd = getPointValue(a[3]);
        bool aChecker = teamA.checkTeam(a[0] - 1);
        if(aChecker == false){
            teamB.getPlayer(a[0] - 1,pointsToAdd,aChecker);
            totalB += pointsToAdd;                      // adds points to teamB total points
        }
        lineCount++;                                    // increment lineCounter
    }

    verbTags.close();                                   // closes match file

    return totalB;                                      // returns total number of points obtained by TeamB
}

void LaserTag::verbosityLow(DSString& outputFile,Team& TeamA,Team& TeamB){
    fstream aFile(outputFile.c_str());                  // writes to "OutputFile.txt"

    aFile << TeamA.getTeamName() << ": " << TeamA.getTeamPoints() << " points\n";
    aFile << TeamB.getTeamName() << ": " << TeamB.getTeamPoints() << " points\n";

    if(TeamA.getTeamPoints() < TeamB.getTeamPoints())
        aFile << "Overall Winners: " << TeamB.getTeamName();

    if(TeamA.getTeamPoints() > TeamB.getTeamPoints())
        aFile << "Overall Winners: " << TeamA.getTeamName();

    if(TeamA.getTeamPoints() == TeamB.getTeamPoints())
        aFile << "Overall Winners: It's a Draw!";

    aFile.close();                                      // closes the OutputFile
}


void LaserTag::verbosityMedium(DSString& outputFile,Team& TeamA, Team& TeamB){
    fstream aFile(outputFile.c_str());

    aFile << TeamA.getTeamName() << endl;
    aFile << TeamB.getTeamName() << endl;

    aFile << "Best score from " << TeamA.getTeamName() << ": " << endl;
    aFile << "Best score from " << TeamB.getTeamName() << ": " << endl;

    aFile << TeamA.getTeamName() << ": " << TeamA.getTeamPoints() << " points" << endl;
    aFile << TeamB.getTeamName() << ": " << TeamB.getTeamPoints() << " points" << endl;

    if(TeamA.getTeamPoints() < TeamB.getTeamPoints())
        aFile << "Overall Winners: " << TeamB.getTeamName();

    if(TeamA.getTeamPoints() > TeamB.getTeamPoints())
        aFile << "Overall Winners: " << TeamA.getTeamName();

    if(TeamA.getTeamPoints() == TeamB.getTeamPoints())
        aFile << "Overall Winners: It's a Draw!";

    aFile.close();
}

void LaserTag::verbosityHigh(DSString& outputFile,Team& TeamA, Team& TeamB){
    fstream aFile(outputFile.c_str());

    aFile << TeamA.getTeamName() << endl;
    aFile << TeamA.getTeamName() << ": " << TeamA.getTeamPoints() << " points" << endl;

    aFile << TeamB.getTeamName() << endl;
    aFile << TeamB.getTeamName() << ": " << TeamB.getTeamPoints() << " points" << endl;

    if(TeamA.getTeamPoints() < TeamB.getTeamPoints())
        aFile << "Winners: " << TeamB.getTeamName();

    if(TeamA.getTeamPoints() > TeamB.getTeamPoints())
        aFile << "Winners: " << TeamA.getTeamName();

    if(TeamA.getTeamPoints() == TeamB.getTeamPoints())
        aFile << "Winners: It's a Draw!";

    aFile.close();

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
