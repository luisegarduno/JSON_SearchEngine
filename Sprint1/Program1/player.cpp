#include "player.h"
#include "dsstring.h"

//const bool DEBUG1 = true;

Player::Player(){
    points = 0;
    ID_AsInt = 0;
    tags = 0;
    this->idNumber = nullptr;
    this->name = nullptr;

}

Player::Player(ifstream& stream){
    //if(DEBUG1)cout << "Player(ifstream)" << endl;
    char * tempLineChar = new char[100];
    stream.getline(tempLineChar,100);
    DSString theID(tempLineChar);
    DSString theName(tempLineChar);

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

    delete [] tempLineChar;
}

Player::Player(Player* originalPlayer){
    cout << "in Player(Player* originalPlayer)" << endl;
    ID_AsInt = originalPlayer->getMemberID_AsInt();
    this->name = originalPlayer->getName();

}

DSString& Player::getName(){
    //if(DEBUG1)cout << "get name: " << this->name << endl;
    return this->name;
}

void Player::setName(const DSString& name){
    //if(DEBUG1)cout << "set name: " << endl;
    this->name = name;
}

int Player::getMemberID_AsInt(){

    points = 0;
    int total = 0;
    for(int i = 0; i < idNumber.size(); i++){
        if(idNumber.size() == 2 && i == 0){
            total = (idNumber.charToNum(idNumber[i]) * 10);
        }
        else {
            total += (idNumber.charToNum(idNumber[i]));
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

Player::~Player(){
    //if(DEBUG1)cout << "in Player Destructor" << endl;
}
