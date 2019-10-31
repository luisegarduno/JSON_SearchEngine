#ifndef DSSTACK_H
#define DSSTACK_H

#include <iostream>

template<class T>
class DSLinkedList;

using std::cout;
using std::endl;

template<class T>
class DSStack : DSLinkedList<T>{

    private:
        DSLinkedList<T> aData;

    public:
        DSStack();
        T pop();
        T peek();
        void push(T);
        bool isEmpty();
};

template<class T>
DSStack<T>::DSStack(){
    this->aData = DSLinkedList<T>();            // initializes DSLinkedList<T>
}

template<class T>
T DSStack<T>::pop(){
    T data1 = this->peek();                     // stores tail in temp data1
    aData.popLastNode();                        // deletes tail from data list
    return data1;                               // returns stored data1
}

template<class T>
void DSStack<T>::push(T x){
    aData.append(x);                            // pushes element onto DSLinkedList
}

template<class T>
T DSStack<T>::peek(){                           // returns tail of data linked list
    return this->aData.getAt(this->aData.getListSize() - 1);
}

template<class T>
bool DSStack<T>::isEmpty(){                 // checks to see if DSLinkedList is empty
    return ( (this->aData.getListSize() == 0) ? true : false);
}

#endif // DSSTACK_H
