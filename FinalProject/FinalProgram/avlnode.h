#ifndef AVLNODE_H
#define AVLNODE_H

template <class T>
class AvlNode{
    private:
        template<class X> friend class AVLTree;

        T element;
        AvlNode<T>*  left;
        AvlNode<T>*  right;
        int height;

        AvlNode(const T&, AvlNode*, AvlNode*, int h = 0);

        AvlNode* findMin(AvlNode<T>* ) const;
        AvlNode* findMax(AvlNode<T>* ) const;
        AvlNode* copyNode(AvlNode<T>* ) const;
};

template<class T>
AvlNode<T>::AvlNode(const T& theElement, AvlNode* lt, AvlNode* rt, int h)
    : element(theElement), left(lt), right(rt), height(h) {      }

template <class T>
AvlNode<T>* AvlNode<T>::findMin(AvlNode<T> *t) const{
    if(t == nullptr)
        return nullptr;

    if(t->left == nullptr)
        return t;

    return findMin(t->left);
}

template <class T>
AvlNode<T>* AvlNode<T>::findMax(AvlNode<T>* t) const{
    if(t != nullptr)
        while(t->right != nullptr)
            t = t->right;

    return t;
}

template <class T>
AvlNode<T> * AvlNode<T>::copyNode(AvlNode<T> *t) const{
    if(t == nullptr)
        return nullptr;
    else
        return new AvlNode<T>(t->element, clone(t->left), clone(t->right), t->height);
}

#endif // AVLNODE_H
