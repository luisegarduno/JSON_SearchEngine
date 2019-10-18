#ifndef DSSORTER_H
#define DSSORTER_H

#include <stdlib.h>
#include <vector>
#include <chrono>
#include "sorter.h"

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
#define EXPERIMENT_SIZE 5


class Timer{
    private:
        using clock_t = high_resolution_clock;
        using milli_t = std::chrono::duration<double,std::micro>;

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
        std::vector<double> theAverage[EXPERIMENT_SIZE];
        using clock_t = high_resolution_clock;
        using milli_t = std::chrono::duration<double,std::micro>;
        size_t experimentNumber;

    public:
        DSSorter(){}
        void test1(){
            experimentNumber = 0;
            for(int i = 0; i < 10; i++){
                data.push_back(i);                              // adds values 1-10 to vector
            }

            Sorter<int>* experiment[EXPERIMENT_SIZE];
            experiment[0] = new MysterySorterA<int>;
            experiment[1] = new MysterySorterB<int>;
            experiment[2] = new MysterySorterC<int>;
            experiment[3] = new MysterySorterD<int>;
            experiment[4] = new MysterySorterE<int>;

            Timer theTime;
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 15; j++){
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();
                    experiment[k]->sort();
                    timeValue = theTime.elapsed();
                    times[k].push_back(timeValue);
                    //cout << "Time taken: " << timeValue << " milliseconds\n" << endl;
                }
            }

            cout << "Test 1: " << endl;
            calculateAverage(times);
        }

        void test2(){
            experimentNumber = 1;

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
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 15; j++){
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();
                    experiment[k]->sort();
                    timeValue = theTime.elapsed();
                    times[k].push_back(timeValue);
                    //cout << "Time taken: " << timeValue << " milliseconds\n" << endl;
                }
            }

            cout << "Test 2: " << endl;
            calculateAverage(times);
        }

        void test3(){
            experimentNumber = 2;

            for(int i = 0; i < 30; i++){
               data.push_back(rand() % 10);
            }

            Sorter<int>* experiment[5];
            experiment[0] = new MysterySorterA<int>;
            experiment[1] = new MysterySorterB<int>;
            experiment[2] = new MysterySorterC<int>;
            experiment[3] = new MysterySorterD<int>;
            experiment[4] = new MysterySorterE<int>;

            Timer theTime;
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 15; j++){
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();
                    experiment[k]->sort();
                    timeValue = theTime.elapsed();
                    times[k].push_back(timeValue);
                    //cout << "Time taken: " << timeValue << " milliseconds\n" << endl;
                }
            }

            cout << "Test 3: " << endl;
            calculateAverage(times);
        }

        void test4(){
            experimentNumber = 3;

            for(int i = 0; i < 50; i++){
               data.push_back(rand() % 10);
            }

            Sorter<int>* experiment[5];
            experiment[0] = new MysterySorterA<int>;
            experiment[1] = new MysterySorterB<int>;
            experiment[2] = new MysterySorterC<int>;
            experiment[3] = new MysterySorterD<int>;
            experiment[4] = new MysterySorterE<int>;

            Timer theTime;
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 15; j++){
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();
                    experiment[k]->sort();
                    timeValue = theTime.elapsed();
                    times[k].push_back(timeValue);
                    //cout << "Time taken: " << timeValue << " milliseconds\n" << endl;
                }
            }

            cout << "Test 4: " << endl;
            calculateAverage(times);
        }

        void test5(){
            experimentNumber = 4;

            for(int i = 0; i < 100; i++){
               data.push_back(rand() % 10);
            }

            Sorter<int>* experiment[5];
            experiment[0] = new MysterySorterA<int>;
            experiment[1] = new MysterySorterB<int>;
            experiment[2] = new MysterySorterC<int>;
            experiment[3] = new MysterySorterD<int>;
            experiment[4] = new MysterySorterE<int>;

            Timer theTime;
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 15; j++){
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();
                    experiment[k]->sort();
                    timeValue = theTime.elapsed();
                    times[k].push_back(timeValue);
                    //cout << "Time taken: " << timeValue << " milliseconds\n" << endl;
                }
            }

            cout << "Test 5: " << endl;
            calculateAverage(times);
        }

        void calculateAverage(std::vector<double> times[]){
            size_t averageVectorSize;
            double finalAverage,total;

            for(int m = 0; m < EXPERIMENT_SIZE; m++){
                averageVectorSize = times[m].size();
                total = finalAverage = 0.0;
                for(size_t l = 0; l < averageVectorSize; l++){
                    total += times[m].at(l);
                }
                finalAverage = total / averageVectorSize;
                theAverage[m].push_back(finalAverage);
                cout << "AVERAGE: " << theAverage[m].at(experimentNumber) << endl;
            }
            cout << endl;
        }
};




#endif // DSSORTER_H
