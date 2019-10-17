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
        // http://www.algolist.net/Algorithms/Sorting/Insertion_sort

            std::cout << "Mystery Sorter A" << std::endl;

            int i, j, tmp, vectorSize = this->data.size();
            for(i = 1;i < vectorSize; i++){
                j = i;
                while((j > 0) && (this->data[j - 1] > this->data[j])){
                    tmp = this->data[j];
                    this->data[j] = this->data[j - 1];
                    this->data[j - 1] = tmp;
                    j--;
                }
            }
            /*
            for(int i = 0; i < vectorSize; i++){
                std::cout << this->data[i] << std::endl;
            }
            */


        }
};

template <typename T>
class MysterySorterB : public Sorter<T> {
    public:
        virtual void sort() {   // Selection Sort
        // http://www.algolist.net/Algorithms/Sorting/Selection_sort

            std::cout << "Mystery Sorter B" << std::endl;

            int i,j, minIndex, tmp, vectorSize = this->data.size();

            for (i = 0; i < vectorSize - 1; i++) {
                minIndex = i;
                for (j = i + 1; j < vectorSize; j++){
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
            /*
            for(int i = 0; i < vectorSize; i++){
                std::cout << this->data[i] << std::endl;
            }
            */
        }
};

template <typename T>
class MysterySorterC : public Sorter<T> {
    public:
        virtual void sort() {   // Bubble Sort (it is optimized)
        // http://www.algolist.net/Algorithms/Sorting/Bubble_sort
            std::cout << "Mystery Sorter C" << std::endl;
            bool swapped = true;
            int j = 0, vectorSize = this->data.size(),tmp;
            while (swapped) {
                swapped = false;
                j++;
                for (int i = 0; i < vectorSize - j; i++) {
                    if (this->data[i] > this->data[i + 1]) {
                        tmp = this->data[i];
                        this->data[i] = this->data[i + 1];
                        this->data[i + 1] = tmp;
                        swapped = true;
                    }
                }
            }
            /*
            for(int i = 0; i < vectorSize; i++){
                std::cout << this->data[i] << std::endl;
            }
            */
        }
};

template <typename T>
class MysterySorterD : public Sorter<T> {
    private:
        int vectorSize;
        int low;
        int high;
        void swap(int * a, int * b){
            int t = *a;
            *a = *b;
            *b = t;
        }

        int partition(int left, int right){
            int pivot = this->data[right];
            int i = (left - 1);
            for(int j = left; j < right; j++){
                if(this->data[j] <= pivot){
                    i++;
                    swap(&this->data[i], &this->data[j]);
                }
            }
            swap(&this->data[i + 1], &this->data[right]);
            return(i + 1);
        }

        void quickSort(int low, int high){
            if(low < high){
                int pi = partition(low,high);
                quickSort(low, pi - 1);
                quickSort(pi + 1, high);
            }
        }

    public:
        virtual void sort() {   // Quick Sort
            // http://www.algolist.net/Algorithms/Sorting/Quicksort

            std::cout << "Mystery Sorter D" << std::endl;

            vectorSize = this->data.size();

            quickSort(0,vectorSize - 1);

            /*
            for(int i = 0; i < vectorSize; i++){
                std::cout << this->data[i] << std::endl;
            }
            */

        }
};

template <typename T>
class MysterySorterE : public Sorter<T> {
    public:
        virtual void sort() {   // Merge Sort
            std::cout << "Mystery Sorter E" << std::endl;


        }
};

#endif //SORTINGFUN_SORTER_H

