#include "team.h"
#include "dsstring.h"
#include <iostream>

Team::Team(){
    cout << "\nin Team Default constructor " << endl;
    teamName = nullptr;
    teamSize = 0;
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

    thePlayer(theTeamFile);

    //theTeamFile.close();

    delete [] tempTeamChar;
}

void Team::thePlayer(ifstream& stream){
    this->player = new Player(stream);
    //cout << "Name: " << this->player->getName() << "\tID: " << this->player->getMemberID_AsInt() << endl;
    //cout << this->player->getIDNumber();
    //stream.close();
    //int *arg = malloc(sizeof(*arg));
    //*arg = i
}

void Team::setTeamName(const char * tempTeamName){
    teamName = tempTeamName;
}

void Team::setTeamSize(int tempNumOfMembers){
    teamSize = tempNumOfMembers;
}

DSString Team::getTeamName(){
    return this->teamName;
}

int Team::getTeamSize(){
    return teamSize;
}

Player* Team::getTeamMember(){
    return this->player;
}

Team::~Team(){
    //cout << "in Team Destructor: " << this->teamName <<  endl;
    delete player;
}
