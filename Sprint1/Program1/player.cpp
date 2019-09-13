#include "player.h"
#include "dsstring.h"

Player::Player(){
    points = 0;
    ID_AsInt = 0;
    tags = 0;
    //idNumber = nullptr;
    //name = nullptr;

}

Player::Player(ifstream& stream){
    //cout << "Player(ifstream)" << endl;
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
    //cout << "in Player(Player* originalPlayer)" << endl;
    ID_AsInt = originalPlayer->getMemberID_AsInt();
    this->name = originalPlayer->getName();
}

Player::Player(int anID){
    cout << "in Player(int)" << endl;
    ID_AsInt = anID;
}

DSString& Player::getName(){
    //cout << "get name: " << this->name << endl;
    return name;
}

void Player::setName(const DSString& name){
    //cout << "set name: " << endl;
    this->name = name;
}

int Player::getMemberID_AsInt(){
    char* tempData = this->idNumber.c_str();
    //int  number = *idNumber.c_str() - '0';
    //cout << number << endl;

    this->points = 0;
    int total = 0;
    cout << "idNumber: " << this->idNumber << endl;
    for(int i = 0; i < idNumber.size(); i++){
        if(idNumber.size() == 2 && i == 0){
            total = (idNumber.charToNum(tempData[i]) * 10);
        }
        else {
            total += (idNumber.charToNum(tempData[i]));
        }
    }
    ID_AsInt = total;


    delete [] tempData;
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
    //cout << "in Player Destructor" << endl;
}
