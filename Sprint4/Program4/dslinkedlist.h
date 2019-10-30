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

    int size;                           // Size of Linked List

    private:
        void remove(DSNode<T>*);        // Remove node

    public:
        DSLinkedList();
        DSLinkedList(const DSLinkedList<T>&);
        void append(T);                 // add node to Linked List
        void removeAt(int);             // remove specific index value (passed in parameter)
        void print();                   // print all values in Linked List
        void clear();                   // Clears the Linked List, also used to destruct memory from heap

        T& newIterator();               // Custom iterator functions
        T& next();
        T getAt(T);                     // returns element at specific index
        bool hasNext();

        ~DSLinkedList();
};

template<typename T>
DSLinkedList<T>::DSLinkedList(){        // Default constructor
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    size = 0;                           // Size of DSLinkedList is initially 0
}

template<typename T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList<T>& originalLinkedList){
    DSNode<T>* aCurrent = 0;
    DSNode<T>* aNext = 0;

    if(originalLinkedList.head == 0){           // if original Linked List is empty
        head = 0;                               // head is = to 0
    }

    else{
        head = new DSNode<T>;
        head->previous = originalLinkedList.head->previous;
        head->data = originalLinkedList->data;

        aCurrent = head;                        // begin at head
        aNext = originalLinkedList.head;

        while(aNext){
            aCurrent->next = new DSNode<T>;     // set next node = to new Node
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

    if(head == nullptr || size == 0){           // if Linked List is empty
        head = newNode;                         // declare new node as the head and tail
        tail = newNode;
    }
    else{
        tail->next = newNode;                   // if linked list contains node already, set the node after the tail = to new node(previously nullptr)
        newNode->previous = tail;               // at the end, the previous node prior to declaring new node, is the tail
        tail = newNode;                         // declare new node as the tail
    }
    size++;                                     // increment Linked List Size


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
            value = myList.next();              // adds values to linked list
        }
        return true;
    }
    return false;
}

template<typename T>
void DSLinkedList<T>::removeAt(int index){
    if (index >= size) {                        // if index is greater than Linked List Size
        std::cout << "\nNothing here" << index << std::endl << std::endl;
    }
    else {
        DSNode<T>* aCurrent = head;             // set the head = to temp Current node
        int count = 0;                          // counter

        while (count != index) {
          aCurrent = aCurrent->next;            // set the current node = to the next node
          count++;                              // increment counter until index is reached
        }

        remove(aCurrent);

        size--;                                 // decrement Linked List size
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

        while(aCurrent != nullptr){                 // cycles & prints all values in linked list
            cout << "Node[" << ++count << "]: " << aCurrent->data << endl;
            aCurrent = aCurrent->next;
        }
    }
}

template<typename T>
void DSLinkedList<T>::remove(DSNode<T>* currentNode){
    DSNode<T>* nextNode = currentNode->next;
    DSNode<T>* previousNode = currentNode->previous;

    if(currentNode != nullptr){                     // checks to see if passed node is empty
        if(nextNode != nullptr){
            nextNode->previous = previousNode;
        }

        if(previousNode != nullptr){
            previousNode->next = nextNode;
        }

        if(currentNode == head){
            head = nextNode;                        // deletes head and new head is declared
        }

        if(currentNode == tail){                    // deletes tail
            tail = previousNode;
        }
        delete currentNode;
    }

}

template<typename T>
T DSLinkedList<T>::getAt(T x){
    if(head == nullptr){
        return -1;
    }
    else{
        DSNode<T>* aCurrent = head;         // begin at head

        for(int i = 0; i < x; i++){
            aCurrent = aCurrent->next;      // cycle through Linked List
        }

        return aCurrent->data;              // return element from linked list (specified in parameter
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
    clear();                                // call the clear member function to deconstruct elements from HEAP
}

#endif // DSLINKEDLIST_H
