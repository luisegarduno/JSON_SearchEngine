#include "team.h"
#include "dsstring.h"
#include <iostream>


Team::Team(){
    cout << "\nin Team Default constructor " << endl;
}

Team::Team(DSString& teamFileName){
    ifstream theTeamFile(teamFileName.c_str());

    char * teamName = new char[100];
    theTeamFile.getline(teamName,100);
    DSString getTheString(teamName);
    cout << "Team name:" << getTheString.size() << endl;


    /*
    if(theTeamFile.good()){
        while(!theTeamFile.eof()){
            theTeamFile.getline(tempArray,100);
            //cout << "Here:" << tempArray << endl;
            //theTeamFile.getline()
            getTheString = new DSString(tempArray);
            cout << "Line: " << *getTheString;
        }
    }
    */

    theTeamFile.close();

    delete [] teamName;
}


