#ifndef DSNODE_H
#define DSNODE_H

//#include "dslinkedlist.h"

template<class T>
class DSNode{

    template<class U> friend class DSLinkedList;

    private:
        T data;
        DSNode<T>* next;
        DSNode<T>* previous;

    public:
        DSNode();
        DSNode(T);
        DSNode(const DSNode<T>& d2);
        ~DSNode();

};

template<class T>
DSNode<T>::DSNode() : next(nullptr), previous(nullptr){

}

template<class T>
DSNode<T>::DSNode(T aValue) : next(nullptr), previous(nullptr), data(aValue){

}

template<class T>
DSNode<T>::DSNode(const DSNode<T>& data2) : next(nullptr), previous(nullptr), data(data2.data){

}

template<class T>
DSNode<T>::~DSNode<T>(){

}

#endif // DSNODE_H
