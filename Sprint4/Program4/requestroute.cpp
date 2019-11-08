#include "requestroute.h"

RequestRoute::RequestRoute(){
}

RequestRoute::RequestRoute(DSString theOrigin,DSString theDestination,DSString theType){
    setRequestedOrigin(theOrigin);
    setRequestedDestination(theDestination);
    setRequestedSort(theType);
}


DSString RequestRoute::getRequestedOrigin(){
   return requestedOrigin;
}


DSString RequestRoute::getRequestedDestination(){
    return requestedDestination;
}

DSString RequestRoute::getRequestedSort(){
    return requestedSort;
}


void RequestRoute::setRequestedOrigin(DSString requestedOrigin){
    this->requestedOrigin = requestedOrigin;
}


void RequestRoute::setRequestedDestination(DSString requestedDestination){
    this->requestedDestination = requestedDestination;
}


void RequestRoute::setRequestedSort(DSString requestedSort){
    if(requestedSort == "T" || requestedSort == "t"){
        this->requestedSort = requestedSort;
    }
    else if(requestedSort == "S" || requestedSort == "s"){
        this->requestedSort = requestedSort;
    }
}
