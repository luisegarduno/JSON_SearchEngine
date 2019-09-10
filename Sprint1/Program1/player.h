#ifndef PLAYER_H
#define PLAYER_H

#include "dsstring.h"


class Player{

    private:
        DSString name;
        DSString idNumber;
        int points;
        int ID_AsInt;
        int tags;

    public:
        Player();
        Player(ifstream&);
        Player(int); // Player(int IDnum, DSString MemberName,int pointArea)
        Player(Player*);
        DSString getName();
        DSString getIDNumber();
        void setName(const DSString&);
        void setIDNumber(const DSString&);
        void setIDNumber_AsInt(const DSString&);

        void addPoints(int points);
        int getPoints();
        int getMemberID_AsInt();
        friend class Team;
        ~Player();

};

#endif // PLAYER_H
