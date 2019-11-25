#include "mode.h"
#include <QApplication>

#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>

using namespace rapidjson;
using namespace std;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Mode selectMode;            // Creates new Window on Stack
    selectMode.show();          // Display "Mode" (Main Menu)

    return a.exec();
}

