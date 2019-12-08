#ifndef HASHTABLE_H
#define HASHTABLE_H

/*
 * Implementation based around:
 * https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables-chaining-with-singly-linked-lists
 * */

#include <list>
#include <vector>
#include <string>
#include <algorithm>

using std::string;

// Initialize table size so resizing isn't necessary
const long TABLE_SIZE = 32;

template<typename KEY, typename VALUE>
class HashTable{
    private:

        template<typename aKEY, typename aVALUE>
        struct HashTableEntry{
            aKEY key;
            aVALUE value;
            HashTableEntry* next;
            HashTableEntry* previous;

            HashTableEntry(aKEY key, aVALUE value){
                this->key = key;
                this->value = value;
                this->next = nullptr;
            }
        };

        HashTableEntry<KEY,VALUE>** theHashTable;

    public:
        // Default constructor
        HashTable();

        void insert(KEY,VALUE);

        VALUE HashFunc(KEY);

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

    for(long count = 0; count < TABLE_SIZE; count++){
        theHashTable[count] = nullptr;
    }
}

template<typename KEY,typename VALUE>
VALUE HashTable<KEY,VALUE>::HashFunc(KEY key){
    return key % TABLE_SIZE;
}

template<typename KEY,typename VALUE>
void HashTable<KEY,VALUE>::insert(KEY key,VALUE value){
    long hashVALUE = HashFunc(key);
    HashTableEntry<KEY,VALUE> * previous = nullptr;
    HashTableEntry<KEY,VALUE> * entry = theHashTable[hashVALUE];

    while(entry != nullptr){
        previous = entry;
        entry = entry->next;
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
void HashTable<KEY,VALUE>::clear(){
    for(long count = 0; count  < TABLE_SIZE; count++){
        HashTableEntry<KEY,VALUE>* entry = theHashTable[count];
    }
    delete [] theHashTable;
}

template<typename KEY,typename VALUE>
HashTable<KEY,VALUE>::~HashTable(){

}



#endif // HASHTABLE_H
