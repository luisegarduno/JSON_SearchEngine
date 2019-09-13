#include "player.h"
#include "dsstring.h"

Player::Player(){
    tags = 0;
    points = 0;
    IDNumber = 0;
    name = nullptr;
}

/*Player::Player(ifstream& stream){
    int num, a = 0, b = 0;
    stream >> num;
    setIDNumber(num);

    char * tempLineChar = new char[100];
    stream.getline(tempLineChar,100);
    DSString theName(tempLineChar);

    while(theName[a] != '\0' && theName[0] != 0){
        if(theName[a] == ' '){
            b = a;
        }
        a++;
    }
    setPlayerName(theName.substring(b,a));

    delete [] tempLineChar;
}*/

Player::Player(Player* originalPlayer){
    this->IDNumber = originalPlayer->getIDNumber();
    this->name = originalPlayer->getPlayerName();
}

DSString& Player::getPlayerName(){
    return this->name;
}

void Player::setPlayerName(const DSString& name){
    this->name = name;
}

void Player::setIDNumber(int IDNumber){
    this->IDNumber = IDNumber;
}

int Player::getIDNumber(){
    return this->IDNumber;
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

void Player::print(){
    cout << getIDNumber() << " " << getPlayerName() << endl;
}

Player::~Player(){
    //cout << "in Player Destructor" << endl;

}
