#include <vector>
#include <iostream>
#include "dsstring.h"
#include "dssorter.h"

using namespace std;

int main(){

    DSSorter<int> * sortData = new DSSorter<int>();

    sortData->test1();                      // Sort Vector size 10
    sortData->test2();                      // Sort Vector size 100
    sortData->test3();                      // Sort Vector size 500
    sortData->test4();                      // Sort Vector size 1k
    sortData->test5();                      // Sort Vector size 5k

    sortData->printAllResults();

    delete sortData;

    return 0;
}
