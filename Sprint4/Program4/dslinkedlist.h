#ifndef DSLINKEDLIST_H
#define DSLINKEDLIST_H

#include <iostream>
#include "dsnode.h"
#include "flightdata.h"

template<class T>
class DSLinkedList{

    template<class U> friend class AdjacencyList;

    DSNode<T> * head;
    DSNode<T> * tail;
    DSNode<T> * iterator;

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
        DSLinkedList<T>& operator=(const DSLinkedList<T>&);

        bool exists();
        bool operator!=(const DSLinkedList<T>&) const;
        int getListSize() const;


        // Custom Iterator


        T& getIterator();               // Custom iterator functions
        T& getNextIterator();
        void resetIterator();
        void iterateForward();
        bool iteratorIsValid();

        ~DSLinkedList();
};

template<class T>
DSLinkedList<T>::DSLinkedList(): head(nullptr), tail(nullptr), iterator(nullptr), size(0){        // Default constructor
}

template<class T>
DSLinkedList<T>::DSLinkedList(T x) {
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

        if(v2LinkedList.head == nullptr){
            head = tail = nullptr;
        }

        else {
            this->clear();

            DSNode<T>* newHead;
            DSNode<T>* newTail;

            newHead = v2LinkedList.head;
            newTail = v2LinkedList.tail;

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
    //DSNode<T>* current = head;
    DSNode<T>* newNode = new DSNode<T>(x);

    if(head == nullptr){           // if Linked List is empty
        head = new DSNode<T>(x);                         // declare new node as the head and tail
        tail = head;
    }
    else{
        /*while(current->next != nullptr){
            current = current->next;
        }
        //current->next = new DSNode<T>(x);*/
        tail->next = newNode;                   // if linked list contains node already, set the node after the tail = to new node(previously nullptr)
        newNode->previous = tail;               // at the end, the previous node prior to declaring new node, is the tail
        tail = newNode;                         // declare new node as the tail
    }
    size++;                                     // increment Linked List Size

}

template<class T>
void DSLinkedList<T>::resetIterator(){
    this->iterator = this->head;                // set's the iterator Nodeptr to the head of LinkedList
}

template<class T>
T& DSLinkedList<T>::getIterator(){

    return this->iterator->data;             // return iterator node data
}

template<class T>
T& DSLinkedList<T>::getNextIterator(){                 // points to the next node in the LinkedList
    this->iterator = this->iterator->next;
    return this->iterator->data;
}

template<class T>
void DSLinkedList<T>::iterateForward(){
    if(this->iterator != nullptr || this->iterator->next != nullptr){
        this->iterator = this->iterator->next;
    }
}

template<class T>
bool DSLinkedList<T>::iteratorIsValid(){
    if(this->iterator != nullptr){
        return true;
    }
    else{
        //this->iterator = this->iterator->previous;
        //resetIterator();
        return false;
    }
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
        DSNode<T>* temp = head;                        // set the head = to temp Current node
        int count = 0;                          // counter

        while (count != index) {
          temp = temp->next;            // set the iterator node = to the next node
          count++;                              // increment counter until index is reached
        }

        remove(temp);

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

        while(aCurrent != nullptr){                 // cycles & prints all values in linked list
            cout << aCurrent->data.getDestination() << " (" << aCurrent->data.getAirline() << ") ";
            aCurrent = aCurrent->next;
            if(aCurrent != nullptr){
                cout << "--> ";
            }
        }
        cout << endl;
    }
}

template<class T>
void DSLinkedList<T>::remove(DSNode<T>* iteratorNode){
    DSNode<T>* nextNode = iteratorNode->next;
    DSNode<T>* previousNode = iteratorNode->previous;

    if(iteratorNode != nullptr){                     // checks to see if passed node is empty
        if(nextNode != nullptr){
            nextNode->previous = previousNode;
        }

        if(previousNode != nullptr){
            previousNode->next = nextNode;
        }

        if(iteratorNode == head){
            head = nextNode;                        // deletes head and new head is declared
        }

        if(iteratorNode == tail){                    // deletes tail
            tail = previousNode;
        }
        delete iteratorNode;
    }

    resetIterator();

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
    if(this->iterator != aLinkedList.iterator){
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

    if(this->iterator != aLinkedList.iterator){
        return true;
    }
    if(this->iterator->data != aLinkedList.iterator->data){
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
