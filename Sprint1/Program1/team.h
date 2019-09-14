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
        Team(DSString&);
        void print();
        void setTeamSize(int);
        void setTeamName(const char*);
        int getTeamSize();
        DSString& getTeamName();
        void thePlayer(ifstream&,LinkedList&);
        ~Team();

        //Player * player;

};

#endif // TEAM_H
