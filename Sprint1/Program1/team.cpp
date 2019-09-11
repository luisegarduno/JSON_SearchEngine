#include "team.h"
#include "dsstring.h"
#include <iostream>

const bool DEBUG2 = false;


Team::Team(){
    if(DEBUG2)cout << "\nin Team Default constructor " << endl;
    teamName = nullptr;
    numOfMembers = nullptr;
    teamSize = 0;
    player = nullptr;
}

Team::Team(DSString& TeamFile){
    ifstream theTeamFile(TeamFile.c_str());
    char * tempTeamChar = new char[100];
    theTeamFile.getline(tempTeamChar,100);
    setTeamName(tempTeamChar);

    char * tempNumOfMembers = new char[3];
    theTeamFile.getline(tempNumOfMembers,3);
    setNumOfMembers(tempNumOfMembers);

    delete [] tempTeamChar;
    delete [] tempNumOfMembers;
}

void Team::addMember(ifstream& stream){
    this->player = new Player(stream);
    cout << "Name: " << this->player->getName() << "\tID: " << this->player->getMemberID_AsInt() << endl;
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
    return this->teamName;
}

int Team::getNumOfMembers(){
    return teamSize;
}

Player* Team::getTeamMember(){
    return this->player;
}

Team::~Team(){
    //cout << "in Team Destructor: " << this->teamName <<  endl;
    delete player;
}
