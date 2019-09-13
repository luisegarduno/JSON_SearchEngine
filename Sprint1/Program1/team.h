#ifndef TEAM_H
#define TEAM_H
#include "dsstring.h"
#include "player.h"

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
        void thePlayer(ifstream&);
        ~Team();

        //Player * player;

};

#endif // TEAM_H
