#ifndef LASERTAG_H
#define LASERTAG_H
#include "dsstring.h"
#include "player.h"

class LaserTag{

    private:

    public:
        LaserTag();
        LaserTag(char* argv[]);
        void verbosityLow(const DSString&,const DSString&);
        void verbosityMedium(const DSString&,const DSString&);
        void verbosityHigh(const DSString&,const DSString&);
};

#endif // LASERTAG_H
