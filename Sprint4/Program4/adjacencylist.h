#ifndef ADJACENCYLISU_H
#define ADJACENCYLISU_H

#include <iostream>
#include "dsstack.h"
#include "dsstring.h"
#include "dslinkedlist.h"


template <class U>
class AdjacencyList{
    private:
        DSLinkedList< DSLinkedList<U> > adjacency_list;

    public:
        AdjacencyList();
        void add(U,U,double,double,U);
        DSLinkedList<U>& checkOuter(U,U);
        bool checkInner(U, const DSLinkedList<U>&);
};

template<class U>
AdjacencyList<U>::AdjacencyList(){

}

template<class U>
void AdjacencyList<U>::add(U originCity, U destinationCity, double cost, double time, U airline){
    DSLinkedList<U> aList = checkOuter(originCity, airline);             // Check list of orgination cities

    if(aList.head != nullptr){                                  // if aList isn't empty
        bool dataExists = checkInner(destinationCity,aList);    // Check if flight

        if(!dataExists){
            aList.append(destinationCity);                      // add destination to Origin Node (originCity)

            aList = checkOuter(destinationCity,airline);

        }
    }

    else{
        DSLinkedList<DSLinkedList<U>> newLinkedListA;
        newLinkedListA.append(aList);
        newLinkedListA.append(originCity);                      // add this LinkedList to adjacencyList
        bool dataExists = checkInner(destinationCity,newLinkedListA);

        if(!dataExists){
            newLinkedListA.append(destinationCity);
        }

        adjacency_list.append(newLinkedListA);
    }
}

template<class U>
DSLinkedList<U>& AdjacencyList<U>::checkOuter(U city, U airline){          // check list of origination cities
    adjacency_list.resetIterator();

    static DSLinkedList<U> newCityLinkedList = DSLinkedList<U>();

    if(adjacency_list.size == 0 && adjacency_list.iteratorIsValid() == false){
        return newCityLinkedList;
    }

    else {
        while(adjacency_list.iteratorIsValid() != false || adjacency_list.getIterator() != city){
            adjacency_list.iterateForward();
        }

        if(adjacency_list.iteratorIsValid() == false && adjacency_list.getIterator() != city){
            newCityLinkedList.append(city);
            return newCityLinkedList;
        }

        else {
            newCityLinkedList = adjacency_list.getIterator();
            return newCityLinkedList;
        }
    }
}

template<class U>
bool AdjacencyList<U>::checkInner(U city, const DSLinkedList<U>& aList){
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
