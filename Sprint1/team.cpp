#include "team.h"
#include "dsstring.h"
#include <iostream>

using std::cin;

Team::Team(){
    cout << "\nin Team Default constructor " << endl;
}

Team::Team(DSString& teamFileName){



    ifstream theTeamFile(teamFileName.c_str());


    DSString theString;
    if(theTeamFile.good()){
        theTeamFile >> theString;
        cout << theString << endl;

    }


    theTeamFile.close();



}


