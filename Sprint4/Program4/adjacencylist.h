#ifndef ADJACENCYLISU_H
#define ADJACENCYLISU_H

#include <iostream>
#include "dsnode.h"
#include "flightdata.h"
#include "dslinkedlist.h"

template <class U>
class AdjacencyList{
    private:
        DSLinkedList< DSLinkedList<U> > adjacency_list;

    public:
        AdjacencyList();
        void add(U);
        void printAdjacencyList();
        DSLinkedList<U>& checkOuter(DSString,DSString);
        DSLinkedList<U> getAllOrigins(DSString);
        bool checkInner(DSString,DSString, const DSLinkedList<U>&);
};

template<class U>
AdjacencyList<U>::AdjacencyList(){
}

template<class U>
void AdjacencyList<U>::add(U newFlightData){
    DSLinkedList<U>* aList = &checkOuter(newFlightData.getOrigin(), newFlightData.getAirline());             // Check list of orgination cities

    if(aList != nullptr){                                  // if adjacencyList.head isn't empty

        bool dataExists = checkInner(newFlightData.getAirline(),newFlightData.getDestination(),*aList);    // Check if flight

        if(!dataExists){
            aList->append(newFlightData);                      // add destination to Origin Node (originCity)
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

    DSNode< DSLinkedList<U> >* currentLinkedList = adjacency_list.head;

    while(currentLinkedList != nullptr){
        if(currentLinkedList->data.head->data.getOrigin() == originCity){
            if(currentLinkedList->data.head->data.getAirline() == airlineData){
                return currentLinkedList->data;
            }
        }
        currentLinkedList = currentLinkedList->next;
    }

    if(currentLinkedList == nullptr){
        DSLinkedList<U>* temp = nullptr;
        return *temp;
    }

    return currentLinkedList->data;
}

template<class U>
DSLinkedList<U> AdjacencyList<U>::getAllOrigins(DSString originCity){          // check list of origination cities

    DSNode< DSLinkedList<U> >* currentLinkedList = adjacency_list.head;

    while(currentLinkedList != nullptr){
        if(currentLinkedList->data.head->data.getOrigin() == originCity){
            return currentLinkedList->data;

        }
        currentLinkedList = currentLinkedList->next;
    }

    if(currentLinkedList == nullptr){
        DSLinkedList<U> temp;
        return temp;
    }

    return currentLinkedList->data;
}


template<class U>
bool AdjacencyList<U>::checkInner(DSString airlineComp,DSString destinationCity, const DSLinkedList<U>& aFlightList){
    auto tempIterator = aFlightList;
    tempIterator.resetIterator();

    while(tempIterator.iteratorIsValid()){
        if(tempIterator.getIterator().getDestination() == destinationCity){
            if(tempIterator.getIterator().getAirline() == airlineComp){
                return true;
            }
        }
            tempIterator.iterateForward();
    }
    return false;
}

template<class U>
void AdjacencyList<U>::printAdjacencyList(){
    DSNode< DSLinkedList<U> >* currentLinkedList = adjacency_list.head;

    while(currentLinkedList != nullptr){
       cout << currentLinkedList->data.head->data.getOrigin() << " --> ";
       currentLinkedList->data.print();
       cout << "   |"<< endl;
       cout << "   V" << endl;
       currentLinkedList = currentLinkedList->next;
    }
}


#endif // ADJACENCYLISU_H
