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
    adjacency_list = DSLinkedList<U>();
}

template<typename U>
void AdjacencyList<U>::add(U originCity, U destinationCity){
    DSLinkedList<U> aList = checkOuter(originCity);             // Check list of orgination cities

    if(aList.head != nullptr){                                  // if aList isn't empty
        cout << "if" << endl;
        bool dataExists = checkInner(destinationCity,aList);    // Check if flight

        if(!dataExists){
            aList.append(destinationCity);                      // add destination to Origin Node (originCity)
        }
    }

    else if(aList.head == nullptr){
        cout << "else if" << endl;
        DSLinkedList<U> newLinkedListA(originCity);
        //newLinkedListA.append(originCity);                      // add this LinkedList to adjacencyList
        newLinkedListA.append(destinationCity);
        newLinkedListA.print();
        adjacency_list.append(newLinkedListA);
    }
    cout << "Origin List" << endl;
    aList.print();
    cout << endl;
}

template<typename U>
DSLinkedList<U>& AdjacencyList<U>::checkOuter(U city){          // check list of origination cities

    static DSLinkedList<U> newCityLinkedList = DSLinkedList<U>();

    if(adjacency_list.size == 0 && adjacency_list.hasNext() == false){
        //newCityLinkedList.append(city);
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
            newCityLinkedList = adjacency_list.newIterator();
            return newCityLinkedList;
        }
    }
}

template<typename U>
bool AdjacencyList<U>::checkInner(U city, const DSLinkedList<U>& aList){
    auto temp = aList;

    bool aFlag = false;
    while(temp.hasNext()){
        if(temp.newIterator() == city){
            aFlag = true;
        }
        else{
            temp.newIterator() = temp.getNext();
        }
    }

    return (aFlag) ? true : false;
}


#endif // ADJACENCYLISU_H
