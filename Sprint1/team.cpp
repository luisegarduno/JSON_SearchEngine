#include "team.h"
#include "dsstring.h"
#include <iostream>

using std::cout;
using std::endl;

Team::Team(){
    cout << "\nin Team Default constructor " << endl;
}

Team::Team(DSString& teamFileName){

    //ifstream theTeamFile(teamFileName.c_str());

    ifstream theTeamFile;
    theTeamFile.open(teamFileName.c_str());

    DSString theLine;
    theTeamFile >> theLine;
    cout << theLine << endl;



    theTeamFile.close();


}


