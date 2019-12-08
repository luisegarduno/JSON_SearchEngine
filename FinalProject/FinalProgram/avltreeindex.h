#ifndef AVLTREEINDEX_H
#define AVLTREEINDEX_H

#include "avltree.h"
#include "indexinterface.h"

class AvlTreeIndex : public IndexInterface{
    public:
        AvlTreeIndex();
        ~AvlTreeIndex();

    private:
        AVLTree<string> index;
};

#endif // AVLTREEINDEX_H
