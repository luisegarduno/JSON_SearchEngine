//#ifndef DSVECTOR_H
//#define DSVECTOR_H

template <typename T>
class DSVector{
    private:
        T * data;
        int size;                       // vector size
        int capacity;                   // vector capacity
        bool aResize;
        void reSize();                  // resizing vector

    public:
        DSVector();                     // default constructor

        int getSize();                  // returns size of vector
        int getCapacity();              // returns vector capacity

        void pushBack(T);               // push elements into a vector from the back
        DSVector popBack();                    // pop/remove elements from a vector from the back
        DSVector swap(int,int);                // used to swap the contents between 2 vectors
        void clear();                   // used to remove all the elements of the vector container
        void assign();                  // assigns new value to the vector elements by replacing old ones

        T& operator=(const DSVector&);
        T& operator+(const DSVector&);
        T& operator+=(const DSVector&);

        bool operator==(const DSVector<T>&) const;
        bool operator!=(const DSVector<T>&) const;

        T & operator[](const int);
        T * arr();


        void print();

        ~DSVector();
};

template <typename T>
DSVector<T>::DSVector(){

}

template <typename T>
int DSVector<T>::getSize(){

}

template <typename T>
int DSVector<T>::getCapacity(){              // returns vector capacity

}

template <typename T>
void DSVector<T>::pushBack(T){               // push elements into a vector from the back

}

template <typename T>
DSVector<T> DSVector<T>::popBack(){                    // pop/remove elements from a vector from the back

}

template <typename T>
DSVector<T> DSVector<T>::swap(int,int){                // used to swap the contents between 2 vectors

}

template <typename T>
void DSVector<T>::clear(){                   // used to remove all the elements of the vector container

}

template <typename T>
void DSVector<T>::assign(){                  // assigns new value to the vector elements by replacing old ones

}

template <typename T>
T& DSVector<T>::operator=(const DSVector& aDSVector){

}

template <typename T>
T& DSVector<T>::operator+(const DSVector& aDSVector){

}

template <typename T>
T& DSVector<T>::operator+=(const DSVector<T>& aDSVector){

}

template <typename T>
bool DSVector<T>::operator==(const DSVector<T>& aDSVector) const{

}

template <typename T>
bool DSVector<T>::operator!=(const DSVector<T>& aDSVector) const{

}

template <typename T>
T& DSVector<T>::operator[](const int aNum){

}

template <typename T>
T* DSVector<T>::arr(){

}

template <typename T>
void DSVector<T>::print(){

}

//#endif // DSVECTOR_H
