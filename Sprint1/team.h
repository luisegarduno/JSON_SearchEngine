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
        Team(DSString&);
        void setTeamName(const char*);
        void setNumOfMembers(const char *);
        DSString getTeamName();
        DSString getIDNum();
        int getNumOfMembers();
        void setMemberID_AsInt();
        void addMember(ifstream&);

};

#endif // TEAM_H
