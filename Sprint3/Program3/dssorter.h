#ifndef DSSORTER_H
#define DSSORTER_H

#include <stdlib.h>
#include <vector>
#include <chrono>
#include <algorithm>
#include "sorter.h"

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;


class Timer{
    private:
        using clock_t = high_resolution_clock;
        using milli_t = std::chrono::duration<double, std::milli>;

        std::chrono::time_point<clock_t> m_beg;

    public:
        Timer() : m_beg(clock_t::now()){}
        void reset(){
            m_beg = clock_t::now();
        }

        double elapsed() const{
            return std::chrono::duration_cast<milli_t>(clock_t::now() - m_beg).count();
        }
};

class DSSorter{
    private:
        std::vector<int> data;
        using clock_t = high_resolution_clock;
        using milli_t = std::chrono::duration<double, std::milli>;

    public:
        DSSorter(){}
        void test1(){

                for(int i = 0; i < 10; i++){
                    data.push_back(i);
                }
                int expSize = 5;
                Sorter<int>* experiment[expSize];
                std::vector<double>* average[expSize];
                experiment[0] = new MysterySorterA<int>;
                experiment[1] = new MysterySorterB<int>;
                experiment[2] = new MysterySorterC<int>;
                experiment[3] = new MysterySorterD<int>;
                experiment[4] = new MysterySorterE<int>;

                Timer theTime;
                double n;

                for(int j = 0; j < 3; j++){
                    for(int k = 0; k < expSize; k++){
                        experiment[k]->setData(data);
                        theTime.reset();
                        experiment[k]->sort();
                        n = theTime.elapsed();
                        average[k]->push_back(n);
                        cout << "Time taken: " << n << " milliseconds\n" << endl;
                    }
                }

                for(int m = 0; m < expSize; m++){
                    int averageVectorSize = average[m]->size();
                    for(int l = 0; l < averageVectorSize; l++){

                    }
                }

        }

        void test2(){

            for(int i = 0; i < 15; i++){
               data.push_back(rand() % 10);
            }

            Sorter<int>* experiment[5];
            experiment[0] = new MysterySorterA<int>;
            experiment[1] = new MysterySorterB<int>;
            experiment[2] = new MysterySorterC<int>;
            experiment[3] = new MysterySorterD<int>;
            experiment[4] = new MysterySorterE<int>;

            Timer theTime;

            for(int j = 0; j < 5; j++){
                experiment[j]->setData(data);
                theTime.reset();
                experiment[j]->sort();
                cout << "Time taken: " << theTime.elapsed() << " milliseconds\n" << endl;
            }
        }

        void test3(){}

        void test4(){}

        void test5(){}
};




#endif // DSSORTER_H
