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
        T popBack();                    // pop/remove elements from a vector from the back
        T swap(int,int);                // used to swap the contents between 2 vectors
        void clear();                   // used to remove all the elements of the vector container
        void assign();                  // assigns new value to the vector elements by replacing old ones

        DSVector& operator=(const DSVector&);
        DSVector& operator+(const DSVector&);
        DSVector& operator+=(const DSVector&);

        bool operator==(const DSVector&);
        bool operator!=(const DSVector&);

        T & operator[](const int);
        T * arr();


        void print();

        ~DSVector();
};

template <typename T>
void DSVector::clear(){
    cout << here << endl;
}

//#endif // DSVECTOR_H
