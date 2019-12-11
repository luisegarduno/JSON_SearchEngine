#ifndef HASHTABLE_ENTRY_H
#define HASHTABLE_ENTRY_H

#include <iostream>

using std::string;
using std::cout, std::endl;

template<typename KEY, typename VALUE>
struct HashTable_Entry{
    KEY key;
    VALUE value;
    HashTable_Entry* next;
    HashTable_Entry* previous;

    HashTable_Entry(KEY key, VALUE value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

#endif // HASHTABLE_ENTRY_H
