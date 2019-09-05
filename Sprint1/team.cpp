#include "team.h"
#include "dsstring.h"
#include <iostream>

Team::Team(){
    cout << "\nin Team Default constructor " << endl;
}

Team::Team(DSString& teamFileName){

    ifstream theTeamFile(teamFileName.c_str());
    DSString newLine;
    if(theTeamFile.is_open()){
        theTeamFile >> newLine;
        cout << newLine << endl;

    }


    theTeamFile.close();


}


