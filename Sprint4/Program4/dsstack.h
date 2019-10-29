#ifndef DSSTACK_H
#define DSSTACK_H

#include <iostream>
#include "dsvector.h"

template<typename T>
class DSStack{
    private:
        T data;
        DSVector<T> vec;

    public:
        DSStack();
        void pop();
        void peek();
        void push(T);
        bool isEmpty();
};

template<typename T>
DSStack<T>::DSStack(){

}

template<typename T>
void DSStack<T>::pop(){
    vec.popBack();
}

template<typename T>
void DSStack<T>::push(T x){
    vec.pushBack(x);
}

template<typename T>
void DSStack<T>::peek(){
    vec.peek();
}

template<typename T>
bool DSStack<T>::isEmpty(){
    return ( (vec.getSize() = 0) ? true : false);
}

#endif // DSSTACK_H
