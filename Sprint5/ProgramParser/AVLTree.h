#ifndef AVLTREE_H
#define AVLTREE_H


#include <list>
#include <string>
#include <vector>
#include <iostream>
#include "AVLNode.h"
#include <stdexcept>

using std::list;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::underflow_error;

template<class T>
class AVLTree{
    private:
        AVLNode<T>* root;

        int height(AVLNode<T>*) const;
        int max(int lhs, int rhs) const;
        void insert(const int&, AVLNode<T>*&);
        void rotateWithLeftChild(AVLNode<T>*&);
        void rotateWithRightChild(AVLNode<T>*&);
        void doubleWithLeftChild(AVLNode<T>*&);
        void doubleWithRightChild(AVLNode<T>*&);

    public:
        AVLTree();
        AVLTree(const AVLTree& rhs);

        const int& findMin() const;
        const int& findMax() const;

        bool contains(const T&) const;
        void insert(const T& x);

        bool isEmpty() const;
        void makeEmpty();
        ~AVLTree();
};

template<class T>
AVLTree<T>::AVLTree() : root(nullptr){
}

template<class T>
AVLTree<T>::AVLTree(const AVLTree& rhs) : root(nullptr) {
    *this = rhs;
}

template<class T>
const int& AVLTree<T>::findMin() const{
    if(isEmpty()){
        throw underflow_error("Exception Throw: Underflow -> findMin()");
    }

    return findMin(root)->element;
}

template<class T>
const int& AVLTree<T>::findMax() const{
    if(isEmpty()){
        throw underflow_error("Exception Throw: Underflow -> findMax()");
    }

    return findMax(root)->element;
}

template<class T>
bool AVLTree<T>::contains(const T& x) const{
        return contains( x, root );
}

template <class T>
void AVLTree<T>::insert(const T& x){
    insert(x, root);
}

template<class T>
bool AVLTree<T>::isEmpty() const{
    return ( (root == nullptr) ? true : false);
}

template<class T>
void AVLTree<T>::makeEmpty(){
    AVLNode<T>* c = root;
    while(c != nullptr){
        makeEmpty( c->left );
        makeEmpty( c->right );
        delete c;
        root = c;
    }
}

template<class T>
AVLTree<T>::~AVLTree(){
    makeEmpty();
}

template<class T>
int AVLTree<T>::height(AVLNode<T>* t) const{
    return t == nullptr ? -1 : t->height;
}

template<class T>
int AVLTree<T>::max(int lhs, int rhs) const{
    return lhs > rhs ? lhs : rhs;
}

template<class T>
void AVLTree<T>::insert(const int& x, AVLNode<T>*& t){
    if(t == nullptr){
        t = new AVLNode<T>(x,nullptr,nullptr);
    }

    else if(x < t->element){
        insert(x,t->left);

        if(height(t->left) - height(t->right) == 2){
            if(x < t->left->element){
                rotateWithLeftChild(t); // Case 1
            }

            else{
                doubleWithLeftChild(t); // Case 2
            }
        }
    }

    else if(t->element < x){
        insert(x,t->right);

        if(height(t->right) - height(t->left) == 2){
            if(t->right->element < x){
                rotateWithRightChild(t); // Case 4
            }
            else{
                doubleWithRightChild(t); // Case 3
            }
        }
    }
    else;

    t->height = max(height(t->left), height(t->right)) + 1;
}

/* Rotate binary tree node with left child.
   For AVL trees, this is a single rotation for case 1.
   Update heights, then set new root.                */
template<class T>
void AVLTree<T>::rotateWithLeftChild(AVLNode<T>*& k2){
    AVLNode<T>* k1 = k2->left;

    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;

    k2 = k1;
}

/* Rotate binary tree node with right child.
   For AVL trees, this is a single rotation for case 1.
   Update heights, then set new root.                */
template<class T>
void AVLTree<T>::rotateWithRightChild(AVLNode<T>*& k1){
    AVLNode<T>*k2 = k1->right;

    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;

    k1 = k2;
}

/* Double rotate binary tree node: first right child.
   with its right child; then node k3 with new left child.
   For AVL trees, this is a double rotation for case 2.
   Update heights, then set new root.                  */
template<class T>
void AVLTree<T>::doubleWithLeftChild(AVLNode<T>*& k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}


/* Double rotate binary tree node: first right child.
   with its left child; then node k1 with new right child.
   For AVL trees, this is a double rotation for case 3.
   Update heights, then set new root.                  */
template<class T>
void AVLTree<T>::doubleWithRightChild(AVLNode<T>*& k1){
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}


#endif // AVLTREE_H
