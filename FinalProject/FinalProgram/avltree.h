#ifndef AVLTREE_H
#define AVLTREE_H

#include "avlnode.h"

static int totalNumberOfNodes;

template <class T>
class AVLTree{
    private:
        AvlNode<T>* root;

        void insert(const T& x, AvlNode<T>*& t);

        bool contains(const T& x, AvlNode<T>* t) const;

        // Removes all nodes in AVL Tree
        void makeEmpty(AvlNode<T>*& t);
        void printTree(AvlNode<T>* t) const;

        int max(int lhs, int rhs) const;
        int height(AvlNode<T>* t) const;

        // Finds total number of nodes in Avl Tree by using recursion
        void setNumberOfNodes(AvlNode<T>*) const;

        // Returns total number of Nodes in Avl Tree
        int getNumberOfNodes();

        // Descriptions provided below
        void rotateWithLeftChild(AvlNode<T>*& k2);
        void rotateWithRightChild(AvlNode<T>*& k1);
        void doubleWithLeftChild(AvlNode<T>*& k3);
        void doubleWithRightChild(AvlNode<T>*& k1);

    public:
        // Default constructor
        AVLTree();

        // Copy constructor
        AVLTree(const AVLTree& rhs);

        // Assignment operator
        const AVLTree& operator=(const AVLTree& rhs);

        // Destructor
        ~AVLTree();

        // Calls private AVLNode function: findMin(AvlNode<T>*) const
        const T& findMin() const;

        // Calls private AVLNode function: findMax(AvlNode<T>*) const
        const T& findMax() const;

        // Calls private function: insert(const T&, AvlNode<T>*&)
        void insert(const T& x);

        // Calls private function: contains(const T& x, AvlNode<T>* t) const
        bool contains(const T& x) const;

        // Returns boolean value depending on AVL Tree's size
        bool isEmpty() const;

        // Calls private function: makeEmpty(AvlNode<T>*&)
        void makeEmpty();

        // Calls private function: printTree(AvlNode<T>*) const
        void printTree() const;
};

template<typename T>
AVLTree<T>::AVLTree() : root(nullptr){
}

template<typename T>
AVLTree<T>::AVLTree(const AVLTree& rhs) : root(nullptr){
    *this = rhs;
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
AVLTree<T>::~AVLTree(){
    makeEmpty();
}


/*
Find the smallest item in the tree.
Throw UnderflowException if empty. */
template<typename T>
const T& AVLTree<T>::findMin() const{
    if(isEmpty()){
        throw underflow_error("Exception Throw: Underflow -> findMin()");
    }

    return findMin(root)->element;
}

/*
Find the largest item in the tree.
Throw UnderflowException if empty. */
template<typename T>
const T& AVLTree<T>::findMax() const{
    if(isEmpty()){
        throw underflow_error("Exception Throw: Underflow -> findMax()");
    }

    return findMax(root)->element;
}

// PUBLIC insert    --> Insert x into the tree; duplicates are ignored
template<typename T>
void AVLTree<T>::insert(const T& x){
    insert(x, root);
}

// PRIVATE insert
template<typename T>
void AVLTree<T>::insert(const T& x, AvlNode<T>*& t){
    if(t == nullptr){
        t = new AvlNode<T>(x, nullptr, nullptr);
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

// PUBLIC contains  --> Returns true if x is found in the tree
template<typename T>
bool AVLTree<T>::contains(const T& x) const{
    return contains(x, root);
}

// PRIVATE contains
template<typename T>
bool AVLTree<T>::contains(const T& x, AvlNode<T>* t) const{
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

/*
Test if the tree is logically empty.
Return true if empty, false otherwise */
template<typename T>
bool AVLTree<T>::isEmpty() const{
    return ((root == nullptr) ? true : false);
}

// PUBLIC makeEmpty --> makes tree logically empty
template<typename T>
void AVLTree<T>::makeEmpty(){
    makeEmpty(root);
}

// PRIVATE makeEmpty
template<typename T>
void AVLTree<T>::makeEmpty(AvlNode<T>*& t){
    if(t != nullptr){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

// PUBLIC printTree
template<typename T>
void AVLTree<T>::printTree() const{
    if(isEmpty()){
        cout << "Empty tree" << endl;
    }

    else{
        printTree(root);
    }
}

// PRIVATE printTree
template<typename T>
void AVLTree<T>::printTree(AvlNode<T>* t) const{
    if(t != nullptr){
        printTree(t->left);
        cout << t->element << endl;
        printTree(t->right);
    }
}

template<typename T>
void AVLTree<T>::setNumberOfNodes(AvlNode<T>* t) const{
    if(t != nullptr){
        setNumberOfNodes(t->left);
        ++totalNumberOfNodes;
        setNumberOfNodes(t->right);
    }
}

template<typename T>
int AVLTree<T>::getNumberOfNodes(){
    if(isEmpty()){
        cout << "Empty tree" << endl;
        return 0;
    }

    else{
        setNumberOfNodes(root);
        return totalNumberOfNodes;
    }
}

/*
Returns the height of node t or -1 if nullptr */
template<typename T>
int AVLTree<T>::height(AvlNode<T>* t) const{
        return t == nullptr ? -1 : t->height;
}

template<typename T>
int AVLTree<T>::max(int lhs, int rhs) const{
    return lhs > rhs ? lhs : rhs;
}

/*
Rotate binary tree node with left child.
For AVL trees, this is a single rotation for case 1.
Update heights, then set new root.                */
template<typename T>
void AVLTree<T>::rotateWithLeftChild(AvlNode<T>*& k2){
    AvlNode<T> *k1 = k2->left;

    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;

    k2 = k1;
}

/*
Rotate binary tree node with right child.
For AVL trees, this is a single rotation for case 1.
Update heights, then set new root.                */
template<typename T>
void AVLTree<T>::rotateWithRightChild(AvlNode<T>*& k1){
    AvlNode<T> *k2 = k1->right;

    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;

    k1 = k2;
}

/*
Double rotate binary tree node: first right child.
with its right child; then node k3 with new left child.
For AVL trees, this is a double rotation for case 2.
Update heights, then set new root.                  */
template<typename T>
void AVLTree<T>::doubleWithLeftChild(AvlNode<T>*& k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

/*
Double rotate binary tree node: first right child.
with its left child; then node k1 with new right child.
For AVL trees, this is a double rotation for case 3.
Update heights, then set new root.                  */
template<typename T>
void AVLTree<T>::doubleWithRightChild(AvlNode<T>*& k1){
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

#endif

