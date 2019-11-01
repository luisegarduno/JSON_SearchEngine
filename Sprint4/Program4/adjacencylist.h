#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include "dsstring.h"
#include "dslinkedlist.h"
#include "dsstack.h"

template <typename T>
class AdjacencyList{
    private:
        DSLinkedList< DSLinkedList<T> > adjacency_list;

    public:
        void add(T,T);
        DSLinkedList<T>& checkOuter(T);
        bool checkInner(T, const DSLinkedList<T>&);
};

template<typename T>
void AdjacencyList<T>::add(T originCity, T destinationCity){
    DSLinkedList<T> aList = checkOuter(originCity);                 // Check list of orgination cities

    if(aList != nullptr){                                           // if aList isn't empty
        bool dataExists = checkInner(destinationCity);              // Check if flight

        if(!dataExists){
            aList.push(destinationCity);
        }
    }

    else {                                                          // if aList is empty
        DSLinkedList<T> newLinkedList;                              // Declare head/Origination city of newLinkedList
        newLinkedList.push(originCity);                             // add this LinkedList to adjacencyList
        adjacency_list.append(newLinkedList);
    }
}

template<typename T>
DSLinkedList<T>& AdjacencyList<T>::checkOuter(T originCity){             // check list of origination cities
    if(adjacency_list.size == 0 && adjacency_list.head == nullptr){
        return nullptr;
    }
    else {
        DSLinkedList<T> tempCurrent = adjacency_list.head;

        while(tempCurrent != nullptr || tempCurrent != originCity){
            tempCurrent = tempCurrent->next;
        }

        return tempCurrent;
    }
}

template<typename T>
bool AdjacencyList<T>::checkInner(T destinationCity, const DSLinkedList<T>& aList){
    DSLinkedList<T> temp = aList->head;

    while(temp != nullptr || temp != destinationCity){
        temp = temp->next;
    }
    if(temp == nullptr){
        return false;
    }
    else if(temp != nullptr && temp == destinationCity){
        return true;
    }

}


#endif // ADJACENCYLIST_H
