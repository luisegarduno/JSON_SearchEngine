#ifndef ADJACENCYLISU_H
#define ADJACENCYLISU_H

#include <iostream>
#include "dsstack.h"
#include "dsstring.h"
#include "dslinkedlist.h"


template <typename U>
class AdjacencyList{
    private:
        DSLinkedList< DSLinkedList<U> > adjacency_list;

    public:
        AdjacencyList();
        void add(U,U);
        DSLinkedList<U>& checkOuter(U);
        bool checkInner(U, const DSLinkedList<U>&);
};

template<typename U>
AdjacencyList<U>::AdjacencyList(){
    //adjacency_list = DSLinkedList<U>();
}

template<typename U>
void AdjacencyList<U>::add(U originCity, U destinationCity){
    DSLinkedList<U> aList = checkOuter(originCity);             // Check list of orgination cities

    if(aList.head != nullptr){                                  // if aList isn't empty
        bool dataExists = checkInner(destinationCity,aList);    // Check if flight

        if(!dataExists){
            aList.append(destinationCity);                      // add destination to Origin Node (originCity)
        }
    }

    else{
        DSLinkedList<U> newLinkedListA;
        newLinkedListA.append(originCity);                      // add this LinkedList to adjacencyList
        bool dataExists = checkInner(destinationCity,newLinkedListA);

        if(!dataExists){
            newLinkedListA.append(destinationCity);
        }

        adjacency_list.append(newLinkedListA);
    }
}

template<typename U>
DSLinkedList<U>& AdjacencyList<U>::checkOuter(U city){          // check list of origination cities
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

template<typename U>
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
