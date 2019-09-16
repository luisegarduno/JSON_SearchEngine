#ifndef PLAYER_H
#define PLAYER_H

#include "dsstring.h"

class Player{

    private:
        int points;                                 // points obtained by this->player
        int IDNumber;                               // player IDNumber
        DSString name;                              // player Name
        DSString TeamName;                          // player TeamName

    public:
        int tags;                                   // total number this->players tagged

        Player();                                   // default Player constructor

        void setIDNumber(int);                      // setter for this->player's IDNumber
        void addPoints(int points);                 // adds points to this->players total score
        void setTeamName(const DSString&);          // setter for this->players TeamName
        void setPlayerName(const DSString&);        // setter for this->players Name

        int getPoints();                            // returns this->players points
        int getIDNumber();                          // returns this->players IDNumber
        DSString& getTeamName();                    // returns this->players TeamName
        DSString& getPlayerName();                  // returns this->player Name

        void print();
};

#endif // PLAYER_H
