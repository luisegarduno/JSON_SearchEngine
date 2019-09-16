#include "player.h"

Player::Player(){
    tags = 0;                                               // initializes this->player tags to 0
    points = 0;                                             // initializes this->player points to 0
    IDNumber = 0;                                           // initializes this->player IDNumber to 0
}

void Player::setIDNumber(int IDNumber){
    this->IDNumber = IDNumber;                              // setter for IDNumber
}

void Player::setPlayerName(const DSString& name){
    this->name = name;                                      // setter for name
}

void Player::setTeamName(const DSString& TeamName){
    this->TeamName = TeamName;                              // setter for teamName
}

int Player::getPoints(){
    return this->points;                                    // returns this->player points
}

int Player::getIDNumber(){
    return this->IDNumber;                                  // returns this->player IDNumber
}

DSString& Player::getTeamName(){
    return this->TeamName;                                  // returns this->player TeamName
}

DSString& Player::getPlayerName(){
    return this->name;                                      // returns this->player name
}

void Player::addPoints(int points){
    tags += 1;                                              // increments tag counter by 1
    this->points += points;                                 // adds points to total player points
}

void Player::print(){
    cout << this-> getPlayerName() << " had a total of " << this->tags << " tags" << endl;
}
