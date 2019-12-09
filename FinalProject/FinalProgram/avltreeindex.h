#ifndef AVLTREEINDEX_H
#define AVLTREEINDEX_H

#include "avltree.h"
#include "index_interface.h"

#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ifstream;

class AvlTreeIndex : public Index_Interface{
    public:
        AvlTreeIndex();
        void load_Index();
        new_word_obj& search_Index(new_word_obj&);
        void insert_In_Index(new_word_obj&, string&);
        void clear_Index();
        void print_Index();
        ~AvlTreeIndex();

    private:
        AVLTree<new_word_obj> index;
};

#endif // AVLTREEINDEX_H
