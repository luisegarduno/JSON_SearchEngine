#include <iostream>
#include <vector>

#ifndef SORTINGFUN_SORTER_H
#define SORTINGFUN_SORTER_H

template <typename T>
class Sorter {
    protected:
        std::vector<T> data;

    public:
        Sorter() {}
        Sorter(T& x):data(x) {}
        void setData(const std::vector<T>& x) {
            data = x;
        }
        virtual void sort() = 0;

};


template <typename T>
class MysterySorterA : public Sorter<T> {
    public:
        virtual void sort() {
            std::cout << "Mystery Sorter A" << std::endl;
        }
};

template <typename T>
class MysterySorterB : public Sorter<T> {
    public:
        virtual void sort() {
            std::cout << "Mystery Sorter B" << std::endl;
        }
};

template <typename T>
class MysterySorterC : public Sorter<T> {
    public:
        virtual void sort() {
            std::cout << "Mystery Sorter C" << std::endl;
        }
};

template <typename T>
class MysterySorterD : public Sorter<T> {
    public:
        virtual void sort() {
            std::cout << "Mystery Sorter D" << std::endl;
        }
};

template <typename T>
class MysterySorterE : public Sorter<T> {
    public:
        virtual void sort() {
            std::cout << "Mystery Sorter E" << std::endl;
        }
};

#endif //SORTINGFUN_SORTER_H

