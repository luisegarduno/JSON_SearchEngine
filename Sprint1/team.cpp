#include "team.h"
#include <iostream>

using std::cout;
using std::endl;

Team::Team(){
    cout << "in Team Default constructor " << endl;
}

Team::Team(const DSString& teamFile){
    cout << teamFile << endl;
}


