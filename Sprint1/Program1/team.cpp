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

    for(int i = 0; i < getTeamSize(); i++){
        thePlayer(theTeamFile);
    }



    //thePlayer(theTeamFile);

    theTeamFile.close();

    delete [] tempTeamChar;
}

void Team::thePlayer(ifstream& TeamFile){
    this->player = new Player(TeamFile);

    //cout << "Name: " << this->player->getName() << "\tID: " << this->player->getMemberID_AsInt()
                //<< "\tPlayerName: " << this->player->getName() << endl;
    //stream.close();
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
    //cout << "in Team Destructor: " << this->teamName <<  endl;
    //delete [] player;
}
