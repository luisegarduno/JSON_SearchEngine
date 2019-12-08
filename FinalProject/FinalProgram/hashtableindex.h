#ifndef HASHTABLEINDEX_H
#define HASHTABLEINDEX_H

#include "hashtable.h"
#include "indexinterface.h"

class HashTableIndex : public IndexInterface{
    public:
        HashTableIndex();
        ~HashTableIndex();

    private:
        HashTable<string,int> index;
};

#endif // HASHTABLEINDEX_H
