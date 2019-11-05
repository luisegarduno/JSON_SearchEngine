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
    U dataReverse = newFlightData.flightDataReversed();

    DSLinkedList<U> aList = checkOuter(newFlightData.getOrigin(), newFlightData.getAirline());             // Check list of orgination cities

    if(adjacency_list.head != nullptr){                                  // if aList isn't empty
        bool dataExists = checkInner(newFlightData.getDestination(),aList);    // Check if flight

        if(!dataExists){
            //DSNode<U> flightNodeInformation;
            aList.append(newFlightData);                      // add destination to Origin Node (originCity)

            aList = checkOuter(newFlightData.getDestination(),newFlightData.getAirline());

        }
    }

    else{

        DSLinkedList<U> newLinkedList;
        newLinkedList.append(newFlightData);
        adjacency_list.append(newLinkedList);                      // add this LinkedList to adjacencyList
        bool dataExists = checkInner(newFlightData.getDestination(),newLinkedList);

        if(!dataExists){
            newLinkedList.append(newFlightData);
        }

        adjacency_list.append(newLinkedList);
    }
}

template<class U>
DSLinkedList<U>& AdjacencyList<U>::checkOuter(DSString originData, DSString airlineData){          // check list of origination cities
    adjacency_list.resetIterator();

    static DSLinkedList<U> newCityLinkedList = DSLinkedList<U>();


    if(adjacency_list.size == 0 && adjacency_list.iteratorIsValid() == false){
        return adjacency_list.getIterator();
    }

    else {
        while(adjacency_list.iteratorIsValid() != false || (adjacency_list.getIterator().head != originData)){
            cout << adjacency_list.getIterator().head << endl;
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
bool AdjacencyList<U>::checkInner(DSString city, const DSLinkedList<U>& flightList){
    auto temp = flightList;

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

    auto temp2 = flightList.iterator;
    auto temp3 = temp2.getOrigin();





    return (aFlag) ? true : false;
}


#endif // ADJACENCYLISU_H
