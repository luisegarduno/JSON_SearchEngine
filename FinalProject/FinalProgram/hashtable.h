#ifndef HASHTABLE_H
#define HASHTABLE_H

/*
 * Implementation based around:
 * https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables-chaining-with-singly-linked-lists
 */

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include "hashtableentry.h"

using std::hash;
using std::cout;
using std::endl;
using std::string;

// Initialize table size so resizing isn't necessary
const auto TABLE_SIZE = 3250000;

template<typename KEY, typename VALUE>
class HashTable{
    private:
        int totalNumberOfNodes;
        HashTableEntry<KEY,VALUE>** theHashTable;

    public:
        // Default constructor
        HashTable();

        auto HashFunc(KEY);

        void insert(KEY,VALUE);

        void print();

        // Searches and returns KEY if found
        VALUE& searchKey(KEY k);

        // Clears HashTable
        void clear();

        // Destructor
        ~HashTable();
};

template<typename KEY, typename VALUE>
HashTable<KEY,VALUE>::HashTable(){
    theHashTable = new HashTableEntry<KEY,VALUE>*[TABLE_SIZE];

    for(auto count = 0; count < TABLE_SIZE; count++){
        theHashTable[count] = nullptr;
    }
}

template<typename KEY,typename VALUE>
auto HashTable<KEY,VALUE>::HashFunc(KEY key){
    size_t theSize = hash<KEY>()(key);
    return theSize % TABLE_SIZE;
}

template<typename KEY,typename VALUE>
void HashTable<KEY,VALUE>::insert(KEY key,VALUE value){
    auto hashVALUE = HashFunc(key);
    HashTableEntry<KEY,VALUE>* previous = nullptr;
    HashTableEntry<KEY,VALUE>* entry = theHashTable[hashVALUE];

    while(entry != nullptr){
        previous = entry;
        entry = previous->next;
    }

    if(entry == nullptr){
        entry = new HashTableEntry<KEY,VALUE>(key,value);

        if(previous == nullptr){
            theHashTable[hashVALUE] = entry;
        }

        else{
            previous->next = entry;
        }
    }

    else{
        entry->value = value;
    }
}

template<typename KEY,typename VALUE>
VALUE& HashTable<KEY,VALUE>::searchKey(KEY key){
    VALUE hashValue = HashFunc(key);
    bool flag = false;
    HashTableEntry<KEY,VALUE>* entry = theHashTable[hashValue];
    if(entry != nullptr){
        while(entry != nullptr){
            if(entry->key == key){
                flag = true;
            }
            if(flag){
                return entry->value;
            }
            entry = entry->next;
        }
    }
    if(!flag){
        //cout << "No Element found at key" << key << endl;
    }
}

template<typename KEY,typename VALUE>
void HashTable<KEY,VALUE>::print(){
    HashTableEntry<KEY,VALUE>* tempPrint;

    for(auto counter = 0; counter < TABLE_SIZE; counter++){
        tempPrint = theHashTable[counter];
        if(tempPrint != nullptr){
            while(tempPrint != nullptr){
                cout << tempPrint->key << " --> File: " << tempPrint->value.the_File << " --> Frequency: " << tempPrint->value.the_Frequency << endl;
                tempPrint = tempPrint->next;
            }
        }
    }
}

template<typename KEY,typename VALUE>
void HashTable<KEY,VALUE>::clear(){
    for(auto count = 0; count  < TABLE_SIZE; count++){
        HashTableEntry<KEY,VALUE>* entry = theHashTable[count];

        while(entry != nullptr){
            if(entry != nullptr){
                delete entry;
                break;
            }
            else{
                HashTableEntry<KEY,VALUE>* next = entry->next;
                delete entry;
                entry = next;
            }
        }
    }
    delete [] theHashTable;
}

template<typename KEY,typename VALUE>
HashTable<KEY,VALUE>::~HashTable(){
    clear();
}

#endif // HASHTABLE_H
