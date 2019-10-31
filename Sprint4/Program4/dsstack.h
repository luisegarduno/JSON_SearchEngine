#include <iostream>
#include "dsvector.h"

#ifndef DSSTACK_H
#define DSSTACK_H

//template <class U> class DSLinkedList{};

template<class T>
class DSStack{

    private:
        DSVector<T> aData;
        //DSLinkedList<T> aData;

    public:
        DSStack();
        T pop();
        T& peek();
        void push(T);
        bool isEmpty();
};

template<class T>
DSStack<T>::DSStack(){
    this->aData = DSVector<T>();            // initializes DSVector<T>
    //this->aData = DSLinkedList<T>();
}

template<class T>
T DSStack<T>::pop(){
    T data1 = this->peek();                 // stores tail in temp data1
    aData.popBack();                        // deletes tail from data vector
    return data1;                           // returns stored data1

    /*
    T data1 = this->getAt(tail);
    aData.popLastNode();
    return data1;
    */

}

template<class T>
void DSStack<T>::push(T x){
    aData.pushBack(x);                      // pushes element onto DSVector
    //aData.append(x);
}

template<class T>
T& DSStack<T>::peek(){                      // returns tail of data vector
    return this->aData.elementIndex(this->aData.getSize() - 1);
    //return this->aData.getAt(this->aData.getListSize() - 1);
}

template<class T>
bool DSStack<T>::isEmpty(){                 // checks to see if DSVector is empty
    return ( (this->aData.getSize() == 0) ? true : false);
    //return ( (this->aData.getListSize() == 0) ? true : false);
}

#endif // DSSTACK_H
