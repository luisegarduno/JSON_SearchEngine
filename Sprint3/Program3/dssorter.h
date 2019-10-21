#ifndef DSSORTER_H
#define DSSORTER_H

#include <vector>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <map>
#include "dsstring.h"
#include "sorter.h"

#define EXPERIMENT_SIZE 5                   // total number of Mystery Sorter's

using std::cout;
using std::endl;
using std::map;
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
        std::vector<T> data;                                // holds data for each dataSet
        size_t experimentNumber;
        Sorter<T>* experiment[EXPERIMENT_SIZE];             // pointer to each MysterySorter
        std::vector<double> theBest[EXPERIMENT_SIZE];       // contains best run times for each case
        std::vector<double> theWorst[EXPERIMENT_SIZE];      // contains worst run times for each case
        std::vector<double> theAverage[EXPERIMENT_SIZE];    // containts average run times for each case

        map<DSString, double> data_set1;
        map<DSString, double> data_set2;
        map<DSString, double> data_set3;
        map<DSString, double> data_set4;
        map<DSString, double> data_set5;

    public:

        DSSorter(){
            experiment[0] = new MysterySorterA<T>;
            experiment[1] = new MysterySorterB<T>;
            experiment[2] = new MysterySorterC<T>;
            experiment[3] = new MysterySorterD<T>;
            experiment[4] = new MysterySorterE<T>;

            for(int p = 0; p < EXPERIMENT_SIZE; p++){
                theBest[p].push_back(100000000.00001);          // declare a VERY large number the best case (so it's easily replaced)
                theWorst[p].push_back(0.00001);                 // declare a small number the worst case (so it's easily replaced)
            }
        }

        ~DSSorter(){
            for(int i = 0; i < EXPERIMENT_SIZE; i++){
                delete experiment[size_t(i)];
            }
        }

        void dataSet1(){
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

                    if(timeValue <= theBest[k].at(0)){
                        theBest[k].pop_back();                  // remove old best case
                        theBest[k].push_back(timeValue);        // add new best case
                    }

                    if(timeValue >= theWorst[k].at(0)){         // check to see if timeValue is worse than current worstCase
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }

                    times[k].push_back(timeValue);              // add timeValue to end of times vector for each individual
                }
            }

            calculateAverage(times);                            // calculate avg of times for each MysterySorter
            data.clear();                                       // erases everything in data vector
        }

        void dataSet2(){
            experimentNumber = 1;

            for(int i = 0; i < 100; i++){                       // adds 100 random values to data vector
               data.push_back(rand() % 100);
            }

            for(int p = 0; p < EXPERIMENT_SIZE; p++){
                theBest[p].push_back(1000000000.000000);        // declare a VERY large number the best case (so it's easily replaced)
                theWorst[p].push_back(0.00001);                 // declare a small number the worst case (so it's easily replaced)
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

                    if(timeValue <= theBest[k].at(experimentNumber)){
                        theBest[k].pop_back();
                        theBest[k].push_back(timeValue);
                    }

                    if(timeValue >= theWorst[k].at(experimentNumber)){
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }

                    times[k].push_back(timeValue);
                }
            }

            calculateAverage(times);
            data.clear();
        }

        void dataSet3(){
            experimentNumber = 2;

            for(int i = 0; i < 500; i++){                       // adds 500 random values to data vector
               data.push_back(rand() % 500);                    // adds values between 1 - 500
            }

            for(int p = 0; p < EXPERIMENT_SIZE; p++){
                theBest[p].push_back(1000000000.000000);        // declare a VERY large number the best case (so it's easily replaced)
                theWorst[p].push_back(0.00001);                 // declare a small number the worst case (so it's easily replaced)
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

                    if(timeValue <= theBest[k].at(experimentNumber)){
                        theBest[k].pop_back();
                        theBest[k].push_back(timeValue);
                    }

                    if(timeValue >= theWorst[k].at(experimentNumber)){
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }

                    times[k].push_back(timeValue);
                }
            }

            calculateAverage(times);
            data.clear();
        }

        void dataSet4(){
            experimentNumber = 3;

            for(int i = 0; i < 1000; i++){                      // generate 1k random variables to add to data vector
               data.push_back(rand() % 1000);                   // numbers between 1 - 1000
            }

            for(int p = 0; p < EXPERIMENT_SIZE; p++){
                theBest[p].push_back(1000000000.000000);        // declare a VERY large number the best case (so it's easily replaced)
                theWorst[p].push_back(0.00001);                 // declare a small number the worst case (so it's easily replaced)
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

                    if(timeValue <= theBest[k].at(experimentNumber)){
                        theBest[k].pop_back();
                        theBest[k].push_back(timeValue);
                    }

                    if(timeValue >= theWorst[k].at(experimentNumber)){
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }

                    times[k].push_back(timeValue);
                }
            }

            calculateAverage(times);
            data.clear();
        }

        void dataSet5(){
            experimentNumber = 4;

            for(int i = 0; i < 5000; i++){              // Get 5k random values
               data.push_back(rand() % 1000);           // between 1 - 1000
            }

            for(int p = 0; p < EXPERIMENT_SIZE; p++){
                theBest[p].push_back(1000000000.000000);        // declare a VERY large number the best case (so it's easily replaced)
                theWorst[p].push_back(0.00001);                 // declare a small number the worst case (so it's easily replaced)
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

                    if(timeValue <= theBest[k].at(experimentNumber)){
                        theBest[k].pop_back();
                        theBest[k].push_back(timeValue);
                    }

                    if(timeValue >= theWorst[k].at(experimentNumber)){
                        theWorst[k].pop_back();
                        theWorst[k].push_back(timeValue);
                    }

                    times[k].push_back(timeValue);
                }
            }

            calculateAverage(times);
            data.clear();                                           // erases everything from data vector
        }

        void calculateAverage(std::vector<double> times[]){         // passes times vector(contains all times for each MysterySorter[])
            size_t averageVectorSize;                               // size of the vector
            double finalAverage,total;                              // finalAvg & total will be double to be precise

            for(int x = 0; x < EXPERIMENT_SIZE; x++){
                averageVectorSize = times[x].size();                // set avgVecSize equal to current times[x](MysterySorter[x])
                total = finalAverage = 0.0;

                for(size_t y = 0; y < averageVectorSize; y++){
                    total += times[x].at(y);                        // add all times[x] together
                }

                finalAverage = total / averageVectorSize;           // divide total by # of elements
                theAverage[x].push_back(finalAverage);              // push calculated average on theAverage vector for MysterySort[x]
            }
        }

        void getMystery(int sorterNumber){                 // prints out the MysteryCase Sorter
            switch(sorterNumber) {
                case 0:
                    cout << "\tMysterySortA:";
                    break;
                case 1:
                    cout << "\tMysterySortB:";
                    break;
                case 2:
                    cout << "\tMysterySortC:";
                    break;
                case 3:
                    cout << "\tMysterySortD:";
                    break;
                case 4:
                    cout << "\tMysterySortE:";
                    break;
            default:                                        // if 0 > sorterNumber or sorterNumber >= 5
                cout << "Invalid sort case...";
            }
        }

        DSString getMysterySort(int sorterNumber){                 // prints out the MysteryCase Sorter
            switch(sorterNumber) {
                case 0:
                    return DSString("MysterySortA");
                case 1:
                    return DSString("MysterySortB");
                case 2:
                    return DSString("MysterySortC");
                case 3:
                    return DSString("MysterySortD");
                case 4:
                    return DSString("MysterySortE");
            default:                                        // if 0 > sorterNumber or sorterNumber >= 5
                cout << "Invalid sort case...";
                return DSString("ERROR");
            }
        }

        void fillMaps(){
            DSString letterA("MysterySorterA");
            data_set1.emplace(letterA,theBest[0].at(0));

            /*
            for(int testCase = 0; testCase < EXPERIMENT_SIZE; testCase++){
                for(int mysterySort = 0; mysterySort < EXPERIMENT_SIZE; mysterySort++){
                    if(testCase == 0){
                        data_set1.emplace(getMysterySort(mysterySort),theBest[mysterySort].at(testCase));
                    }
                    if(testCase == 1){
                        data_set2.emplace(getMysterySort(mysterySort),theBest[mysterySort].at(testCase));
                    }
                    if(testCase == 2){
                        data_set3.emplace(getMysterySort(mysterySort),theBest[mysterySort].at(testCase));
                    }
                    if(testCase == 3){
                        data_set4.emplace(getMysterySort(mysterySort),theBest[mysterySort].at(testCase));
                    }
                    if(testCase == 4){
                        data_set5.emplace(getMysterySort(mysterySort),theBest[mysterySort].at(testCase));
                    }
                    else{
                    }
                }
            }
            */
        }

        void printAllResults(){
            for(int testCase = 0; testCase < EXPERIMENT_SIZE; testCase++){                      // Prints all MysterySorts for each data sets
                cout << "DataSet[" << testCase + 1 << "]: " << endl;

                for(int mysterySort = 0; mysterySort < EXPERIMENT_SIZE; mysterySort++){
                    getMystery(mysterySort);


                    cout << "\tBest Case: " << theBest[mysterySort].at(testCase);
                    cout << "\tWorst Case: " << theWorst[mysterySort].at(testCase);
                    cout << "\tAverage Case: " << theAverage[mysterySort].at(testCase) << endl;
                }
                cout << endl;
            }
        }

        void mysteryAnalyzer(){


        }

        void solveMystery(){

        }
};


#endif // DSSORTER_H
