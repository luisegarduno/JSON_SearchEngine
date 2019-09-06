#include "team.h"
#include "dsstring.h"
#include <iostream>


Team::Team(){
    cout << "\nin Team Default constructor " << endl;
}

Team::Team(DSString& teamFileName){

    ifstream theTeamFile(teamFileName.c_str());
    char * tempArray = new char[100];

    DSString * getTheString;
    if(theTeamFile.good()){
        while(!theTeamFile.eof()){
            theTeamFile.getline(tempArray,100);
            getTheString = new DSString(tempArray);
        }
    }
    cout << *getTheString << endl;


    theTeamFile.close();

    delete getTheString;
    delete [] tempArray;
}


