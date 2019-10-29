#ifndef DSSTACK_H
#define DSSTACK_H

#include <iostream>
#include "dsvector.h"

template<typename T>
class DSStack{
    private:
        DSVector<T> data;

    public:
        DSStack();
        T pop();
        T& peek();
        void push(T);
        bool isEmpty();
};

template<typename T>
DSStack<T>::DSStack(){

}

template<typename T>
T DSStack<T>::pop(){
    T data1 = this->peek();                 // stores tail in temp data1
    data.popBack();                         // deletes tail from data vector
    return data1;                           // returns stored data1
}

template<typename T>
void DSStack<T>::push(T x){
    data.pushBack(x);
}

template<typename T>
T& DSStack<T>::peek(){                      // returns tail of data vector
    return this->data.elementIndex(this->data.getSize() - 1);
}

template<typename T>
bool DSStack<T>::isEmpty(){
    return ( (data.getSize() = 0) ? true : false);
}

#endif // DSSTACK_H
