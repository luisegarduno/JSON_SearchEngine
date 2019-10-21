#include <vector>
#include <iostream>
#include "dssorter.h"

using namespace std;

int main(){

    DSSorter<int> * sortData = new DSSorter<int>();

    sortData->dataSet1();               // Sort Vector size 10
    sortData->dataSet2();               // Sort Vector size 100
    sortData->dataSet3();               // Sort Vector size 500
    sortData->dataSet4();               // Sort Vector size 1k
    sortData->dataSet5();               // Sort Vector size 5k

    sortData->printAllResults();        // prints best,worst & average case for each dataSet
    sortData->fillMaps();               // creates map for each data set containing best run times
                                        // for each MysterySorter

    sortData->mysteryAnalyzer();

    delete sortData;

    return 0;
}
