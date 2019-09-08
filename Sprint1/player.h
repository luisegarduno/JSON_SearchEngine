#ifndef PLAYER_H
#define PLAYER_H

#include "dsstring.h"


class Player{

    private:
        DSString name;
        DSString idNumber;
        int points;
        //int idNumber;

    public:
        Player();
        Player(ifstream&);
        DSString getName();
        void setName(const DSString&);
        void setIdNumber(const DSString&);
        void addPoints(int points);
        int getPoints();

};

#endif // PLAYER_H
