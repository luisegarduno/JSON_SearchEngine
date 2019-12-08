#ifndef HASHTABLEENTRY_H
#define HASHTABLEENTRY_H

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
