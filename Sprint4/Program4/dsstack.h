#ifndef DSSTACK_H
#define DSSTACK_H

#include <iostream>
#include "dsnode.h"
#include "flightdata.h"
#include "dslinkedlist.h"

template<class T>
class DSLinkedList;

using std::cout;
using std::endl;

template<class T>
class DSStack : DSLinkedList<T>{

    private:
        DSLinkedList<T> stackData;
        T top;
        size_t stackSize;

    public:
        DSStack();
        T pop();
        T peek();
        void push(T);
        bool isEmpty();

        T topValue();
        size_t sizeOfStack();
        DSLinkedList<T>& getDataLL();
};

template<class T>
DSStack<T>::DSStack(): stackSize(0){
}

template<class T>
T DSStack<T>::pop(){
    T returnValue;
    if(!isEmpty()) {
        returnValue = stackData.popFirstNode();
        if(stackData.head != 0){
            top = stackData.head->getData();
        }
        return returnValue;
    }                             // returns stored data1
    return returnValue;
}

template<class T>
void DSStack<T>::push(T x){
    stackData.pushToFront(x);
    top = x;                           // pushes element onto DSLinkedList
    stackSize++;
}

template<class T>
T DSStack<T>::peek(){                           // returns tail of data linked list
    try {
        return this->stackData.getAt(this->stackData.getListSize() - 1);
    } catch (OUT_OF_BOUNDS) {
        throw OUT_OF_BOUNDS();
    }
}

template<class T>
T DSStack<T>::topValue(){
    return stackData.getHead();
}

template<class T>
DSLinkedList<T>& DSStack<T>::getDataLL(){
    return stackData;
}

template<class T>
size_t DSStack<T>::sizeOfStack(){
    return stackSize;
}

template<class T>
bool DSStack<T>::isEmpty(){                 // checks to see if DSLinkedList is empty
    return ( (this->stackData.head == nullptr) ? true : false);
}



#endif // DSSTACK_H
