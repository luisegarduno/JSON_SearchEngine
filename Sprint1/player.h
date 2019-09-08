#ifndef PLAYER_H
#define PLAYER_H

#include "dsstring.h"


class Player{

    private:
        DSString name;
        DSString idNumber;
        int points;
        int ID_AsInt;

    public:
        Player();
        Player(ifstream&);
        DSString getName();
        DSString getIDNumber();
        void setName(const DSString&);
        void setIDNumber(const DSString&);
        void setIDNumber_AsInt(const DSString&);

        void addPoints(int points);
        int getPoints();

};

#endif // PLAYER_H
