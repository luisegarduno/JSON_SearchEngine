#ifndef DSNODE_H
#define DSNODE_H

#include <iostream>

using std::cout;
using std::endl;

template<class T>
class DSNode{
    // make DSLinkedList a friend of DSNode, this grants DSLinkedList access to private members
    template<class U> friend class DSLinkedList;

    private:
        DSNode<T>* next;
        DSNode<T>* previous;
        T data;

    public:
        DSNode();
        DSNode(T);
        DSNode(const DSNode<T>& d2);
        ~DSNode();

};

template<class T>
DSNode<T>::DSNode() : next(nullptr), previous(nullptr){
}           // Default constructor

template<class T>
DSNode<T>::DSNode(T aValue) : next(nullptr), previous(nullptr), data(aValue){
}           // Constructor with data value passed into it

template<class T>
DSNode<T>::DSNode(const DSNode<T>& data2) : next(nullptr), previous(nullptr), data(data2.data){
}

template<class T>
DSNode<T>::~DSNode<T>(){
}

#endif // DSNODE_H
