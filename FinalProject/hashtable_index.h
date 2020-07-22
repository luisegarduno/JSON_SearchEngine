#ifndef HASHTABLE_INDEX_H
#define HASHTABLE_INDEX_H

#include "hashtable.h"
#include "index_interface.h"

using std::ifstream;

class HashTable_Index : public Index_Interface{
    public:
        HashTable_Index();
        void load_Index();
        word& search_Index(word&);
        void insert_In_Index(word&, string&);
        void clear_Index();
        void print_Index();
        ~HashTable_Index();

    private:
        HashTable<string,word> index;
};

#endif // HASHTABLE_INDEX_H
