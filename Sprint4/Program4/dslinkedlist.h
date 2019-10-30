#ifndef DSLINKEDLIST_H
#define DSLINKEDLIST_H

#include <iostream>
#include "dsnode.h"
#include "dsstack.h"


template<typename T>
class DSLinkedList{
    DSNode<T> * head;
    DSNode<T> * tail;
    DSNode<T> * current;

    int size;

    private:
        void remove(DSNode<T>*);

    public:
        DSLinkedList();
        DSLinkedList(const DSLinkedList<T>&);
        void append(T);
        void removeAt(int);
        void print();
        void clear();

        T& newIterator();
        T& next();
        T getAt(T);
        bool hasNext();

        ~DSLinkedList();

};

template<typename T>
DSLinkedList<T>::DSLinkedList(){
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    size = 0;
}

template<typename T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList<T>& originalLinkedList){
    DSNode<T>* aCurrent = 0;
    DSNode<T>* aNext = 0;

    if(originalLinkedList.head == 0){
        head = 0;
    }

    else{
        head = new DSNode<T>;
        head->previous = originalLinkedList.head->previous;
        head->data = originalLinkedList->data;

        aCurrent = head;
        aNext = originalLinkedList.head;

        while(aNext){
            aCurrent->next = new DSNode<T>;
            aCurrent = aCurrent->next;
            aCurrent->previous = aNext->data;

            aNext = aNext->next;
        }

        aCurrent->next = 0;

    }
}

template<typename T>
void DSLinkedList<T>::append(T x){
    DSNode<T>* newNode = new DSNode<T>(x);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    size++;
}

template<typename T>
T& DSLinkedList<T>::newIterator(){          // sets new head of LinkedList
    this->current = this->head;
    return this->current->data;
}

template<typename T>
T& DSLinkedList<T>::next(){                 // points to the next node in the LinkedList
    this->current = this->current->next;
    return this->current->data;
}

template<typename T>
bool DSLinkedList<T>::hasNext(){
    if(this->current->next == nullptr || this->current == nullptr){
        DSLinkedList<T> myList = DSLinkedList<T>();

        int value = myList.newIterator();

        for(int i = 0; i < myList.size; i++){
            cout << value << endl;
            value = myList.next();
        }
        return true;
    }
    return false;
}

template<typename T>
void DSLinkedList<T>::removeAt(int index){
    if (index >= size) {
        std::cout << "\nNothing here" << index << std::endl << std::endl;
    }
    else {
        DSNode<T>* aCurrent = head;
        int count = 0;

        while (count != index) {
          aCurrent = aCurrent->next;
          count++;
        }

        remove(aCurrent);

        size--;
      }
}

template<typename T>
void DSLinkedList<T>::print(){
    if(head == nullptr){
        cout << "Nothing Available" << endl;
    }

    else{
        DSNode<T>* aCurrent = head;
        int count = 0;
        cout << endl;

        while(aCurrent != nullptr){
            cout << "Node[" << ++count << "]: " << aCurrent->data << endl;
            aCurrent = aCurrent->next;
        }
    }
}

template<typename T>
void DSLinkedList<T>::remove(DSNode<T>* currentNode){
    DSNode<T>* nextNode = currentNode->next;
    DSNode<T>* previousNode = currentNode->previous;

    if(nextNode != nullptr){
        nextNode->previous = previousNode;
    }

    if(previousNode != nullptr){
        previousNode->next = nextNode;
    }

    if(currentNode == head){
        head = nextNode;
    }

    if(currentNode == tail){
        tail = previousNode;
    }

}

template<typename T>
T DSLinkedList<T>::getAt(T x){
    if(head == nullptr){
        return -1;
    }


    else{
        DSNode<T>* aCurrent = head;

        for(int i = 0; i < x; i++){
            aCurrent = aCurrent->next;
        }

        return aCurrent->data;
    }
}

template<typename T>
void DSLinkedList<T>::clear(){
    DSNode<T>* c = head;
    while(c != nullptr){
        c = c->next;
        delete head;
        head = c;
    }
}

template<typename T>
DSLinkedList<T>::~DSLinkedList<T>(){
    clear();
}

#endif // DSLINKEDLIST_H
