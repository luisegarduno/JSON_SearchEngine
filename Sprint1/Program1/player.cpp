#include "player.h"
#include "dsstring.h"

const bool DEBUG1 = false;

Player::Player(){
    points = 0;
    ID_AsInt = 0;
    tags = 0;
    this->idNumber = nullptr;
    this->name = nullptr;

}

Player::Player(ifstream& stream){
    if(DEBUG1)cout << "Player(ifstream)" << endl;
    char * tempLineChar = new char[100];
    stream.getline(tempLineChar,100);
    DSString* theID = new DSString(tempLineChar);
    DSString* theName = new DSString(*theID);

    int a = 0;
    int b = 0;
    while(tempLineChar[a] != '\0'){

        if(tempLineChar[a] == ' '){
            setIDNumber(theID->substring(a,0 - a));

            if(DEBUG1)cout << "ID: " << *theID;
            b = a;
        }
        a++;
    }
    setName(theName->substring(b,a));
    setIDNumber_AsInt(getIDNumber());
    if(DEBUG1)cout << "\tName: " << *theName << endl;

    delete [] tempLineChar;
    delete theID;
    delete theName;
}

Player::Player(Player* originalPlayer){
    ID_AsInt = originalPlayer->getMemberID_AsInt();
    this->name = originalPlayer->getName();

}

DSString Player::getName(){
    if(DEBUG1)cout << "get name: " << this->name << endl;
    return this->name;
}

void Player::setName(const DSString& name){
    if(DEBUG1)cout << "set name: " << endl;
    this->name = name;
}

void Player::setIDNumber_AsInt(const DSString& idNumber){
    this->idNumber = idNumber;
    this->points = 0;
    int total = 0;
    for(int i = 0; i < this->idNumber.size(); i++){
        if(this->idNumber.size() == 2 && i == 0){
            total = (this->idNumber.charToNum(this->idNumber[i]) * 10);
        }
        else {
            total += (this->idNumber.charToNum(this->idNumber[i]));
        }
    }
    ID_AsInt = total;
}

int Player::getMemberID_AsInt(){
    return ID_AsInt;
}

void Player::setIDNumber(const DSString& idNumber){
    this->idNumber = idNumber;
}

DSString Player::getIDNumber(){
    return this->idNumber;
}

void Player::addPoints(int points){
    this->points += points;
}

int Player::getPoints(){
    return this->points;
}

Player::~Player(){
    if(DEBUG1)cout << " in Player Destructor" << endl;
    //delete player;
}
