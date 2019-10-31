#ifndef DSVECTOR_H
#define DSVECTOR_H
#include <iostream>

template <typename T>
class DSVector{
    private:
        T * data;                       // vector element data
        int sizeOfDSVector;             // vector size
        int capacity;                   // vector capacity
        bool aResize;                   // boolean flag to check if reSize is needed
        void reSize();                  // resizing vector
        bool isSorted;

    public:
        DSVector();                     // default constructor
        DSVector(int);
        DSVector(const DSVector&);             // copy constructor

        int getSize();                  // returns size of vector
        int getCapacity();              // returns vector capacity

        void clearVector();             // used to remove all the elements of the vector container
        void printVector();
        void swap(DSVector&);           // used to swap the contents between 2 vectors
        void pushBack(const T&);        // push elements into a vector from the back
        void reserve(size_t);
        void assign(size_t,const DSVector&);   // assigns new value to the vector elements by replacing old ones

        T& operator[](const int);
        T& operator=(T&);               // copy assignment operator
        DSVector& popBack();            // pop/remove/delete's last element from vector
        DSVector& operator+=(DSVector&);
        DSVector operator+(const DSVector&) const;



        bool isEmpty() const;
        bool operator==(const DSVector&) const;
        bool operator!=(const DSVector&) const;

        T& elementIndex(int);

        ~DSVector();
};

template <typename T>
DSVector<T>::DSVector(){                                // Default constructor
    capacity = 5;                                       // initial capacity size
    sizeOfDSVector = 0;
    this->data = new T[capacity];                             // allocate memory for data
    aResize = false;
}

template <typename T>
DSVector<T>::DSVector(int numOfElements){
    capacity = 5;
    sizeOfDSVector = numOfElements;
    if(sizeOfDSVector > capacity){
        capacity = sizeOfDSVector;
    }
    this->data = new T[capacity];
}

template<typename T>
DSVector<T>::DSVector(const DSVector<T>& originalDSVector){
    capacity = originalDSVector.capacity;               // copy originalDSVector capacity
    sizeOfDSVector = originalDSVector.sizeOfDSVector;   // copy originalDSVector size
    this->data = new T[capacity];                       // dynamically allocate data

    for(int i = 0; i < capacity; i++){
        this->data[i] = originalDSVector.data[i];       // copy originalDSVector data
    }
}

template <typename T>
void DSVector<T>::reSize(){
    int aCapacity = this->capacity * 2;

    T* temp = this->data;
    this->data = new T[aCapacity];

    for(int i = 0; i < sizeOfDSVector; i++){
        this->data[i] = temp[i];
    }

    delete [] temp;
    this->capacity = aCapacity;
    /*capacity *= 2;                                      // doubles the capacity
    T * temp = new T[capacity];                         // create temp data array to copy elements

    for(int i = 0;i < sizeOfDSVector;i++) {
        temp[i] = this->data[i];                        // deep copy data to temp
    }
    delete [] this->data;                               // delete the memory allocated
    this->data = temp;
    */
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

    this->data[sizeOfDSVector] = anElement;             // add new element as the last vector element
    sizeOfDSVector += 1;                                // once added, the size of the vector increases by 1
}

template <typename T>
DSVector<T>& DSVector<T>::popBack(){                    //pop/remove elements from a vector from the back
    T * temps = this->data;                             // create pointer to = this->data
    sizeOfDSVector -= 1;                                // Since we are removing an element from the Vector, decrease size counter
    this->data = new T[capacity];

    for(int i = 0; i < sizeOfDSVector; i++){
        this->data[i] = temps[i];
    }

    delete [] temps;                                    // delete temp pointer
    return *this;
}

template <typename T>
void DSVector<T>::swap(DSVector<T>& bDSVector){         // used to swap the contents between 2 vectors

    int tempCapacity = capacity;                        // store capacity on stack
    capacity = bDSVector.getCapacity();                 // replace v1.capacity with v2.capacity
    bDSVector.capacity = tempCapacity;

    int tempSize = sizeOfDSVector;
    sizeOfDSVector = bDSVector.getSize();               // replace v2.size with temp.size
    bDSVector.sizeOfDSVector = tempSize;

    T * tempData = this->data;                          // use tempData to point to data
    this->data = bDSVector.data;                        // this->data now points to bDSVector.data
    bDSVector.data = tempData;                          // bDSVector now points to tempData
}

template <typename T>
void DSVector<T>::reserve(size_t space){
    if(sizeOfDSVector < int(space)){
        capacity = int(space);
    }
}

template <typename T>
void DSVector<T>::clearVector(){                        // used to remove all the elements of the vector container

    delete [] this->data;                               // completely delete all data

    capacity = 5;                                       // re-declare the values of private variables
    sizeOfDSVector = 0;
    this->data = new T[capacity];
}

