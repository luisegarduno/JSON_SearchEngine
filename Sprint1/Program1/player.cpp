#include "player.h"
#include "dsstring.h"

Player::Player(){
    points = 0;
    ID_AsInt = 0;
    tags = 0;
    idNumber = nullptr;
    name = nullptr;

}

Player::Player(ifstream& stream){
    //cout << "Player(ifstream)" << endl;
    char * tempLineChar = new char[100];
    stream.getline(tempLineChar,100);
    cout << "Player" << tempLineChar << endl;

    DSString theID(tempLineChar);
    DSString theName(tempLineChar);
    cout << theID << endl;
    int a = 0;
    int b = 0;
    while(tempLineChar[a] != '\0'){

        if(tempLineChar[a] == ' '){
            setIDNumber(theID.substring(a,0 - a));
            b = a;
        }
        a++;
    }

    setName(theName.substring(b,a));
    //theTeamFile.close();

    delete [] tempLineChar;
}

Player::Player(Player* originalPlayer){
    ID_AsInt = originalPlayer->getMemberID_AsInt();
    name = originalPlayer->getName();
}

Player::Player(int anID){
    ID_AsInt = anID;
}

DSString& Player::getName(){
    return this->name;
}

void Player::setName(const DSString& name){
    this->name = name;
}

int Player::getMemberID_AsInt(){
    char* tempData = this->idNumber.c_str();
    //int  number = *idNumber.c_str() - 81;

    points = 0;
    int total = 0;

    for(int i = 0; i < idNumber.size(); i++){
        if(idNumber.size() == 2 && i == 0){
            total = (idNumber.charToNum(tempData[i]) * 10);
        }
        else {
            total += (idNumber.charToNum(tempData[i]));
        }
    }
    ID_AsInt = total;
    return ID_AsInt;
}

void Player::setIDNumber(const DSString& idNumber){
    this->idNumber = idNumber;
}

DSString& Player::getIDNumber(){
    return this->idNumber;
}

void Player::addPoints(int points){
    this->points += points;
}

int Player::getPoints(){
    return this->points;
}

void Player::setTeamName(const DSString& TeamName){
    this->TeamName = TeamName;
}

DSString& Player::getTeamName(){
    return this->TeamName;
}

Player::~Player(){
    //cout << "in Player Destructor" << endl;

}
