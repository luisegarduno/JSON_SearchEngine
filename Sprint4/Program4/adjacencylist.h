#ifndef ADJACENCYLISU_H
#define ADJACENCYLISU_H

#include <iostream>
#include "dsstring.h"
#include "dslinkedlist.h"
#include "dsstack.h"

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
    DSLinkedList<U> ListOne;
    DSLinkedList<U> ListTwo;
}

template<typename U>
void AdjacencyList<U>::add(U originCity, U destinationCity){
    DSLinkedList<U> aList = checkOuter(originCity);                 // Check list of orgination cities
    DSLinkedList<U> bList = checkOuter(destinationCity);

    if(aList != nullptr){                                           // if aList isn't empty
        bool dataExists = checkInner(destinationCity,aList);              // Check if flight

        if(!dataExists){
            aList.append(destinationCity);                            // add destination to Origin Node (originCity)
        }
    }

    else if(aList == nullptr){
        DSLinkedList<U> newLinkedListA;                              // Declare head/Origination city of newLinkedList
        newLinkedListA.append(originCity);                             // add this LinkedList to adjacencyList
        adjacency_list.append(newLinkedListA);
    }

    else if(bList != nullptr){
        bool dataExists = checkInner(originCity,bList);                   // Check if flight exists

        if(!dataExists){
            bList.append(originCity);                                 // add Origin Node (originCity) to new Origin Node (destinationCity)
        }
    }

    else if(bList == nullptr){
        DSLinkedList<U> newLinkedListB;                              // Declare head/Origination city of newLinkedList
        newLinkedListB.append(destinationCity);                        // add this LinkedList to adjacencyList
        adjacency_list.append(newLinkedListB);
    }
}

template<typename U>
DSLinkedList<U>& AdjacencyList<U>::checkOuter(U city){             // check list of origination cities
    adjacency_list.newIterator();

    if(adjacency_list.getListSize() == 0 && adjacency_list.hasNext() == true){
        return adjacency_list.newIterator();
    }
    else {

        DSLinkedList<U> temp = adjacency_list.newIterator();

        while(temp.hasNext() != false || temp.newIterator() != city){
            temp.newIterator() = temp.next();
        }

        return adjacency_list.newIterator();
    }
}

template<typename U>
bool AdjacencyList<U>::checkInner(U city, const DSLinkedList<U>& aList){
    DSLinkedList<U> temp = aList->head;

    while(temp.hasNext() != false || temp.newIterator() != city){
        temp.newIterator() = temp.next();
    }
    if(temp.hasNext() == true){
        return false;
    }
    else if(temp.hasNext() != false && temp.newIterator() == city){
        return true;
    }
}


#endif // ADJACENCYLISU_H
