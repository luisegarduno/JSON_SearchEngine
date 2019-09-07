#include "team.h"
#include "dsstring.h"
#include <iostream>


Team::Team(){
    cout << "\nin Team Default constructor " << endl;
}

Team::Team(DSString& teamFileName){
    ifstream theTeamFile(teamFileName.c_str());

    char * tempTeamChar = new char[100];
    theTeamFile.getline(tempTeamChar,100);
    DSString teamName(tempTeamChar);
    cout << "Team name: " << teamName << endl;

    char * tempNumOfMembersChar = new char[3];
    theTeamFile.getline(tempNumOfMembersChar,3);
    DSString numOfMembers(tempNumOfMembersChar);
    cout << "Number of team members: " << numOfMembers << endl;

    /*
     *
     *
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

    delete [] tempTeamChar;
    delete [] tempNumOfMembersChar;
}


