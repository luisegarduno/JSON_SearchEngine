#ifndef HASHTABLEINDEX_H
#define HASHTABLEINDEX_H

#include <fstream>
#include <iostream>
#include "hashtable.h"
#include "index_interface.h"

using std::string;
using std::ifstream;

class HashTableIndex : public Index_Interface{
    public:
        HashTableIndex();
        void load_Index();
        new_word_obj& search_Index(new_word_obj&);
        void insert_In_Index(new_word_obj&, string&);
        void clear_Index();
        void print_Index();
        ~HashTableIndex();

    private:
        HashTable<string,new_word_obj> index;
};

#endif // HASHTABLEINDEX_H
