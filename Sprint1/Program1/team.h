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
        //Player thePlayers;
        DSString teamName;

    public:
        Team();
        Team(DSString&);
        void setTeamSize(int);
        void setTeamName(const char*);
        int getTeamSize();
        DSString& getTeamName();
        Player * getTeamMember();
        void thePlayer(ifstream&,LinkedList&);
        ~Team();

        //Player * player;

};

#endif // TEAM_H
