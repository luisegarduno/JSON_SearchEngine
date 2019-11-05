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
    DSLinkedList<U> aList = checkOuter(newFlightData.origin, newFlightData.airline);             // Check list of orgination cities

    if(adjacency_list.head != nullptr){                                  // if aList isn't empty
        bool dataExists = checkInner(newFlightData.destination,aList);    // Check if flight

        if(!dataExists){
            DSNode<U> flightNodeInformation;
            aList.append(newFlightData.destination);                      // add destination to Origin Node (originCity)

            aList = checkOuter(newFlightData.destination,newFlightData.airline);

        }
    }

    else{
        DSLinkedList<U> newLinkedList = DSLinkedList<U>();
        newLinkedList.append(newFlightData);
        adjacency_list.append(newLinkedList);                      // add this LinkedList to adjacencyList
        bool dataExists = checkInner(newFlightData.destination,newLinkedList);

        if(!dataExists){
            newLinkedList.append(newFlightData.destination);
        }

        adjacency_list.append(newLinkedList);
    }
}

template<class U>
DSLinkedList<U>& AdjacencyList<U>::checkOuter(DSString originData, DSString airlineData){          // check list of origination cities
    adjacency_list.resetIterator();

    static DSLinkedList<U> newCityLinkedList = DSLinkedList<U>();

    if(adjacency_list.size == 0 && adjacency_list.iteratorIsValid() == false){
        return adjacency_list.head;
    }

    else {
        while(adjacency_list.iteratorIsValid() != false || (adjacency_list.getIterator() != originData)){
            adjacency_list.iterateForward();
        }

        if(adjacency_list.iteratorIsValid() == false && adjacency_list.getIterator() != originData){
            newCityLinkedList.append(originData);
            return newCityLinkedList;
        }

        else {
            newCityLinkedList = adjacency_list.getIterator();
            return newCityLinkedList;
        }
    }
}

template<class U>
bool AdjacencyList<U>::checkInner(DSString city, const DSLinkedList<U>& aList){
    auto temp = aList;
    temp.resetIterator();

    bool aFlag = false;
    while(temp.iteratorIsValid()){
        if(temp.getIterator() == city){
            aFlag = true;
        }
        else{
            temp.iterateForward();
        }
    }

    return (aFlag) ? true : false;
}


#endif // ADJACENCYLISU_H
