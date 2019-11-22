#ifndef AVLTREE_H
#define AVLTREE_H

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

template <typename T>
class AVLTree{
    private:
        class AvlNode{
            public:
                T element;
                AvlNode   *left;
                AvlNode   *right;
                int       height;

                AvlNode(const T& theElement, AvlNode* lt, AvlNode* rt, int h = 0)
                    : element(theElement), left(lt), right(rt), height(h) {      }
        };

        AvlNode* root;



        AvlNode* findMin(AvlNode *t) const{
            if(t == nullptr)
                return nullptr;

            if(t->left == nullptr)
                return t;

            return findMin(t->left);
        }

        AvlNode* findMax(AvlNode* t) const{
            if(t != nullptr)
                while(t->right != nullptr)
                    t = t->right;

            return t;
        }

        AvlNode * clone(AvlNode *t) const{
            if(t == nullptr)
                return nullptr;
            else
                return new AvlNode(t->element, clone(t->left), clone(t->right), t->height);
        }
        void insert(const T & x, AvlNode * & t );

        bool contains(const T& x, AvlNode* t) const;

        void makeEmpty(AvlNode*& t);
        void printTree(AvlNode* t) const;

        int height(AvlNode* t) const;
        int max(int lhs, int rhs) const;

        void rotateWithLeftChild(AvlNode*& k2);
        void rotateWithRightChild(AvlNode*& k1);
        void doubleWithLeftChild(AvlNode*& k3);
        void doubleWithRightChild(AvlNode*& k1);

    public:
        AVLTree();
        AVLTree(const AVLTree & rhs);
        ~AVLTree();


        const T& findMin() const;
        const T& findMax() const;

        bool contains(const T& x) const;
        bool isEmpty() const;
        void printTree() const;
        void makeEmpty();
        void insert(const T& x);

        const AVLTree & operator=(const AVLTree& rhs);
};

template<typename T>
AVLTree<T>::AVLTree() : root(nullptr){
}

template<typename T>
AVLTree<T>::AVLTree(const AVLTree& rhs) : root(nullptr){
    *this = rhs;
}

template<typename T>
AVLTree<T>::~AVLTree(){
    makeEmpty();
}

template<typename T>
const T& AVLTree<T>::findMin() const{
    if(isEmpty()){
        throw underflow_error("Exception Throw: Underflow -> findMin()");
    }

    return findMin(root)->element;
}

template<typename T>
const T& AVLTree<T>::findMax() const{
    if(isEmpty()){
        throw underflow_error("Exception Throw: Underflow -> findMax()");
    }

    return findMax(root)->element;
}

template<typename T>
bool AVLTree<T>::contains(const T& x) const{
    return contains(x, root);
}

template<typename T>
bool AVLTree<T>::isEmpty() const{
    return ((root == nullptr) ? true : false);
}

template<typename T>
void AVLTree<T>::printTree() const{
    if(isEmpty()){
        cout << "Empty tree" << endl;
    }

    else{
        printTree(root);
    }
}

template<typename T>
void AVLTree<T>::makeEmpty(){
    makeEmpty(root);
}

template<typename T>
void AVLTree<T>::insert(const T& x){
    insert(x, root);
}

template<typename T>
const AVLTree<T>& AVLTree<T>::operator=(const AVLTree& rhs){
    if(this != &rhs){
        makeEmpty();
        root = clone(rhs.root);
    }

    return *this;
}

template<typename T>
void AVLTree<T>::insert(const T& x, AvlNode*& t){
    if(t == nullptr){
        t = new AvlNode(x, nullptr, nullptr);
    }

    else if(x < t->element){
        insert(x, t->left);

        if(height(t->left) - height(t->right) == 2){
            if(x < t->left->element){
                rotateWithLeftChild(t);
            }

            else{
                doubleWithLeftChild(t);
            }
        }
    }

    else if(t->element < x){
        insert(x, t->right);

        if( height(t->right) - height(t->left) == 2){
            if(t->right->element < x){
                rotateWithRightChild(t);
            }

            else{
                doubleWithRightChild(t);
            }
        }
    }

    else{}

    t->height = max(height(t->left), height(t->right)) + 1;
}

template<typename T>
bool AVLTree<T>::contains(const T& x, AvlNode* t) const{
    if(t == nullptr){
        return false;
    }

    else if(x < t->element){
        return contains(x, t->left);
    }

    else if(t->element < x){
        return contains(x, t->right);
    }

    else{
        return true;    // Match
    }
}

template<typename T>
void AVLTree<T>::makeEmpty(AvlNode*& t){
    if(t != nullptr){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template<typename T>
void AVLTree<T>::printTree(AvlNode* t) const{
    if(t != nullptr){
        printTree(t->left);
        cout << t->element << endl;
        printTree(t->right);
    }
}

template<typename T>
int AVLTree<T>::height(AvlNode* t) const{
        return t == nullptr ? -1 : t->height;
}

template<typename T>
int AVLTree<T>::max(int lhs, int rhs) const{
    return lhs > rhs ? lhs : rhs;
}

/* Rotate binary tree node with left child.
   For AVL trees, this is a single rotation for case 1.
   Update heights, then set new root.                */
template<typename T>
void AVLTree<T>::rotateWithLeftChild(AvlNode*& k2){
    AvlNode *k1 = k2->left;

    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;

    k2 = k1;
}

/* Rotate binary tree node with right child.
   For AVL trees, this is a single rotation for case 1.
   Update heights, then set new root.                */
template<typename T>
void AVLTree<T>::rotateWithRightChild(AvlNode*& k1){
    AvlNode *k2 = k1->right;

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
template<typename T>
void AVLTree<T>::doubleWithLeftChild(AvlNode*& k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

/* Double rotate binary tree node: first right child.
   with its left child; then node k1 with new right child.
   For AVL trees, this is a double rotation for case 3.
   Update heights, then set new root.                  */
template<typename T>
void AVLTree<T>::doubleWithRightChild(AvlNode*& k1){
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

#endif
