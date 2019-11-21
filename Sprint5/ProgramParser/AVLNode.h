#ifndef AVLNODE_H
#define AVLNODE_H

template<class T>
class AVLNode{
    private:

    public:
        int element;

        AVLNode<T>* left;
        AVLNode<T>* right;

        int height;

        AVLNode(const int&, AVLNode<T>*, AVLNode<T>*, int h = 0 );
};

template<class T>
AVLNode<T>::AVLNode(const int& theElement, AVLNode<T>* lt, AVLNode<T>* rt, int h)
    :   element(theElement), left(lt), right(rt), height(h)     {    }

#endif // AVLNODE_H
