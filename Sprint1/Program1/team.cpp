#include "team.h"
#include "dsstring.h"
#include <iostream>

Team::Team(){
    cout << "\nin Team Default constructor " << endl;
    teamName = nullptr;
    teamSize = 0;
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
        *player = new Player[getTeamSize()];
        thePlayer(theTeamFile);
        *(player) = i;
        cout << (player[i]).getName() << endl;
    }
    //*player = new Player[getTeamSize()];
    //thePlayer(theTeamFile);
    //*(player + 0) = *(this->player);
    //cout << (player + 0)->getName() << endl;

    //DSString * yo = new DSString[3];
    //*(yo + 0) = "hi";
    //cout << *(yo + 0) << endl;



    //thePlayer(theTeamFile);

    //theTeamFile.close();

    delete [] tempTeamChar;
}   //this->team->

void Team::thePlayer(ifstream& stream){
    this->player = new Player(stream);
    //cout << "Name: " << this->player->getName() << "\tID: " << this->player->getMemberID_AsInt() << endl;
    //cout << this->player->getIDNumber();
    //stream.close();
    //int *arg = malloc(sizeof(*arg));
    //*arg = i
    //delete [] this->player;
}

void Team::setTeamName(const char * tempTeamName){
    this->teamName = tempTeamName;
}

void Team::setTeamSize(int tempNumOfMembers){
    this->teamSize = tempNumOfMembers;
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
