#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "dslinkedlist.h"

template <typename T>
class AdjacencyList{
    private:
        DSLinkedList< DSLinkedList<T> > adjacency_list;

    public:
        DSLinkedList<T>& checkOuter(T);
       bool checkInner(T, const DSLinkedList<T>&);
        void add(T,T);
};

template<typename T>
void AdjacencyList<T>::add(T data1, T data2){
    DSLinkedList<T> aList = checkOuter(data1);

    if(aList != nullptr){
        bool dataExists = checkInner(data2);

        if(!dataExists){
            aList.push(data2);
        }

        else {
            DSLinkedList<T> newLinkedList;
            //newLinkedList.push();
        }
    }
}

template<typename T>
DSLinkedList<T>& AdjacencyList<T>::checkOuter(T data1){

}

template<typename T>
bool AdjacencyList<T>::checkInner(T data1, const DSLinkedList<T>& adjList){

}


#endif // ADJACENCYLIST_H
