#include <vector>
#include <iostream>
#include "dsstring.h"
#include "dssorter.h"

using namespace std;

int main(){

    DSSorter<int> * sortData = new DSSorter<int>();

    sortData->test1();                      // Sort Vector size 10
    sortData->test2();                      // Sort Vector size 15
    sortData->test3();                      // Sort Vector size 30
    sortData->test4();                      // Sort Vector size 50
    sortData->test5();                      // Sort Vector size 100
    sortData->test6();                      // Sort Vector size 200


    sortData->printResults(0);              // prints best,worst,avg case for MysterySortA
    sortData->printResults(1);              //                                MysterySortB
    sortData->printResults(2);              //                                MysterySortC
    sortData->printResults(3);              //                                MysterySortD
    sortData->printResults(4);                //                                MysterySortE

    sortData->printAverage(0);

    delete sortData;

    return 0;
}
