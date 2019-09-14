#include "team.h"
#include <iostream>

Team::Team(){
    teamSize = 0;
    teamPoints = 0;
}

Team::Team(DSString& TeamFile,LinkedList& teamA){
    ifstream theTeamFile(TeamFile.c_str());

    char * tempTeamChar = new char[100];
    theTeamFile.getline(tempTeamChar,100);
    setTeamName(tempTeamChar);

    int tempNumOfMembers;
    theTeamFile >> tempNumOfMembers;
    setTeamSize(tempNumOfMembers);

    for(int i = 0; i < getTeamSize(); i++){
        thePlayer(theTeamFile,teamA);
    }

    theTeamFile.close();
    delete [] tempTeamChar;
}

void Team::thePlayer(ifstream& TeamFile, LinkedList& team){
    int num = 0, a = 0, b = 0;
    TeamFile >> num;
    this->player = new Player();
    player->setIDNumber(num);

    char * tempLineChar = new char[100];
    TeamFile.getline(tempLineChar,100);
    DSString theName(tempLineChar);

    while(theName[a] != '\0' && theName[0] != 0){
        if(theName[a] == ' '){
            b = a;
        }
        a++;
    }
    this->player->setTeamName(getTeamName());
    this->player->setPlayerName(theName.substring(b,a));
    team.addPlayer(this->player);

    delete [] tempLineChar;
}

void Team::setTeamName(const char * tempTeamName){
    this->teamName = tempTeamName;
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

void Team::setTeamPoints(int points){
    this->teamPoints = points;
}

int Team::getTeamPoints(){
    return this->teamPoints;
}
