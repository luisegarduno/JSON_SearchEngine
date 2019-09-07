#include "player.h"
#include "dsstring.h"

Player::Player(){
    points = 0;
    idNumber = 0;
    this->name = nullptr;
}

Player::Player(ifstream& stream){
    char * tempLineChar = new char[100];
    stream.getline(tempLineChar,100);

    int i = 0;
    while(tempLineChar[i] != '\0'){
        cout << tempLineChar[i];
        i++;
        if(tempLineChar[i] == ' '){
            cout << "\tName: ";

        }
    }

    cout << endl;

    stream.close();

    delete [] tempLineChar;
}

DSString Player::getName(){
    return this->name;
}

void Player::addPoints(int points){
    this->points += points;
}

int Player::getPoints(){
    return this->points;
}
