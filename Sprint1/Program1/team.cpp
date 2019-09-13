#include "team.h"
#include "dsstring.h"
#include <iostream>

Team::Team(){
    teamName = nullptr;
    teamSize = 0;
    teamPoints = 0;
    player = nullptr;
}

Team::Team(DSString& TeamFile){
    ifstream theTeamFile(TeamFile.c_str());

    char * tempTeamChar = new char[100];
    theTeamFile.getline(tempTeamChar,100);
    setTeamName(tempTeamChar);

    int tempNumOfMembers;
    theTeamFile >> tempNumOfMembers;
    setTeamSize(tempNumOfMembers);

    cout << "Team: " << getTeamName() << "\tPlayers: " << getTeamSize()  << endl;

    for(int i = 0; i < getTeamSize(); i++){
        thePlayer(theTeamFile);
    }

    theTeamFile.close();

    cout << endl;

    delete [] tempTeamChar;
}

void Team::thePlayer(ifstream& TeamFile){
    this->player = new Player(TeamFile);
    this->player->print();

    delete this->player;
}

void Team::setTeamName(const char * tempTeamName){
    teamName = tempTeamName;
}

void Team::setTeamSize(int tempNumOfMembers){
    this->teamSize = tempNumOfMembers;
}

DSString& Team::getTeamName(){
    return this->teamName;
}

int Team::getTeamSize(){
    return this->teamSize;
}

Player* Team::getTeamMember(){
    return this->player;
}

Team::~Team(){
    //delete [] player;
}
