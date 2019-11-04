#ifndef DSLINKEDLIST_H
#define DSLINKEDLIST_H

#include <iostream>
#include "dsstring.h"
#include "dsnode.h"
#include "dsstack.h"

template<class T>
class DSLinkedList{

    template<class U> friend class AdjacencyList;

    DSNode<T> * head;
    DSNode<T> * tail;
    DSNode<T> * current;

    int size;                           // Size of Linked List

    private:
        void remove(DSNode<T>*);        // Remove node

    public:
        DSLinkedList();
        DSLinkedList(T);
        DSLinkedList(const DSLinkedList<T>&);

        void print();                   // print all values in Linked List
        void clear();                   // Clears the Linked List, also used to destruct memory from heap
        void append(T);                 // add node to Linked List
        void removeAt(int);             // remove specific index value (passed in parameter)
        void popLastNode();

        T getAt(T);                     // returns element at specific index
        T& getNext();
        T& newIterator();               // Custom iterator functions
        DSLinkedList<T>& operator=(const DSLinkedList<T>&);

        bool exists();
        bool hasNext();
        bool operator!=(const DSLinkedList<T>&) const;
        int getListSize() const;



        ~DSLinkedList();
};

template<class T>
DSLinkedList<T>::DSLinkedList(): head(nullptr), tail(nullptr), current(nullptr), size(0){        // Default constructor
}

template<class T>
DSLinkedList<T>::DSLinkedList(T x){
    head = new DSNode<T>(x);
    size++;
}

template<class T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList<T>& originalLinkedList){


    if(originalLinkedList.head == nullptr){           // if original Linked List is empty
            head = tail = nullptr;                    // head is = to nullptr
        }

        else{
            DSNode<T>* aCurrent = originalLinkedList.head;
            head = tail = nullptr;
            auto count = 0;

            while(aCurrent != nullptr){
                DSNode<T>* newNode = new DSNode<T>();
                newNode->previous = nullptr;
                newNode->next = nullptr;
                newNode->data = aCurrent->data;

                if(count == 0){
                    head = tail = newNode;
                }
                else {
                    tail->next = newNode;
                    newNode->previous = tail;
                    tail = tail->next;
                }
                ++count;
                aCurrent = aCurrent->next;
            }
         }
}

template<class T>
DSLinkedList<T>& DSLinkedList<T>::operator=(const DSLinkedList<T>& v2LinkedList) {
    if(this != &v2LinkedList){

        if(v2LinkedList.size == 0){
            head = nullptr;
        }

        else {
            this->clear();

            DSNode<T>* newHead;
            DSNode<T>* newTail;

            newHead = v2LinkedList.head;
            newTail = new DSNode<T>(newHead->data);

            head = newHead;
            DSNode<T>* temp;

            while(newHead != nullptr){
                temp = new DSNode<T>(newHead->data);
                newTail->next = temp;
                newTail = newTail->next;
                newHead = newHead->next;
            }
        }
    }

    return *this;
}

template<class T>
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

template<class T>
T& DSLinkedList<T>::newIterator(){
    if(current){
        current = head;         // set's the current Nodeptr to the head of LinkedList
    }
    return current->data;             // return current node data
}

template<class T>
T& DSLinkedList<T>::getNext(){                 // points to the next node in the LinkedList
    this->current = this->current->next;
    return this->current->data;
}

template<class T>
bool DSLinkedList<T>::hasNext(){
    if(this->current == nullptr || this->current->next == nullptr){
        return false;
    }
    return true;
}

template<class T>
int DSLinkedList<T>::getListSize() const{
    return size;
}

template<class T>
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

template<class T>
void DSLinkedList<T>::print(){
    if(head == nullptr){
        cout << "Nothing Available" << endl;
    }

    else{
        DSNode<T>* aCurrent = head;
        int count = 0;

        while(aCurrent != nullptr){                 // cycles & prints all values in linked list
            cout << "Node[" << ++count << "]: " << aCurrent->data << endl;
            aCurrent = aCurrent->next;
        }
    }
}

template<class T>
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

template<class T>
void DSLinkedList<T>::popLastNode(){
    remove(tail);

    size--;
}

template<class T>
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

template<class T>
void DSLinkedList<T>::clear(){
    DSNode<T>* c = head;
    while(c != nullptr){
        c = c->next;
        delete head;
        head = c;
    }
}


template<class T>
bool DSLinkedList<T>::operator!=(const DSLinkedList<T>& aLinkedList)const {
    if(this->head != aLinkedList.head){
        return true;
    }
    if(this->tail != aLinkedList.tail){
        return true;
    }
    if(this->current != aLinkedList.current){
        return true;
    }

    if(size != aLinkedList.size){
        return true;
    }
    if(head != nullptr){
        DSNode<T>* c = head;
        for(int i = 0; i < size; i++){
            if(c == nullptr){
                return false;
            }
            c = c->next;
        }
        return true;
    }

    if(this->current != aLinkedList.current){
        return true;
    }
    if(this->current->data != aLinkedList.current->data){
        return true;
    }

    return false;

}

template<class T>
bool DSLinkedList<T>::exists(){
    if(head == nullptr){
        return false;
    }
    else {
        return true;
    }
}


template<class T>
DSLinkedList<T>::~DSLinkedList<T>(){
    clear();                                // call the clear member function to deconstruct elements from HEAP
}

#endif // DSLINKEDLIST_H
