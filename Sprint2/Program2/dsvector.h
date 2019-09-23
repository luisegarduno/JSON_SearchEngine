#ifndef DSVECTOR_H
#define DSVECTOR_H

template <typename T>
class DSVector{
    private:
        T * data;
        int capacity;
        int size;
        bool aResize;
        void reSize();

    public:
        DSVector();
};

#endif // DSVECTOR_H
