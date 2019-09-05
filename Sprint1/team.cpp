#include "team.h"
#include "dsstring.h"
#include <iostream>

using std::cout;
using std::endl;

Team::Team(){
    cout << "\nin Team Default constructor " << endl;
}

Team::Team(DSString teamFileName){
    cout << endl;
    cout << teamFileName.c_str() << endl;;


}


