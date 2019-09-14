#ifndef TEAM_H
#define TEAM_H
#include "dsstring.h"
#include "player.h"
#include "linkedlist.h"

class Team{

    private:
        int teamSize;
        int teamPoints;
        Player * player;
        DSString teamName;

    public:
        Team();
        Team(DSString&,LinkedList&);
        void print();
        void setTeamSize(int);
        void setTeamPoints(int);
        void setTeamName(const char*);
        int getTeamSize();
        int getTeamPoints();

        DSString& getTeamName();
        void thePlayer(ifstream&,LinkedList&);
        ~Team();

};

#endif // TEAM_H
