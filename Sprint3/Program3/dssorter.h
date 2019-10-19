#ifndef DSSORTER_H
#define DSSORTER_H

#include <vector>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include "dsstring.h"
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
        std::vector<double> theBest[EXPERIMENT_SIZE];
        std::vector<double> theWorst[EXPERIMENT_SIZE];
        std::vector<double> theAverage[EXPERIMENT_SIZE];

        std::vector<double> mystSortA[EXPERIMENT_SIZE + 1];
        std::vector<double> mystSortB[EXPERIMENT_SIZE + 1];
        std::vector<double> mystSortC[EXPERIMENT_SIZE + 1];
        std::vector<double> mystSortD[EXPERIMENT_SIZE + 1];
        std::vector<double> mystSortE[EXPERIMENT_SIZE + 1];

    public:
        DSSorter(){
            experiment[0] = new MysterySorterA<T>;
            experiment[1] = new MysterySorterB<T>;
            experiment[2] = new MysterySorterC<T>;
            experiment[3] = new MysterySorterD<T>;
            experiment[4] = new MysterySorterE<T>;

           // for(int p = 0; p < EXPERIMENT_SIZE; p++){
             //   theBest[p].push_back(1000000000.000000);          // declare a VERY large number the best case (so it's easily replaced)
            //    theWorst[p].push_back(0.00001);                 // declare a small number the worst case (so it's easily replaced)
            //}
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

            for(int p = 0; p < EXPERIMENT_SIZE; p++){
                theBest[p].push_back(1000000000.000000);          // declare a VERY large number the best case (so it's easily replaced)
                theWorst[p].push_back(0.00001);                 // declare a small number the worst case (so it's easily replaced)
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
                    if(timeValue <= theBest[k].at(0)){
                        theBest[k].pop_back();                  // remove old best case
                        theBest[k].push_back(timeValue);        // add new best case
                    }
                    if(timeValue >= theWorst[k].at(0)){         // check to see if timeValue is worse than current worstCase
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }
                    times[k].push_back(timeValue);              // add timeValue to end of times vector for each individual

                }                                               // MysterySorter
            }

            //cout << "Test 1: " << endl;
            calculateAverage(times);                            // calculate avg of times for each MysterySorter
            //cout << "The Best: " << theBest[0].at(0);
            addMysterySortA(experimentNumber);
            addMysterySortB(experimentNumber);

            data.clear();                                       // erases everything in data vector
        }

        void test2(){
            experimentNumber = 1;

            for(int i = 0; i < 15; i++){                        // adds 15 random values to data vector
               data.push_back(rand() % 10);
            }

            for(int p = 0; p < EXPERIMENT_SIZE; p++){
                theBest[p].push_back(1000000000.000000);          // declare a VERY large number the best case (so it's easily replaced)
                theWorst[p].push_back(0.00001);                 // declare a small number the worst case (so it's easily replaced)
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
                    if(timeValue <= theBest[k].at(0)){
                        theBest[k].pop_back();
                        theBest[k].push_back(timeValue);
                    }
                    if(timeValue >= theWorst[k].at(0)){
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }
                    times[k].push_back(timeValue);
                }
            }

            //cout << "Test 2: " << endl;
            calculateAverage(times);

            addMysterySortA(experimentNumber);
            addMysterySortB(experimentNumber);

            data.clear();
        }

        void test3(){
            experimentNumber = 2;

            for(int i = 0; i < 20; i++){                        // adds 30 random values to data vector
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
                    if(timeValue <= theBest[k].at(0)){
                        theBest[k].pop_back();
                        theBest[k].push_back(timeValue);
                    }
                    if(timeValue >= theWorst[k].at(0)){
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }
                    times[k].push_back(timeValue);
                }
            }

            //cout << "Test 3: " << endl;
            calculateAverage(times);

            addMysterySortA(experimentNumber);
            addMysterySortB(experimentNumber);

            data.clear();
        }

        void test4(){
            experimentNumber = 3;

            for(int i = 0; i < 75; i++){                            // generate 50 random variables to add to data vector
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
                    if(timeValue <= theBest[k].at(0)){
                        theBest[k].pop_back();
                        theBest[k].push_back(timeValue);
                    }
                    if(timeValue >= theWorst[k].at(0)){
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }
                    times[k].push_back(timeValue);
                }
            }

            //cout << "Test 4: " << endl;
            calculateAverage(times);

            addMysterySortA(experimentNumber);
            addMysterySortB(experimentNumber);

            data.clear();
        }

        void test5(){
            experimentNumber = 4;

            for(int i = 0; i < 150; i++){
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

                    if(timeValue <= theBest[k].at(0)){
                        theBest[k].pop_back();
                        theBest[k].push_back(timeValue);
                    }
                    if(timeValue >= theWorst[k].at(0)){
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }
                    times[k].push_back(timeValue);
                }
            }

            //cout << "Test 5: " << endl;
            calculateAverage(times);

            addMysterySortA(experimentNumber);
            addMysterySortB(experimentNumber);

            data.clear();                                           // erases everything from data vector
        }

        void addMysterySortA(int i){
            mystSortA[i].push_back(theBest[i].at(0));
            mystSortA[i].push_back(theWorst[i].at(0));
            mystSortA[i].push_back(theAverage[i].at(0));

        }

        void addMysterySortB(int i){
            mystSortB[i].push_back(theBest[i].at(0));
            mystSortB[i].push_back(theWorst[i].at(0));
            mystSortB[i].push_back(theAverage[i].at(0));
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

                //cout << "AVERAGE: " << theAverage[x].at(experimentNumber) << endl;
            }
            //cout << endl;
        }

        void printResults(int mysterySorter){
            if(mysterySorter == 0){
                cout << "MysterySortA: " << endl;
                for(int b = 0; b < EXPERIMENT_SIZE; b++){
                    cout << "TEST[" << b + 1 << "]:" << endl;
                    cout << "\tBest Case: " << mystSortA[b].at(0) << endl;
                    cout << "\tWorst Case: " << mystSortA[b].at(1) << endl;
                    cout << "\tAverage Case: " << mystSortA[b].at(2) << endl;
                }
                cout << endl;
            }
            else if(mysterySorter == 1){
                cout << "MysterySortB: " << endl;
                for(int b = 0; b < EXPERIMENT_SIZE; b++){
                    cout << "TEST[" << b + 1 << "]:" << endl;
                    cout << "\tBest Case: " << mystSortB[b].at(0) << endl;
                    cout << "\tWorst Case: " << mystSortB[b].at(1) << endl;
                    cout << "\tAverage Case: " << mystSortB[b].at(2) << endl;
                }
                cout << endl;
            }

        }

        void getMystery(int i){
            if(i == 0){
                cout << "MysterySortA: " << endl;
            }
            if(i == 1){
                cout << "MysterySortB: " << endl;
            }
            if(i == 2){
                cout << "MysterySortC: " << endl;
            }
            if(i == 3){
                cout << "MysterySortD: " << endl;
            }
            if(i == 4){
                cout << "MysterySortE: " << endl;
            }
        }


        void printAverage(int i){
            getMystery(i);
            int averageVectorSize = theAverage[i].size();

            for(int j = 0; j < averageVectorSize; j++){
                cout << "TEST[" << j + 1 << "]:" << endl;
                cout << "\tBest Case: " << theBest[j].at(0) << endl;
                cout << "\tWorst Case: " << theWorst[j].at(0) << endl;
                cout << "\tAverage Case: " << theAverage[j].at(i) << endl;
            }
            cout << endl;
        }
};


#endif // DSSORTER_H
