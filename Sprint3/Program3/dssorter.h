#ifndef DSSORTER_H
#define DSSORTER_H

#include <vector>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include "sorter.h"

#define EXPERIMENT_SIZE 5                   // total number of Mystery Sorter's

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;

class Timer{
    private:
        using clock_t = high_resolution_clock;
        using micro_t = std::chrono::duration<double,std::micro>;

        std::chrono::time_point<clock_t> m_beg;

    public:
        Timer() : m_beg(clock_t::now()){}
        void reset(){
            m_beg = clock_t::now();
        }

        double elapsed() const{
            return std::chrono::duration_cast<micro_t>(clock_t::now() - m_beg).count();
        }
};

template <typename T>
class DSSorter{

    private:
        std::vector<T> data;
        size_t experimentNumber;
        Sorter<T>* experiment[EXPERIMENT_SIZE];
        std::vector<double> theAverage[EXPERIMENT_SIZE];

    public:
        DSSorter(){
            experiment[0] = new MysterySorterA<T>;
            experiment[1] = new MysterySorterB<T>;
            experiment[2] = new MysterySorterC<T>;
            experiment[3] = new MysterySorterD<T>;
            experiment[4] = new MysterySorterE<T>;
        }

        ~DSSorter(){
            for(int i = 0; i < EXPERIMENT_SIZE; i++){
                delete experiment[size_t(i)];
            }
        }
        void test1(){
            experimentNumber = 0;
            for(int i = 0; i < 10; i++){
                data.push_back(i);                              // adds values 1-10 to vector
            }

            Timer theTime;
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 20; j++){
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();                            // reset timer
                    experiment[k]->sort();                      // run MysterySorting algorithm
                    timeValue = theTime.elapsed();              // save the time elapsed into timeValue
                    times[k].push_back(timeValue);              // add timeValue to end of times vector for each individual
                }                                               // MysterySorter
            }

            cout << "Test 1: " << endl;
            calculateAverage(times);                            // calculate avg of times for each MysterySorter
            data.clear();                                       // erases everything in data vector
        }

        void test2(){
            experimentNumber = 1;

            for(int i = 0; i < 15; i++){                        // adds 15 random values to data vector
               data.push_back(rand() % 10);
            }

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
                }
            }

            cout << "Test 2: " << endl;
            calculateAverage(times);
            data.clear();
        }

        void test3(){
            experimentNumber = 2;

            for(int i = 0; i < 30; i++){                        // adds 30 random values to data vector
               data.push_back(rand() % 10);                     // adds values between 1-9
            }

            Timer theTime;
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 20; j++){
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();
                    experiment[k]->sort();
                    timeValue = theTime.elapsed();
                    times[k].push_back(timeValue);
                }
            }

            cout << "Test 3: " << endl;
            calculateAverage(times);
            data.clear();
        }

        void test4(){
            experimentNumber = 3;

            for(int i = 0; i < 50; i++){                            // generate 50 random variables to add to data vector
               data.push_back(rand() % 10);
            }

            Timer theTime;
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 20; j++){
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();
                    experiment[k]->sort();
                    timeValue = theTime.elapsed();
                    times[k].push_back(timeValue);
                }
            }

            cout << "Test 4: " << endl;
            calculateAverage(times);
            data.clear();
        }

        void test5(){
            experimentNumber = 4;

            for(int i = 0; i < 100; i++){
               data.push_back(rand() % 10);
            }

            Timer theTime;
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 20; j++){
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();
                    experiment[k]->sort();
                    timeValue = theTime.elapsed();
                    times[k].push_back(timeValue);
                }
            }

            cout << "Test 5: " << endl;
            calculateAverage(times);
            data.clear();
        }

        void test6(){
            experimentNumber = 5;

            for(int i = 0; i < 200; i++){                           // add 200 random single digit numbers to
               data.push_back(rand() % 10);                         // data vector
            }

            Timer theTime;
            double timeValue;
            std::vector<double> times[EXPERIMENT_SIZE];

            for(int j = 0; j < 20; j++){                            // calculate the average of 15 occurances
                for(int k = 0; k < EXPERIMENT_SIZE; k++){
                    experiment[k]->setData(data);
                    theTime.reset();
                    experiment[k]->sort();
                    timeValue = theTime.elapsed();
                    times[k].push_back(timeValue);
                }
            }

            cout << "Test 6: " << endl;
            calculateAverage(times);
            data.clear();
        }

        void calculateAverage(std::vector<double> times[]){                         // passes times vector(contains all times for each MysterySorter[])
            size_t averageVectorSize;                                               // size of the vector
            double finalAverage,total;                                              // finalAvg & total will be double to be precise

            for(int x = 0; x < EXPERIMENT_SIZE; x++){
                averageVectorSize = times[x].size();                                // set avgVecSize equal to current times[x](MysterySorter[x])
                total = finalAverage = 0.0;
                for(size_t y = 0; y < averageVectorSize; y++){
                    total += times[x].at(y);                                        // add all times[x] together
                }
                finalAverage = total / averageVectorSize;                           // divide total by # of elements
                theAverage[x].push_back(finalAverage);                              // push calculated average on theAverage vector for MysterySort[x]
                cout << "AVERAGE: " << theAverage[x].at(experimentNumber) << endl;
            }
            cout << endl;
        }
};


#endif // DSSORTER_H
