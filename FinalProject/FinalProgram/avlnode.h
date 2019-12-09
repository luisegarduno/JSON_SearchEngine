#ifndef AVLNODE_H
#define AVLNODE_H

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

using std::list;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::underflow_error;

template <class T>
class AvlNode{
    private:
        template<class X> friend class AVLTree;

        T element;

        // Parent Node will always contain a left and right child
        AvlNode<T>* left;
        AvlNode<T>* right;
        int height;

        AvlNode(const T&, AvlNode*, AvlNode*, int h = 0);

        AvlNode* findMin(AvlNode<T>* ) const;
        AvlNode* findMax(AvlNode<T>* ) const;
};

template<class T>
AvlNode<T>::AvlNode(const T& theElement, AvlNode<T>* lt, AvlNode<T>* rt, int h)
    : element(theElement), left(lt), right(rt), height(h) {      }


// findMin is recursively called to find where t->left = null,
// t is therefore the left most child(smallest)
template <class T>
AvlNode<T>* AvlNode<T>::findMin(AvlNode<T> *t) const{
    if(t == nullptr){
        return nullptr;
    }

    if(t->left == nullptr){
        return t;
    }

    return findMin(t->left);
}

// findMax is recursively called to find where t->right = null,
// t is therefore the right most child (largest)
template <class T>
AvlNode<T>* AvlNode<T>::findMax(AvlNode<T>* t) const{
    if(t == nullptr){
        return nullptr;
    }

    if(t->right == nullptr){
        return t;
    }

    return findMin(t->right);
}

#endif // AVLNODE_H
