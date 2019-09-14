#ifndef PLAYER_H
#define PLAYER_H

#include "dsstring.h"

class Player{

    private:
        int tags;
        int points;
        int IDNumber;
        DSString name;
        DSString TeamName;


    public:
        Player();

        int getPoints();
        int getIDNumber();
        DSString& getPlayerName();
        DSString& getTeamName();

        void setIDNumber(int);
        void addPoints(int points);
        void setPlayerName(const DSString&);
        void setTeamName(const DSString&);

        void print();
};

#endif // PLAYER_H
