#include "team.h"
#include "dsstring.h"
#include <iostream>


Team::Team(){
    cout << "\nin Team Default constructor " << endl;
    teamName = nullptr;
    numOfMembers = nullptr;
    teamSize = 0;
    player = nullptr;
}

Team::Team(DSString& teamFileName){
    ifstream theTeamFile(teamFileName.c_str());

    char * tempTeamChar = new char[100];
    theTeamFile.getline(tempTeamChar,100);
    setTeamName(tempTeamChar);

    char * tempNumOfMembers = new char[3];
    theTeamFile.getline(tempNumOfMembers,3);
    setNumOfMembers(tempNumOfMembers);


    for(int i = 0; i < getNumOfMembers(); i++){
        addPlayer(theTeamFile);
    }




    //int memberCounter = 0;



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
    delete [] tempNumOfMembers;
}

void Team::addPlayer(ifstream& stream){
    player = new Player(stream);
}

void Team::setTeamName(const char * tempTeamName){
    teamName = tempTeamName;
}

void Team::setNumOfMembers(const char * tempNumOfMembers){
    numOfMembers = tempNumOfMembers;
    int total = 0;
    for(int i = 0; i < numOfMembers.size(); i++){
        if(numOfMembers.size() == 2 && i == 0){
            total = (numOfMembers.charToNum(numOfMembers[i]) * 10);
        }
        else {
            total += (numOfMembers.charToNum(numOfMembers[i]));
        }
    }
    teamSize = total;
}

DSString Team::getTeamName(){
    return teamName;
}

int Team::getNumOfMembers(){
    return teamSize;
}

