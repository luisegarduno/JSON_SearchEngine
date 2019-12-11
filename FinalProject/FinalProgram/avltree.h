#ifndef AVLTREE_H
#define AVLTREE_H

#include "avltree_node.h"
#include <stdexcept>

static int totalNumberOfNodes;

template <class T>
class AvlTree{
    private:
        AvlTree_Node<T>* root;

        void insert(const T& x, AvlTree_Node<T>*& t);

        bool contains(const T& x, AvlTree_Node<T>* t) const;

        // Removes all nodes in AVL Tree
        void makeEmpty(AvlTree_Node<T>*& t);
        void printTree(AvlTree_Node<T>* t) const;

        int max(int lhs, int rhs) const;
        int height(AvlTree_Node<T>* t) const;

        // Finds total number of nodes in Avl Tree by using recursion
        void setNumberOfNodes(AvlTree_Node<T>*) const;

        // Returns total number of Nodes in Avl Tree
        int getNumberOfNodes();

        // Descriptions provided below
        void rotateWithLeftChild(AvlTree_Node<T>*& k2);
        void rotateWithRightChild(AvlTree_Node<T>*& k1);
        void doubleWithLeftChild(AvlTree_Node<T>*& k3);
        void doubleWithRightChild(AvlTree_Node<T>*& k1);

    public:
        // Default constructor
        AvlTree();

        // Copy constructor
        AvlTree(const AvlTree& rhs);

        // Assignment operator
        const AvlTree& operator=(const AvlTree& rhs);

        // Destructor
        ~AvlTree();

        // Calls private AVLNode function: findMin(AvlTree_Node<T>*) const
        const T& findMin() const;

        // Calls private AVLNode function: findMax(AvlTree_Node<T>*) const
        const T& findMax() const;

        // Calls private function: insert(const T&, AvlTree_Node<T>*&)
        void insert(const T& x);

        // Calls private function: contains(const T& x, AvlTree_Node<T>* t) const
        bool contains(const T& x) const;

        // Returns boolean value depending on AVL Tree's size
        bool isEmpty() const;

        // Calls private function: makeEmpty(AvlTree_Node<T>*&)
        void makeEmpty();

        T& searchAvl(const T&);

        // Calls private function: printTree(AvlTree_Node<T>*) const
        void printTree() const;
};

template<typename T>
AvlTree<T>::AvlTree() : root(nullptr){
}

template<typename T>
AvlTree<T>::AvlTree(const AvlTree& rhs) : root(nullptr){
    *this = rhs;
}

template<typename T>
const AvlTree<T>& AvlTree<T>::operator=(const AvlTree& rhs){
    if(this != &rhs){
        makeEmpty();
        root = clone(rhs.root);
    }

    return *this;
}

template<typename T>
AvlTree<T>::~AvlTree(){
    makeEmpty();
}


/*
Find the smallest item in the tree.
Throw UnderflowException if empty. */
template<typename T>
const T& AvlTree<T>::findMin() const{
    if(isEmpty()){
        throw underflow_error("Exception Throw: Underflow -> findMin()");
    }

    return findMin(root)->element;
}

/*
Find the largest item in the tree.
Throw UnderflowException if empty. */
template<typename T>
const T& AvlTree<T>::findMax() const{
    if(isEmpty()){
        throw underflow_error("Exception Throw: Underflow -> findMax()");
    }

    return findMax(root)->element;
}

// PUBLIC insert    --> Insert x into the tree; duplicates are ignored
template<typename T>
void AvlTree<T>::insert(const T& x){
    insert(x, root);
}

// PRIVATE insert
template<typename T>
void AvlTree<T>::insert(const T& x, AvlTree_Node<T>*& t){
    if(t == nullptr){
        t = new AvlTree_Node<T>(x, nullptr, nullptr);
    }

    else if(x.the_Word < t->element.the_Word){
        insert(x, t->left);
        if(height(t->left) - height(t->right) == 2){
            if(x.the_Word < t->left->element.the_Word){
                rotateWithLeftChild(t);
            }

            else{
                doubleWithLeftChild(t);
            }
        }
    }

    else if(t->element.the_Word < x.the_Word){
        insert(x, t->right);

        if( height(t->right) - height(t->left) == 2){
            if(t->right->element.the_Word < x.the_Word){
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
bool AvlTree<T>::contains(const T& x) const{
    return contains(x, root);
}

// PRIVATE contains
template<typename T>
bool AvlTree<T>::contains(const T& x, AvlTree_Node<T>* t) const{
    if(t == nullptr){
        return false;
    }

    else if(x.the_Word < t->element.the_Word){
        return contains(x, t->left);
    }

    else if(t->element.the_Word < x.the_Word){
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
bool AvlTree<T>::isEmpty() const{
    return ((root == nullptr) ? true : false);
}

// PUBLIC makeEmpty --> makes tree logically empty
template<typename T>
void AvlTree<T>::makeEmpty(){
    makeEmpty(root);
}

// PRIVATE makeEmpty
template<typename T>
void AvlTree<T>::makeEmpty(AvlTree_Node<T>*& t){
    if(t != nullptr){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

// PUBLIC printTree
template<typename T>
void AvlTree<T>::printTree() const{
    if(isEmpty()){
        cout << "Empty tree" << endl;
    }

    else{
        printTree(root);
    }
}

// PRIVATE printTree
template<typename T>
void AvlTree<T>::printTree(AvlTree_Node<T>* t) const{
    if(t != nullptr){
        printTree(t->left);
        cout << t->element.the_Word << " --> File: " << t->element.the_File << " --> Frequency: " << t->element.the_Frequency << endl;
        printTree(t->right);
    }
}

template<typename T>
T& AvlTree<T>::searchAvl(const T& x){
    AvlTree_Node<T>* tempTree = root;
    while(tempTree != nullptr){
        if(tempTree->element.the_Word == x.the_Word){
            return tempTree->element;
        }
        if(tempTree->element.the_Word < x.the_Word){
            tempTree = tempTree->right;
        }
        else{
            tempTree = tempTree->left;
        }
    }
}

template<typename T>
void AvlTree<T>::setNumberOfNodes(AvlTree_Node<T>* t) const{
    if(t != nullptr){
        setNumberOfNodes(t->left);
        ++totalNumberOfNodes;
        setNumberOfNodes(t->right);
    }
}

template<typename T>
int AvlTree<T>::getNumberOfNodes(){
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
int AvlTree<T>::height(AvlTree_Node<T>* t) const{
        return t == nullptr ? -1 : t->height;
}

template<typename T>
int AvlTree<T>::max(int lhs, int rhs) const{
    return lhs > rhs ? lhs : rhs;
}

/*
Rotate binary tree node with left child.
For AVL trees, this is a single rotation for case 1.
Update heights, then set new root.                */
template<typename T>
void AvlTree<T>::rotateWithLeftChild(AvlTree_Node<T>*& k2){
    AvlTree_Node<T> *k1 = k2->left;

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
void AvlTree<T>::rotateWithRightChild(AvlTree_Node<T>*& k1){
    AvlTree_Node<T> *k2 = k1->right;

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
void AvlTree<T>::doubleWithLeftChild(AvlTree_Node<T>*& k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

/*
Double rotate binary tree node: first right child.
with its left child; then node k1 with new right child.
For AVL trees, this is a double rotation for case 3.
Update heights, then set new root.                  */
template<typename T>
void AvlTree<T>::doubleWithRightChild(AvlTree_Node<T>*& k1){
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

#endif


