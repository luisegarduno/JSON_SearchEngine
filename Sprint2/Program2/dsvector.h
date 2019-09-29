#include <iostream>
//#include "dsstring.h"

template <typename T>
class DSVector{
    private:
        T * data;                       // vector element data
        int sizeOfDSVector;             // vector size
        int capacity;                   // vector capacity
        bool aResize;                   // boolean flag to check if reSize is needed
        void reSize();                  // resizing vector

    public:
        DSVector();                     // default constructor
        DSVector(int);
        DSVector(const DSVector&);      // copy constructor

        int getSize();                  // returns size of vector
        int getCapacity();              // returns vector capacity

        void assign();                  // assigns new value to the vector elements by replacing old ones
        void clearVector();             // used to remove all the elements of the vector container
        void printVector();
        void pushBack(const T&);        // push elements into a vector from the back

        DSVector& popBack();            // pop/remove/delete's last element from vector
        void swap(DSVector&);           // used to swap the contents between 2 vectors

        DSVector& operator=(const DSVector&);  // copy assignment operator
        DSVector operator+(const DSVector&);
        DSVector& operator+=(const DSVector&);
        T& operator[](const int);

        bool operator==(const DSVector&) const;
        bool operator!=(const DSVector&) const;

        T* elementIndex(int);

        ~DSVector();
};

template <typename T>
DSVector<T>::DSVector(){                // Default constructor
    capacity = 5;                       // initial capacity size
    sizeOfDSVector = 0;
    data = new T[capacity];             // allocate memory for data
}

template <typename T>
DSVector<T>::DSVector(int numOfElements){
    sizeOfDSVector = numOfElements;
    data = new T[capacity];
}

template<typename T>
DSVector<T>::DSVector(const DSVector& originalDSVector){
    this->data = new T[capacity];                       // dynamically allocate data
    capacity = originalDSVector.capacity;               // copy originalDSVector capacity
    sizeOfDSVector = originalDSVector.size;             // copy originalDSVector size

    for(int i = 0; i < capacity; i++){
        this->data[i] = originalDSVector.data[i];       // copy originalDSVector data
    }
}

template <typename T>
void DSVector<T>::reSize(){

    capacity *= 2;                                  // doubles the capacity
    T * temp = new T[capacity];                     // create temp data array to copy elements

    for(int i = 0;i < sizeOfDSVector;i++) {
        temp[i] = this->data[i];
    }
    delete [] this->data;                           // delete the memory allocated
    this->data = temp;
}

template <typename T>
int DSVector<T>::getSize(){
    return sizeOfDSVector;                              // returns vector size
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
    sizeOfDSVector += 1;
}

template <typename T>
DSVector<T>& DSVector<T>::popBack(){                     // pop/remove elements from a vector from the back
    T * temps = this->data;
    sizeOfDSVector -= 1;
    this->data = new T[capacity];

    for(int i = 0; i < sizeOfDSVector; i++){
        this->data[i] = temps[i];
    }

    delete [] temps;

    return *this;
}

template <typename T>
void DSVector<T>::swap(DSVector<T>& bDSVector){       // used to swap the contents between 2 vectors
    T * tempData = this->data;
    int tempCapactity = capacity;
    int tempSize = sizeOfDSVector;

    this->data = new T[bDSVector.getSize()];
    capacity = bDSVector.getCapacity();
    sizeOfDSVector = bDSVector.getSize();

    for(int i = 0;i < capacity; i++) {
        this->data[i] = bDSVector.data[i];
    }

    bDSVector.data = new T[sizeOfDSVector];
    bDSVector.capacity = tempCapactity;
    bDSVector.sizeOfDSVector = tempSize;

    for(int j = 0; j < bDSVector.capacity; j++){
        bDSVector.data[j] = tempData[j];
    }

    delete [] tempData;

}

template <typename T>
void DSVector<T>::clearVector(){                        // used to remove all the elements of the vector container

    delete [] this->data;

    capacity = 2;
    sizeOfDSVector = 0;
    this->data = new T[capacity];
}

template <typename T>
void DSVector<T>::assign(){                             // assigns new value to the vector elements by replacing old ones

}

template <typename T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T>& aDSVector){

    capacity = aDSVector.getCapacity();                 // declare capacity = parameters capacity
    sizeOfDSVector = aDSVector.getSize();               // declare sizeOfDsVector = parameters size
    this->data = new T[capacity];                       // dynamically allocate data

    for(int i = 0;i < capacity; i++) {
        this->data[i] = aDSVector.elementIndex(i);      // copy elements to new data array
    }

    return *this;
}

template <typename T>
DSVector<T> DSVector<T>::operator+(const DSVector<T>& aDSVector){
    DSVector tempVector;                                // create the vector we will be returning
    tempVector.sizeOfDSVector = this->data.getSize() + aDSVector.getSize();
    tempVector.capacity = tempVector.getSize() + 1;

    T * tempData = this->data;                          // temporarily copy data
    this->data = new T[tempVector.getCapacity()];       // declare

    for(int i = 0; i < this->data.getSize(); i++){
        this->data[i] = tempData->data[i];
    }

    for(int j = 0; j < aDSVector.getSize(); j++){
        this->data[j + tempData->getSize()] = aDSVector.data[j];
    }

    tempVector.data = this->data;
    this->data = tempData;

    delete [] tempData;
    return tempVector;
}

template <typename T>
DSVector<T>& DSVector<T>::operator+=(const DSVector<T>& aDSVector){
    T * temp = this->data;

    capacity += aDSVector.getCapacity();
    sizeOfDSVector += aDSVector.getSize();
    this->data = new T[this->data.getSize() + aDSVector.getSize()];

    for(int i = 0; i < temp->getCapacity(); i++){
        this->data[i] = temp->elementIndex(i);
    }

    for(int j = (temp->getCapacity());j < aDSVector.getSize(); j ++){
        this->data[j] = aDSVector.elementIndex(j);
    }

    delete [] this->temp;

    return *this;
}

template <typename T>
bool DSVector<T>::operator==(const DSVector& aDSVector)const{
    if(this->getCapacity() != aDSVector.getCapacity()){
        return false;
    }
    if(this->getSize() != aDSVector.getSize()){
        return false;
    }
    for (int i = 0;i < aDSVector.getSize(); i++) {
        if(this->data[i] != aDSVector.data[i]){
            return false;
        }
    }
    return true;
}

template <typename T>
bool DSVector<T>::operator!=(const DSVector<T>& aDSVector) const{
    if(this->data != aDSVector.data){
        return true;
    }
    else {
        return false;
    }

}

template <typename T>
T& DSVector<T>::operator[](const int indexLocation){
    if(indexLocation < 0 || indexLocation > capacity - 1){      // if statement to check location exists
        return -1;
    }
    return *(this->data + indexLocation);           // return element from DSVector
}

template <typename T>
T* DSVector<T>::elementIndex(int elementNumber){
    return this->data[elementNumber];
}

template <typename T>
void DSVector<T>::printVector(){
    for(int i = 0; i < getSize(); i++){
        if(i < (getSize() - 1)){
            std::cout << this->data[i] << ",";
        }
        else{
            std::cout << this->data[i] << std::endl;
        }
    }
}

template <typename T>
DSVector<T>::~DSVector(){
    delete [] this->data;                           // deallocate memory from heap
}
