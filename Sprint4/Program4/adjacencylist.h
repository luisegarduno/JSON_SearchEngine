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

        DSLinkedList<U>& checkOuter(DSString,DSString);
        bool checkInner(DSString,DSString, const DSLinkedList<U>&);

        DSLinkedList<U> getAllOrigins(DSString);

        void printAdjacencyList();
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
DSLinkedList<U> AdjacencyList<U>::getAllOrigins(DSString aCity){
   DSNode< DSLinkedList<U> >* currentLinkedList = adjacency_list.head;
   DSLinkedList<U> flightOrigin = DSLinkedList<U>();
   currentLinkedList->getData().resetIterator();

   if(currentLinkedList == nullptr){
        DSLinkedList<U> temp;
        return temp;
    }

    while(currentLinkedList != nullptr){
        currentLinkedList->getData().resetIterator();
        while(currentLinkedList->getData().iteratorIsValid()){
            if(currentLinkedList->getData().getIterator().getOrigin() == aCity){
                //cout << "-->CITY: " << currentLinkedList->data.getIterator().getOrigin() << "\t\tAIRLINE: " << currentLinkedList->data.getIterator().getAirline() << endl;
                flightOrigin.append(currentLinkedList->getData().getIterator());
                break;
            }

            currentLinkedList->getData().iterateForward();
        }

        currentLinkedList = currentLinkedList->next;
    }

    return flightOrigin;
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
    cout << "-----------------ADJACENCY LIST----------------------" << endl;
    while(currentLinkedList != nullptr){
       cout << currentLinkedList->data.head->data.getOrigin() << " --> ";
       currentLinkedList->data.print();
       currentLinkedList = currentLinkedList->next;
       if(currentLinkedList != nullptr){
           cout << "   |"<< endl;
           cout << "   V" << endl;
       }
    }
    cout << "-----------------------------------------------------" << endl;
}

#endif // ADJACENCYLISU_H
