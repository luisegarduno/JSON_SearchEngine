#ifndef LASERTAG_H
#define LASERTAG_H
#include "team.h"
#include "dsstring.h"
#include "linkedlist.h"

class LaserTag{

    private:
        LinkedList teamA;                               // LinkedList for each team
        LinkedList teamB;

    public:
        LaserTag();
        LaserTag(char* argv[]);

        int getPointValue(int);                         // returns points per body area
        int verbosityPartOne(DSString&);                // gets points for TeamA
        int verbosityPartTwo(DSString&);                // gets points for TeamB

        void verbosityLow(DSString&,Team&,Team&);
        void verbosityMedium(DSString&,Team&,Team&);
        void verbosityHigh(DSString&,Team&,Team&);
};

#endif // LASERTAG_H
