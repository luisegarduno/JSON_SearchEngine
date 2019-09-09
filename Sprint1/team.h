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
        void setMemberID_AsInt();
        int getMemberID_AsInt();
        DSString getTeamName();
        DSString getIDNum();
        int getNumOfMembers();
        void addMember(ifstream&);
        ~Team();

};

#endif // TEAM_H
