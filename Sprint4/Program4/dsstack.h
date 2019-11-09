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
        DSLinkedList<T> aData;
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
    T data1 = this->peek();
    aData.popLastNode();
    return data1;                               // returns stored data1
}

template<class T>
void DSStack<T>::push(T x){
    aData.append(x);                            // pushes element onto DSLinkedList
    //top = x;
    stackSize++;
}

template<class T>
T DSStack<T>::peek(){                           // returns tail of data linked list
    return this->aData.getAt(this->aData.getListSize() - 1);
}

template<class T>
T DSStack<T>::topValue(){
    return aData.getHead();
}

template<class T>
DSLinkedList<T>& DSStack<T>::getDataLL(){
    return aData;
}

template<class T>
size_t DSStack<T>::sizeOfStack(){
    return stackSize;
}

template<class T>
bool DSStack<T>::isEmpty(){                 // checks to see if DSLinkedList is empty
    return ( (this->aData.getListSize() == 0) ? true : false);
}



#endif // DSSTACK_H
