#ifndef HASHTABLEENTRY_H
#define HASHTABLEENTRY_H

#include <iostream>

using std::cout;
using std::endl;
using std::string;


template<typename KEY, typename VALUE>
struct HashTableEntry{
    KEY key;
    VALUE value;
    HashTableEntry* next;
    HashTableEntry* previous;

    HashTableEntry(KEY key, VALUE value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

#endif // HASHTABLEENTRY_H
