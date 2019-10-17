#include <vector>
#include <iostream>
#include <stdlib.h>
#include "dssorter.h"

using namespace std;

int main(){

    DSSorter * sortData = new DSSorter();
    sortData->test1();
    //sortData->test2();

    delete sortData;

    return 0;
}
