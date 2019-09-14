#include "team.h"
#include <iostream>

Team::Team(){
    teamSize = 0;
    teamPoints = 0;
}

Team::Team(DSString& TeamFile,LinkedList& teamA){
    //LinkedList team;
    ifstream theTeamFile(TeamFile.c_str());

    char * tempTeamChar = new char[100];
    theTeamFile.getline(tempTeamChar,100);
    setTeamName(tempTeamChar);

    int tempNumOfMembers;
    theTeamFile >> tempNumOfMembers;
    setTeamSize(tempNumOfMembers);

    cout << "Team: " << getTeamName() << "\tPlayers: " << getTeamSize()  << endl;

    for(int i = 0; i < getTeamSize(); i++){
        thePlayer(theTeamFile,teamA);
    }


    theTeamFile.close();
   // team.print();

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
    this->player->setPlayerName(theName.substring(b,a));
    team.addPlayer(this->player);


    delete [] tempLineChar;
    //delete player;
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

Team::~Team(){

}
