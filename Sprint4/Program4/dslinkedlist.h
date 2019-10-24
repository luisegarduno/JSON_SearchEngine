#ifndef DSLINKEDLIST_H
#define DSLINKEDLIST_H

#include "dsnode.h"

template<typename T>
class DSLinkedList{
    private:
        DSNode<T> * head;
        DSNode<T> * tail;

    public:
        DSLinkedList();
        void push_head();

};

#endif // DSLINKEDLIST_H
