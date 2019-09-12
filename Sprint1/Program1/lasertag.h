#ifndef LASERTAG_H
#define LASERTAG_H
#include "dsstring.h"
#include "player.h"
#include <fstream>


class LaserTag{

    private:

    public:
        LaserTag();
        LaserTag(char* argv[]);
        void verbosityLow( DSString&,const DSString&);
        void verbosityMedium(DSString&,const DSString&);
        void verbosityHigh(DSString&,const DSString&);
};

#endif // LASERTAG_H
