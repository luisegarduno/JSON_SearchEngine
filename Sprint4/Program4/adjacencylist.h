#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "dslinkedlist.h"

template <typename T>
class AdjacencyList{
    private:
        //DSLinkedList< DSLinkedList<T> > adjacency_list;

    public:
        //DSLinkedList& checkOuter(T);
        //bool checkInner(T, const DSLinkedList&);
        void add(T,T);
};
/*
template<typename T>
void AdjacencyList<T>::add(T data1, data2){
    DSLinkedList aList = checkOuter(data1);

    if(aList != nullptr){
        bool dataExists = checkInner(data2);

        if(!dataExists){
            aList.push(data2);
        }

        else {
            DSLinkedList newLinkedList();
            newLinkedList.push(data);
        }
}

template<typename T>
DSLinkedList<T>& AdjacencyList<T>::checkOuter(T data1){

}

template<typename T>
bool AdjacencyList<T>::checkInner(T data1, const DSLinkedList& adjList){

}
*/


#endif // ADJACENCYLIST_H
