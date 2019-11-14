#include "mode.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Mode selectMode;            // Creates new Window on Stack
    selectMode.show();          // Display "Mode" (Main Menu)

    return a.exec();
}
