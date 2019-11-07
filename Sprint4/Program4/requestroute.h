#ifndef REQUESTROUTE_H
#define REQUESTROUTE_H

#include "dsstring.h"


class RequestRoute{
    private:
        DSString requestedOrigin;
        DSString requestedDestination;
        DSString requestedSort;

    public:
        RequestRoute();
        RequestRoute(DSString,DSString,DSString);
        DSString getRequestedOrigin();
        DSString getRequestedDestination();
        DSString getRequestedSort();

        void setRequestedOrigin(DSString);
        void setRequestedDestination(DSString);
        void setRequestedSort(DSString);
};

#endif // REQUESTROUTE_H
