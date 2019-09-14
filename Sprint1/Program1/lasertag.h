#ifndef LASERTAG_H
#define LASERTAG_H
#include "dsstring.h"
//#include "player.h"
#include "team.h"
#include "linkedlist.h"

class LaserTag{

    public:
        LaserTag();
        LaserTag(char* argv[]);                                             // passes

        int getPointValue(int);
        int verbosityPartOne(DSString&,LinkedList&,LinkedList&);
        int verbosityPartTwo(DSString&,LinkedList&,LinkedList&);

        void verbosityLow(DSString&,Team&,Team&);
        void verbosityMedium(DSString&,DSString&);
        void verbosityHigh(DSString&,DSString&);
};

#endif // LASERTAG_H
