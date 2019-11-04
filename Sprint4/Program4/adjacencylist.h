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
        DSLinkedList<U> checkOuter(U);
        bool checkInner(U, const DSLinkedList<U>&);
};

template<typename U>
AdjacencyList<U>::AdjacencyList(){
}

template<typename U>
void AdjacencyList<U>::add(U originCity, U destinationCity){
    DSLinkedList<U> aList = checkOuter(originCity);                 // Check list of orgination cities
    DSLinkedList<U> bList = checkOuter(destinationCity);

    if(aList.head != nullptr){                                           // if aList isn't empty
        cout << "in bool" << endl;
        bool dataExists = checkInner(destinationCity,aList);              // Check if flight

        if(!dataExists){
            aList.append(destinationCity);                            // add destination to Origin Node (originCity)
        }
    }

    else if(aList.head == nullptr){
        cout << "in here" << endl;
        DSLinkedList<U> newLinkedListA;                              // Declare head/Origination city of newLinkedList
        newLinkedListA.append(originCity);                             // add this LinkedList to adjacencyList
        adjacency_list.append(newLinkedListA);
    }

    if(bList.head != nullptr){
        bool dataExists = checkInner(originCity,bList);                   // Check if flight exists

        if(!dataExists){
            bList.append(originCity);                                 // add Origin Node (originCity) to new Origin Node (destinationCity)
        }
    }

    else if(bList.head == nullptr){
        cout << "in here" << endl;
        DSLinkedList<U> newLinkedListB;                              // Declare head/Origination city of newLinkedList
        newLinkedListB.append(destinationCity);                        // add this LinkedList to adjacencyList
        adjacency_list.append(newLinkedListB);
    }
}

template<typename U>
DSLinkedList<U> AdjacencyList<U>::checkOuter(U city){             // check list of origination cities
    DSLinkedList<U> newCityLinkedList = DSLinkedList<U>();

    if(adjacency_list.size == 0 && adjacency_list.hasNext() == false){
        return newCityLinkedList;
    }

    else {
        while(adjacency_list.hasNext() != false || adjacency_list.newIterator() != city){
            adjacency_list.newIterator() = adjacency_list.getNext();
        }

        if(adjacency_list.hasNext() == false && adjacency_list.newIterator() != city){
            newCityLinkedList.append(city);
            adjacency_list.getNext() = newCityLinkedList;
            return newCityLinkedList;
        }

        else {
            adjacency_list.newIterator();
            return newCityLinkedList;
        }
    }
}

template<typename U>
bool AdjacencyList<U>::checkInner(U city, const DSLinkedList<U>& aList){
    cout << "in here" << endl;
    DSLinkedList<U> temp = aList;
    cout << "passed temp" << endl;
    temp.newIterator();
    cout << "created new" << endl;

    while(temp.hasNext() != false || temp.newIterator() != city){
        temp.newIterator() = temp.getNext();
    }
    if(temp.hasNext() == true){
        cout << "returning" << endl;
        return false;
    }
    else if(temp.hasNext() != false && temp.newIterator() == city){
        cout << "returning" << endl;
        return true;
    }
    else {
        cout << "returning" <<endl;
        return true;
    }
}


#endif // ADJACENCYLISU_H
