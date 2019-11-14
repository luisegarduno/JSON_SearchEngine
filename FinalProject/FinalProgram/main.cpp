#include <QApplication>
#include "mode.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Mode selectMode;
    selectMode.show();

    return a.exec();
}
