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
        bool firstMember;

    public:
        Team();
        Team(DSString&);
        void setTeamName(const char*);
        void setNumOfMembers(const char *);
        DSString getTeamName();
        int getNumOfMembers();
        void addMember(ifstream&);
        bool isFirstMember();
        void setTeamMember(Player*);
        Player * getTeamMember();
        ~Team();

        //Player * player;

};

#endif // TEAM_H
