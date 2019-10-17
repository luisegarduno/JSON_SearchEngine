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
        virtual void sort() {   // Insertion sort
            std::cout << "Mystery Sorter A" << std::endl;
            unsigned i, j, tmp;
            for(i = 1;i < this->data.size(); i++){
                j = 1;
                while(j > 0 && this->data[j - 1] > this->data[j]){
                    tmp = this->data[j];
                    this->data[j] = this->data[j - 1];
                    this->data[j - 1] = tmp;
                    j--;
                }
            }
        }
};

template <typename T>
class MysterySorterB : public Sorter<T> {
    public:
        virtual void sort() {   // Selection Sort
            std::cout << "Mystery Sorter B" << std::endl;
            unsigned int i,j, minIndex, tmp;
            for (i = 0; i < this->data.size() - 1; i++) {
                minIndex = i;
                for (j = i + 1; j < this->data.size(); j++){
                    if (this->data[j] < this->data[minIndex]){
                        minIndex = j;
                    }
                }
                if (minIndex != i) {
                    tmp = this->data[i];
                    this->data[i] = this->data[minIndex];
                    this->data[minIndex] = tmp;
                }
            }
        }
};

template <typename T>
class MysterySorterC : public Sorter<T> {
    public:
        virtual void sort() {   // Bubble Sort
            std::cout << "Mystery Sorter C" << std::endl;
            bool swapped = true;
            int j = 0,tmp;
            while (swapped) {
                swapped = false;
                j++;
                for (unsigned int i = 0; i < this->data.size() - j; i++) {
                    if (this->data[i] > this->data[i + 1]) {
                        tmp = this->data[i];
                        this->data[i] = this->data[i + 1];
                        this->data[i + 1] = tmp;
                        swapped = true;
                    }
                }
            }
        }
};

template <typename T>
class MysterySorterD : public Sorter<T> {
    private:

    public:
        virtual void sort() {   // Quick Sort
            std::cout << "Mystery Sorter D" << std::endl;

            bool swapped = true;
            int j = 0,tmp;
            while (swapped) {
                swapped = false;
                j++;
                for (unsigned int i = 0; i < this->data.size() - j; i++) {
                    if (this->data[i] > this->data[i + 1]) {
                        tmp = this->data[i];
                        this->data[i] = this->data[i + 1];
                        this->data[i + 1] = tmp;
                        swapped = true;
                    }
                }
            }


        }
};

template <typename T>
class MysterySorterE : public Sorter<T> {
    public:
        virtual void sort() {   // Merge Sort
            std::cout << "Mystery Sorter E" << std::endl;

            unsigned i, j, tmp;
            for(i = 1;i < this->data.size(); i++){
                j = 1;
                while(j > 0 && this->data[j - 1] > this->data[j]){
                    tmp = this->data[j];
                    this->data[j] = this->data[j - 1];
                    this->data[j - 1] = tmp;
                    j--;
                }
            }
        }
};

#endif //SORTINGFUN_SORTER_H

