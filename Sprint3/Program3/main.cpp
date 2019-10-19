#include <vector>
#include <iostream>
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

    delete sortData;

    return 0;
}
