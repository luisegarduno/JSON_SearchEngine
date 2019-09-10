#include "team.h"
#include "dsstring.h"
#include <iostream>


Team::Team(){
    cout << "\nin Team Default constructor " << endl;
    teamName = nullptr;
    numOfMembers = nullptr;
    teamSize = 0;
    player = nullptr;
    firstMember = true;
}

Team::Team(DSString& teamFileName){
    ifstream theTeamFile(teamFileName.c_str());

    char * tempTeamChar = new char[100];
    theTeamFile.getline(tempTeamChar,100);
    setTeamName(tempTeamChar);

    char * tempNumOfMembers = new char[3];
    theTeamFile.getline(tempNumOfMembers,3);
    setNumOfMembers(tempNumOfMembers);

    firstMember = true;

    Player * player[getNumOfMembers()];

    for(int i = 0; i < getNumOfMembers(); i++){
        addMember(theTeamFile);
        player[i] = this->player;
    }

    setTeamMember(player[0]);

    theTeamFile.close();

    delete [] tempTeamChar;
    delete [] tempNumOfMembers;
}


void Team::addMember(ifstream& stream){
    this->player = new Player(stream);
    cout << "Team: " << getTeamName() << "\tName: " << this->player->getName();
    cout << "\tID: " << this->player->getMemberID_AsInt() << endl;
    if(this->player->getMemberID_AsInt() == 1){
        isFirstMember();
    }
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

bool Team::isFirstMember(){
    firstMember = false;
    return firstMember;
}

DSString Team::getTeamName(){
    return this->teamName;
}

int Team::getNumOfMembers(){
    return teamSize;
}

void Team::setTeamMember(Player * aPlayer){
   aPlayer = this->player;
}

Player* Team::getTeamMember(){
    return this->player;
}

Team::~Team(){
    //cout << "in Team Destructor: " << this->teamName <<  endl;
    //delete  this->player;
}
