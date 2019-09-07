#ifndef TEAM_H
#define TEAM_H
#include "dsstring.h"

class Team{

    private:
        DSString teamName;
        DSString numOfMembers;
        int teamSize;

    public:
        Team();
        Team(DSString&);
        void setTeamName(const char*);
        void setNumOfMembers(const char *);
        DSString getTeamName();
        int getNumOfMembers();

};

#endif // TEAM_H
