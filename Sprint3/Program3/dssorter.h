#ifndef DSSORTER_H
#define DSSORTER_H

#include <stdlib.h>
#include <vector>
#include <chrono>
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
                    data.push_back(i);                              // adds values 1-10 to vector
                }

                const int expSize = 5;                              // declare number of experiments as constant
                Sorter<int>* experiment[expSize];
                std::vector<double> theAverage[expSize];
                std::vector<double> times[expSize];
                experiment[0] = new MysterySorterA<int>;
                experiment[1] = new MysterySorterB<int>;
                experiment[2] = new MysterySorterC<int>;
                experiment[3] = new MysterySorterD<int>;
                experiment[4] = new MysterySorterE<int>;

                Timer theTime;
                double timeValue;

                for(int j = 0; j < 3; j++){
                    for(int k = 0; k < expSize; k++){
                        experiment[k]->setData(data);
                        theTime.reset();
                        experiment[k]->sort();
                        timeValue = theTime.elapsed();
                        times[k].push_back(timeValue);
                        cout << "Time taken: " << timeValue << " milliseconds\n" << endl;
                    }
                }


                size_t averageVectorSize;
                double finalAverage,total;//,sum;

                for(int m = 0; m < expSize; m++){
                    averageVectorSize = times[m].size();
                    total = 0.0;
                    finalAverage = 0.0;
                    for(size_t l = 0; l < averageVectorSize; l++){
                        //sum = times[m].at(l);
                        total += times[m].at(l);
                    }
                    finalAverage = total / averageVectorSize;
                    theAverage[m].push_back(finalAverage);

                    cout << "AVERAGE: " << theAverage[m].at(0) << endl;
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
