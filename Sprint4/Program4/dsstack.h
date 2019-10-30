#ifndef DSSTACK_H
#define DSSTACK_H

#include <iostream>
#include "dsvector.h"

template<typename T>
class DSStack{
    private:
        DSVector<T> aData;

    public:
        DSStack();
        T pop();
        T& peek();
        void push(T);
        bool isEmpty();
};

template<typename T>
DSStack<T>::DSStack(){
    this->aData = DSVector<T>();            // initializes DSVector<T>
}

template<typename T>
T DSStack<T>::pop(){
    T data1 = this->peek();                 // stores tail in temp data1
    aData.popBack();                        // deletes tail from data vector
    return data1;                           // returns stored data1
}

template<typename T>
void DSStack<T>::push(T x){
    aData.pushBack(x);                      // pushes element onto DSVector
}

template<typename T>
T& DSStack<T>::peek(){                      // returns tail of data vector
    return this->aData.elementIndex(this->aData.getSize() - 1);
}

template<typename T>
bool DSStack<T>::isEmpty(){                 // checks to see if DSVector is empty
    return ( (this->aData.getSize() == 0) ? true : false);
}

#endif // DSSTACK_H
