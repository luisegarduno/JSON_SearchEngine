#include <vector>
#include <iostream>

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
            std::cout << "Mystery Sorter A" << std::endl;
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
            std::cout << "Mystery Sorter B" << std::endl;
            for(int i = 0; i < vectorSize; i++){
                std::cout << this->data[i] << std::endl;
            }
            */
        }
};

template <typename T>
class MysterySorterC : public Sorter<T> {
    private:
    void swap(int *xp, int *yp){
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

    public:
        virtual void sort() {   // Bubble Sort (optimized)
        // http://www.algolist.net/Algorithms/Sorting/Bubble_sort
        int i, j,vectorSize = this->data.size();
            for (i = 0; i < vectorSize-1; i++)

            // Last i elements are already in place
            for (j = 0; j < vectorSize-i-1; j++)
                if (this->data[j] > this->data[j+1])
                    swap(&this->data[j], &this->data[j+1]);
        /*
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
            */
            /*
            std::cout << "Mystery Sorter C" << std::endl;
            for(int i = 0; i < vectorSize; i++){
                std::cout << this->data[i] << std::endl;
            }
            */
        }
};

template <typename T>
class MysterySorterD : public Sorter<T> {
    private:
        int low,high,vectorSize;

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

            vectorSize = this->data.size();
            quickSort(0,vectorSize - 1);
        }
};

template <typename T>
class MysterySorterE : public Sorter<T> {

    private:
        int vectorSize;
        void merge(int left, int middle, int right){
            int i, j, k;
            int n1 = middle - left + 1;
            int n2 =  right - middle;

            /* create temp arrays */
            int L[n1], R[n2];

            /* Copy data to temp arrays L[] and R[] */
            for (i = 0; i < n1; i++){
                L[i] = this->data[left + i];
            }
            for (j = 0; j < n2; j++){
                R[j] = this->data[middle + 1 + j];
            }

            /* Merge the temp arrays back into arr[l..r]*/
            i = 0; // Initial index of first subarray
            j = 0; // Initial index of second subarray
            k = left; // Initial index of merged subarray
            while (i < n1 && j < n2){
                if (L[i] <= R[j]){
                    this->data[k] = L[i];
                    i++;
                }
                else{
                    this->data[k] = R[j];
                    j++;
                }
                k++;
            }

            /* Copy the remaining elements of L[], if there are any */
            while (i < n1){
                this->data[k] = L[i];
                i++;
                k++;
            }

            /* Copy the remaining elements of R[], if there are any */
            while (j < n2){
                this->data[k] = R[j];
                j++;
                k++;
            }
        }
        void mergeSort(int left, int right){
            if(left < right){
                int middle = left + (right - left) / 2;

                mergeSort(left, middle);
                mergeSort(middle + 1, right);

                merge(left, middle, right);
            }
        }
    public:
        virtual void sort() {   // Merge Sort
            // https://www.geeksforgeeks.org/merge-sort/
            // std::cout << "Mystery Sorter E" << std::endl;

            vectorSize = this->data.size();
            mergeSort(0,vectorSize - 1);

            /*
            std::cout << "Mystery Sorter E" << std::endl;
            for(int i = 0; i < vectorSize; i++){
                std::cout << this->data[i] << std::endl;
            }
            */
        }
};

#endif //SORTINGFUN_SORTER_H