template <typename T>
void DSVector<T>::assign(size_t newX,const DSVector<T>& assignElement){    // assigns new value to the vector elements by replacing old ones
    delete [] this->data;                                      // delete data from HEAP

    if(newX >= size_t(capacity)){
        capacity = newX;
        sizeOfDSVector = newX;
    }
    if(newX < size_t(sizeOfDSVector)){
        sizeOfDSVector = newX;
    }
                            // assign capacity, size, data

    //sizeOfDSVector = newX;
    this->data = new T[capacity];

    for(int i = 0; i < sizeOfDSVector; i++){
        this->data[i] = assignElement.data[i];
    }
}

template <typename T>
T& DSVector<T>::operator=(T& v2){
    if(this != nullptr){
        delete [] data;
        this->capacity = v2.getCapacity();                 // declare capacity = parameters capacity
        sizeOfDSVector = v2.getSize();               // declare sizeOfDsVector = parameters size
        this->data = new T[capacity];                // dynamically allocate data

        for(int i = 0;i < sizeOfDSVector; i++) {
            this->data[i] = v2.data[i];      // copy elements to new data array
        }
    }

    return *this;
}

template <typename T>
DSVector<T> DSVector<T>::operator+(const DSVector<T>& aDSVector) const{
    DSVector<T> tempVector;                                // create the vector we will be returning
    tempVector.sizeOfDSVector = getSize() + aDSVector.getSize();
    tempVector.capacity = tempVector.getSize();

    T * tempData = this->data;                          // temporarily copy data
    this->data = new T[tempVector.getCapacity()];       // allocate memory for data on heap

    for(int i = 0; i < this->data.getSize(); i++){
        this->data[i] = tempData->data[i];              // iteratively add v1 data to new data
    }

    for(int j = 0; j < aDSVector.getSize(); j++){
        this->data[j + tempData->getSize()] = aDSVector.data[j];    // continue adding data starting from where
    }                                                               // last element index number

    tempVector.data = this->data;
    this->data = tempData;

    delete [] tempData;
    return tempVector;
}

template <typename T>
DSVector<T>& DSVector<T>::operator+=( DSVector<T>& v2){
    T * temp = this->data;                               // copy data temporarily to the heap


    this->data = new T[sizeOfDSVector + v2.getSize()];   // allocate memory for data on HEAP

    for(int i = 0; i < sizeOfDSVector; i++){
        this->data[i] = temp[i];                         // iteratively add v1 data elements to new data
    }

    for(int j = 0;j < v2.getSize(); j++){
        this->data[j + sizeOfDSVector] = v2.data[j];     // iteratively add v2 data elements to new data
    }

    capacity += v2.getCapacity();                        // capacity = capacity + aDSVector.getCapacity
    sizeOfDSVector += v2.getSize();

    delete [] temp;                                      // deallocate temp memory
    return *this;
}

template <typename T>
bool DSVector<T>::operator==(const DSVector& aDSVector)const{
    if(this->getCapacity() != aDSVector.getCapacity()){
        return false;
    }
    if(this->getSize() != aDSVector.getSize()){                 // if sizes do not match return false
        return false;
    }
    for (int i = 0;i < aDSVector.getSize(); i++) {
        if(this->data[i] != aDSVector.data[i]){
            return false;
        }
    }
    return true;                                                // if everything matches return true
}

template <typename T>
bool DSVector<T>::operator!=(const DSVector<T>& aDSVector) const{
    if(this->getCapacity() != aDSVector.getCapacity()){         // if capacities do not match return true
        return true;
    }
    if(this->getSize() != aDSVector.getSize()){
        return true;
    }
    for (int i = 0;i < aDSVector.getSize(); i++) {
        if(this->data[i] != aDSVector.data[i]){                 // if any data element's don't match
            return true;                                        // return true
        }
    }
    return false;                                               // if everything matches, return false
}

template <typename T>
bool DSVector<T>::isEmpty() const{
    if(sizeOfDSVector == 0){                                    // checks to see if vector is empty
        return true;
    }
    return false;                                               // if the size of the vector is >= 0 return false
}

template <typename T>
T& DSVector<T>::operator[](const int indexLocation){
    if(indexLocation < 0 || indexLocation > capacity - 1){      // if statement to check location exists
        return -1;
    }
    return *(this->data + indexLocation);                       // return element from DSVector
}

template <typename T>
T& DSVector<T>::elementIndex(int elementNumber){
    return this->data[elementNumber];
}

template <typename T>
void DSVector<T>::printVector(){
    for(int i = 0; i < getSize(); i++){                         // returns every element in Vector
        if(i < (getSize() - 1)){
            std::cout << this->data[i] << " | ";
        }
        else{
            std::cout << this->data[i] << std::endl;            // once the end is reached, newline
        }
    }
}

template <typename T>
DSVector<T>::~DSVector(){
    if(this->data != nullptr){
        delete [] this->data;                                       // deallocate memory from heap
    }
}

#endif
