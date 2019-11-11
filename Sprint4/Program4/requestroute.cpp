#include <iostream>
#include "requestroute.h"

RequestRoute::RequestRoute(){
}

RequestRoute::RequestRoute(DSString theOrigin,DSString theDestination,DSString theType){
    setRequestedOrigin(theOrigin);
    setRequestedDestination(theDestination);
    setRequestedSort(theType);
}

void RequestRoute::setRequestedOrigin(DSString requestedOrigin){
    this->requestedOrigin = requestedOrigin;
}


void RequestRoute::setRequestedDestination(DSString requestedDestination){
    this->requestedDestination = requestedDestination;
}


void RequestRoute::setRequestedSort(DSString requestedSort){
    if(requestedSort == DSString("T") || requestedSort == DSString("C")){
        this->requestedSort = requestedSort;
    }
    else{
        cout << "Invalid Sort" << endl;
    }
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



