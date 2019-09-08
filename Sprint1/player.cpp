#include "player.h"
#include "dsstring.h"

Player::Player(){
    points = 0;
    this->idNumber = nullptr;
    this->name = nullptr;
}

Player::Player(ifstream& stream){
    char * tempLineChar = new char[100];
    stream.getline(tempLineChar,100);
    DSString* theID = new DSString(tempLineChar);
    DSString* theName = new DSString(*theID);

    int a = 0;
    int b = 0;
    while(tempLineChar[a] != '\0'){

        if(tempLineChar[a] == ' '){
            setIdNumber(theID->substring(a,0 - a));
            cout << "ID: " << *theID;
            b = a;
        }
        a++;
    }
    setName(theName->substring(b,a));
    cout << "\tName: " << *theName << endl;

    //stream.close();

    delete [] tempLineChar;
    delete theID;
    delete theName;
}

DSString Player::getName(){
    //cout << "get name: " << this->name << endl;
    return this->name;
}

void Player::setName(const DSString& name){
    //cout << "set name: " << endl;
    this->name = name;
}

void Player::setIdNumber(const DSString& idNumber){
    this->idNumber = idNumber;
}

void Player::addPoints(int points){
    this->points += points;
}

int Player::getPoints(){
    return this->points;
}
