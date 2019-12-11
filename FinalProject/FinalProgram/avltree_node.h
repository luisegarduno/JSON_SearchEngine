#ifndef AVLTREE_NODE_H
#define AVLTREE_NODE_H

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

using std::list;
using std::string;
using std::vector;
using std::cout, std::endl;
using std::underflow_error;

template <class T>
class AvlTree_Node{
    private:
        template<class X> friend class AvlTree;

        T element;

        // Parent Node will always contain a left and right child
        AvlTree_Node<T>* left;
        AvlTree_Node<T>* right;
        int height;

        AvlTree_Node(const T&, AvlTree_Node*, AvlTree_Node*, int h = 0);

        AvlTree_Node* findMin(AvlTree_Node<T>* ) const;
        AvlTree_Node* findMax(AvlTree_Node<T>* ) const;
};

template<class T>
AvlTree_Node<T>::AvlTree_Node(const T& theElement, AvlTree_Node<T>* lt, AvlTree_Node<T>* rt, int h)
    : element(theElement), left(lt), right(rt), height(h) {      }


// findMin is recursively called to find where t->left = null,
// t is therefore the left most child(smallest)
template <class T>
AvlTree_Node<T>* AvlTree_Node<T>::findMin(AvlTree_Node<T> *t) const{
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
AvlTree_Node<T>* AvlTree_Node<T>::findMax(AvlTree_Node<T>* t) const{
    if(t == nullptr){
        return nullptr;
    }

    if(t->right == nullptr){
        return t;
    }

    return findMin(t->right);
}

#endif // AVLTREE_NODE_H

