#include <vector>
#include <iostream>
#include <stdlib.h>
#include "dssorter.h"

using namespace std;

int main(){

    DSSorter * tempNew = new DSSorter;
    tempNew->test1();

    delete tempNew;

    return 0;
}
