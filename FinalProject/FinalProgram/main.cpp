#include "mode.h"
#include <cstdio>
#include <QApplication>

using namespace std;
using namespace rapidjson;

int main(int argc, char *argv[]){
    QApplication theGUI(argc, argv);

    // Creates new Window on Stack
    Mode selectMode;

    // Display "Mode" (Main Menu)
    selectMode.show();

    return theGUI.exec();
}

