#ifndef TEAM_H
#define TEAM_H
#include "player.h"
#include "dsstring.h"
#include "linkedlist.h"

class Team{

    private:
        int teamSize;                                   // Total number of players on team
        int teamPoints;                                 // Total number of points of team
        Player * player;                                // Player pointer
        DSString teamName;                              // Name of team

    public:
        Team();                                         // Default Constructor
        Team(DSString&,LinkedList&);                    // sets teamName,teamSize, & adds players

        void setTeamSize(int);                          // setter for teamSize
        void setTeamPoints(int);                        // setter for teamPoints
        void setTeamName(const char*);                  // setter for teamName
        void thePlayer(ifstream&,LinkedList&);          // reads team file to create & add players to LinkedList

        int getTeamSize();                              // returns teamSize
        int getTeamPoints();                            // returns teamPoints
        DSString& getTeamName();                        // returns teamName
};

#endif // TEAM_H
