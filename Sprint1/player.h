#ifndef PLAYER_H
#define PLAYER_H

#include "dsstring.h"


class Player{

    private:
        DSString name;
        int points;
        int idNumber;

    public:
        Player();
        Player(int idNumber,DSString name);
        DSString getName();
        void setName(const DSString&);
        void addPoints(int points);
        int getPoints();

};

#endif // PLAYER_H
