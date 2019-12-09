#ifndef HASHTABLEINDEX_H
#define HASHTABLEINDEX_H

#include <fstream>
#include "hashtable.h"
#include "indexinterface.h"

using std::string;
using std::ifstream;

class HashTableIndex : public IndexInterface{
    public:
        HashTableIndex();
        ~HashTableIndex();
        void load_Index();
        void search_Index();
        void insert_In_Index(new_word_obj&, string&);
        void clear_Index();

    private:
        HashTable<string,new_word_obj> index;
};

#endif // HASHTABLEINDEX_H
