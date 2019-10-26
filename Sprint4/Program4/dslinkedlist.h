#ifndef DSLINKEDLIST_H
#define DSLINKEDLIST_H

#include "dsnode.h"

template<typename T>
class DSLinkedList{
    DSNode<T> * head;
    DSNode<T> * tail;
    int size;

    private:
        void remove(DSNode<T>*);

    public:
        DSLinkedList();
        DSLinkedList(const DSLinkedList<T>&);
        void append();
        void removeAt(int);
        void print();

};

template<typename T>
DSLinkedList<T>::DSLinkedList(){
    head = nullptr;
    tail = nullptr;
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
void DSLinkedList<T>::append(){
    DSNode<T>* newNode = newNode();

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template<typename T>
void DSLinkedList<T>::removeAt(int index){
    if (index >= size) {
        std::cout << "\nNothing here" << index << std::endl << std::endl;
    }
    else {
        DSNode<T>* current = head;
        int count = 0;

        while (count != index) {
          current = current->next;
          count++;
        }

        remove(current);

        size--;
      }
}

template<typename T>
void DSLinkedList<T>::print(){
    if(head == nullptr){
        cout << "Nothing Available" << endl;
    }

    else{
        DSNode<T>* current = head;
        int count = 0;
        cout << endl;

        while(current != nullptr){
            cout << "Num: " << ++count << endl;
            current = current->next;
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

#endif // DSLINKEDLIST_H
