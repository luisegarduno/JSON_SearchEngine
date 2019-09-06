#include "team.h"
#include "dsstring.h"
#include <iostream>


Team::Team(){
    cout << "\nin Team Default constructor " << endl;
}

Team::Team(DSString& teamFileName){
    DSString * getTheString;
    ifstream theTeamFile(teamFileName.c_str());
    char * tempArray = new char[100];

    if(theTeamFile.good()){
        while(!theTeamFile.eof()){
            theTeamFile.getline(tempArray,100);
            //theTeamFile.getline()
            getTheString = new DSString(tempArray);
            cout << *getTheString << endl;
        }
    }

    theTeamFile.close();

    delete [] tempArray;
}


