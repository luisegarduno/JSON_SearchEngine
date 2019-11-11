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

        void setRequestedOrigin(DSString);
        void setRequestedDestination(DSString);
        void setRequestedSort(DSString);

        DSString getRequestedOrigin();
        DSString getRequestedDestination();
        DSString getRequestedSort();
};

#endif // REQUESTROUTE_H
