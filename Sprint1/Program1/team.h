#ifndef TEAM_H
#define TEAM_H
#include "dsstring.h"
#include "player.h"

class Team{

    private:
        DSString teamName;
        int teamSize;
        Player * player;

    public:
        Team();
        Team(DSString&);
        void setTeamName(const char*);
        void setTeamSize(int);
        DSString getTeamName();
        int getTeamSize();
        void addMember(ifstream&);
        Player * getTeamMember();
        ~Team();

        //Player * player;

};

#endif // TEAM_H
