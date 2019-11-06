#ifndef ADJACENCYLISU_H
#define ADJACENCYLISU_H

#include <iostream>
#include "dsstack.h"
#include "dsstring.h"
#include "flightdata.h"
#include "dslinkedlist.h"


template <class U>
class AdjacencyList{
    private:
        DSLinkedList< DSLinkedList<U> > adjacency_list;

    public:
        AdjacencyList();
        void add(U);
        DSLinkedList<U>& checkOuter(DSString,DSString);
        bool checkInner(DSString, const DSLinkedList<U>&);
};

template<class U>
AdjacencyList<U>::AdjacencyList(){
}

template<class U>
void AdjacencyList<U>::add(U newFlightData){
    U flightReverse = newFlightData.flightDataReversed();
    DSLinkedList<U> aList = checkOuter(newFlightData.getOrigin(), newFlightData.getAirline());             // Check list of orgination cities

    if(aList.head != nullptr){                                  // if adjacencyList.head isn't empty

        bool dataExists = checkInner(newFlightData.getDestination(),aList);    // Check if flight

        if(!dataExists){
            aList.append(newFlightData);                      // add destination to Origin Node (originCity)



        }
    }

    else{
        DSLinkedList<U> newLinkedList;
        newLinkedList.append(newFlightData);
        adjacency_list.append(newLinkedList);                      // add this LinkedList to adjacencyList
    }
}

template<class U>
DSLinkedList<U>& AdjacencyList<U>::checkOuter(DSString originCity, DSString airlineData){          // check list of origination cities
    adjacency_list.resetIterator();
    DSNode< DSLinkedList<U> >* currentLinkedList = adjacency_list.head;



    if(currentLinkedList->size == 0 && currentLinkedList->iteratorIsValid() == false){
        return currentLinkedList->getIterator();
    }

    else {
        while(currentLinkedList->iteratorIsValid() != false){
            if(currentLinkedList->data.head->data.getOrigin() == originCity){
                if(currentLinkedList->data.head->data.getAirline() == airlineData){
                    break;
                }
            }
            currentLinkedList->iterateForward();
        }
        return this->currentLinkedList;
    }
}

template<class U>
bool AdjacencyList<U>::checkInner(DSString destinationCity, const DSLinkedList<U>& flightList){

    DSLinkedList<U>* tempIterator = flightList.head;

    bool aFlag = false;
    while(tempIterator->iteratorIsValid() != false){
        if(tempIterator->head->data == destinationCity){
            aFlag = true;
            break;
        }
            tempIterator->iterateForward();
    }
    return (aFlag) ? true : false;
}


#endif // ADJACENCYLISU_H
