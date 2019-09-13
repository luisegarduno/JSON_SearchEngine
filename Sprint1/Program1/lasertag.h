#ifndef LASERTAG_H
#define LASERTAG_H
#include "dsstring.h"
#include "player.h"

class LaserTag{

    public:
        LaserTag();
        LaserTag(char* argv[]);
        void verbosityLow(DSString&,DSString&);
        void verbosityMedium(DSString&,DSString&);
        void verbosityHigh(DSString&,DSString&);
        int getPointValue(int);
};

#endif // LASERTAG_H
