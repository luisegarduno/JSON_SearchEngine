#include "dsstring.h"

template <typename T>
class DSVector{
    private:
        T * data;
        int sizeOfDSVector;                       // vector size
        int capacity;                   // vector capacity
        bool aResize;
        void reSize();                  // resizing vector

    public:
        DSVector();                     // default constructor
        DSVector(const DSVector&);      // copy constructor

        int getSize();                  // returns size of vector
        int getCapacity();              // returns vector capacity

        void clearVector();             // used to remove all the elements of the vector container
        void printVector();
        void assign();                  // assigns new value to the vector elements by replacing old ones
        void pushBack(const T&);               // push elements into a vector from the back

        DSVector popBack();             // pop/remove/delete's last element from vector
        DSVector swap(int,int);         // used to swap the contents between 2 vectors

        DSVector& operator=(const DSVector&);  // copy assignment
        DSVector& operator+(const DSVector&);
        DSVector& operator+=(const DSVector&);
        T& operator[](const int);

        bool operator==(const DSVector&) const;
        bool operator!=(const DSVector&) const;

        T* elementIndex(int);

        ~DSVector();
};

template <typename T>
DSVector<T>::DSVector(){
    sizeOfDSVector = 0;
    capacity = 5;
    data = new T[capacity];
}

template<typename T>
DSVector<T>::DSVector(const DSVector<T>& originalDSVector){
    capacity = originalDSVector.capacity;             // copy originalDSVector capacity
    sizeOfDSVector = originalDSVector.size;           // copy originalDSVector size
    this->data = new T[capacity];                     // dynamically allocate data

    for(int i = 0; i < capacity; i++){
        this->data[i] = originalDSVector.data[i];       // copy originalDSVector data
    }
}

template <typename T>
void DSVector<T>::reSize(){
    this->capacity *= 2;                                // doubles the capacity

    T * temp = this->data;                              // create temp holder for this->data
    this->data = new T[this->capacity];                 // "resizing" data

    for(int i = 0; i < sizeOfDSVector; i++){
        this->data[i] = temp[i];                        // copy contents to new data array
    }

    delete [] temp;                                     // deallocate memory
    sizeOfDSVector += 1;                                // increase total sizeOfDSVector
}

template <typename T>
int DSVector<T>::getSize(){
    return sizeOfDSVector;
}

template <typename T>
int DSVector<T>::getCapacity(){                         // returns vector capacity
    return capacity;
}

template <typename T>
void DSVector<T>::pushBack(const T& anElement){         // add element to back of vector
    if(sizeOfDSVector == capacity){                     // if capacity is reached, resize
        reSize();
    }

    this->data[sizeOfDSVector] = anElement;

}

template <typename T>
DSVector<T> DSVector<T>::popBack(){                     // pop/remove elements from a vector from the back

}

template <typename T>
DSVector<T> DSVector<T>::swap(int aDSVector,int bDSVector){       // used to swap the contents between 2 vectors

}

template <typename T>
void DSVector<T>::clearVector(){                        // used to remove all the elements of the vector container

}

template <typename T>
void DSVector<T>::assign(){                             // assigns new value to the vector elements by replacing old ones

}

template <typename T>
DSVector<T>& DSVector<T>::operator=(const DSVector& aDSVector){

    capacity = aDSVector.getCapacity();                 // declare capacity = parameters capacity
    sizeOfDSVector = aDSVector.getSize();               // declare sizeOfDsVector = parameters size
    this->data = new T[capacity];                       // dynamically allocate data

    for(int i = 0;i < capacity; i++) {
        this->data[i] = aDSVector.elementIndex(i);      // copy elements to new data array
    }
}

template <typename T>
DSVector<T>& DSVector<T>::operator+(const DSVector& aDSVector){

    this->data = aDSVector;
    return *this;
}

template <typename T>
DSVector<T>& DSVector<T>::operator+=(const DSVector<T>& aDSVector){

    this->data = aDSVector;
}

template <typename T>
bool DSVector<T>::operator==(const DSVector& aDSVector) const{
    if(this->data == aDSVector.data){
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
bool DSVector<T>::operator!=(const DSVector& aDSVector) const{
    if(this->data != aDSVector.data){
        return true;
    }
    else {
        return false;
    }

}

template <typename T>
T& DSVector<T>::operator[](const int indexLocation){
    if(indexLocation < 0 || indexLocation > capacity - 1){
        return -1;
    }
    return *(this->data + indexLocation);
}

template <typename T>
T* DSVector<T>::elementIndex(int elementNumber){

}

template <typename T>
void DSVector<T>::printVector(){

}

template <typename T>
DSVector<T>::~DSVector(){
    delete [] this->data;                           // deallocate memory from heap
}
