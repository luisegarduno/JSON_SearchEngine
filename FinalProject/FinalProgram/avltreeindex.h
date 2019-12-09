#ifndef AVLTREEINDEX_H
#define AVLTREEINDEX_H

#include "avltree.h"
#include "indexinterface.h"

class AvlTreeIndex : public IndexInterface{
    public:
        AvlTreeIndex();
        ~AvlTreeIndex();
        void search_Index();
        void insert_In_Index();
        void clear_Index();

    private:
        AVLTree<string> index;
};

#endif // AVLTREEINDEX_H
