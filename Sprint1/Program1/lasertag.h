#ifndef LASERTAG_H
#define LASERTAG_H
#include "dsstring.h"
#include "player.h"
#include "team.h"
#include "linkedlist.h"

class LaserTag{

    public:
        LaserTag();
        LaserTag(char* argv[]);
        //int getMatchPartA(DSString&,LinkedList&,LinkedList&);
        //int getMatchPartB(DSString&,LinkedList&,LinkedList&);
        int verbosityLow(DSString&,DSString&,LinkedList&,LinkedList&);
        void verbosityMedium(DSString&,DSString&);
        void verbosityHigh(DSString&,DSString&);
        int getPointValue(int);
};

#endif // LASERTAG_H
