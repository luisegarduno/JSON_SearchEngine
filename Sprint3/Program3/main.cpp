#include <vector>
#include <iostream>
#include <sorter.h>
#include "dssorter.h"

using namespace std;

int main(){

    DSSorter * sortData = new DSSorter();
    sortData->test1();                      // Sort Vector size 10
    sortData->test2();                      // Sort Vector size 15
    sortData->test3();                      // Sort Vector size 30
    sortData->test4();                      // Sort Vector size 50
    sortData->test5();                      // Sort Vector size 100

    delete sortData;

    return 0;
}
