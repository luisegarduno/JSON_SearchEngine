#ifndef AVLTREE_INDEX_H
#define AVLTREE_INDEX_H

#include "avltree.h"
#include "index_interface.h"

using std::ifstream;

class AvlTree_Index : public Index_Interface{
    public:
        AvlTree_Index();
        void load_Index();
        word& search_Index(word&);
        void insert_In_Index(word&, string&);
        void clear_Index();
        void print_Index();
        ~AvlTree_Index();

    private:
        AvlTree<word> index;
};

#endif // AVLTREE_INDEX_H
