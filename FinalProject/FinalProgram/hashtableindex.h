#ifndef HASHTABLEINDEX_H
#define HASHTABLEINDEX_H

#include "hashtable.h"
#include "indexinterface.h"

class HashTableIndex : public IndexInterface{
    public:
        HashTableIndex();
        ~HashTableIndex();
        void search_Index();
        void insert_In_Index();
        void clear_Index();

    private:
        HashTable<string,int> index;
};

#endif // HASHTABLEINDEX_H
