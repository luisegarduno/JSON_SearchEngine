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
        new_word_obj& search_Index(new_word_obj&);
        void insert_In_Index(new_word_obj&, string&);
        void clear_Index();
        void print_Index();

    private:
        HashTable<string,new_word_obj> index;
};

#endif // HASHTABLEINDEX_H
