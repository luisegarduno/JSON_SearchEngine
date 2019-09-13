#ifndef PLAYER_H
#define PLAYER_H

#include "dsstring.h"


class Player{

    private:
        DSString TeamName;
        DSString name;
        int IDNumber;
        int points;
        int tags;

    public:
        Player();
        Player(Player*);
        Player(ifstream&);

        int getPoints();
        int getIDNumber();
        DSString& getPlayerName();
        DSString& getTeamName();

        void setIDNumber(int);
        void addPoints(int points);
        void setPlayerName(const DSString&);
        void setTeamName(const DSString&);

        //friend class Team;
        ~Player();

};

#endif // PLAYER_H
