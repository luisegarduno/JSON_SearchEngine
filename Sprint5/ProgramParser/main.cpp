#include <iostream>
#include "parser.h"

using namespace std;

int main(int argc, char *argv[]){
    Parser newParser = Parser(argv);
    newParser.printFileNames();


    return 0;
}
