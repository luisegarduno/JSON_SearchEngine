#ifndef AVLTREEINDEX_H
#define AVLTREEINDEX_H

#include "avltree.h"
#include "indexinterface.h"

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

using std::string;
using std::fstream;
using std::stringstream;
using std::istringstream;
using std::ifstream;

class AvlTreeIndex : public IndexInterface{
    public:
        AvlTreeIndex();
        ~AvlTreeIndex();
        void load_Index();
        void search_Index();
        void insert_In_Index(new_word_obj&, string&);
        void clear_Index();

    private:
        AVLTree<new_word_obj> index;
};

#endif // AVLTREEINDEX_H
