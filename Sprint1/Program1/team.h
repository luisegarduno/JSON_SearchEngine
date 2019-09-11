#ifndef TEAM_H
#define TEAM_H
#include "dsstring.h"
#include "player.h"

class Team{

    private:
        DSString teamName;
        DSString numOfMembers;
        int teamSize;
        Player * player;

    public:
        Team();
        Team(ifstream&);
        void setTeamName(const char*);
        void setNumOfMembers(const char *);
        DSString getTeamName();
        int getNumOfMembers();
        void addMember(ifstream&);
        Player * getTeamMember();
        ~Team();

        //Player * player;

};

#endif // TEAM_H
