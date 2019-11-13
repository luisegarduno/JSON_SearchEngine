#include "mode.h"

#include <QApplication>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cout << "howdy" << endl;
    Mode w;
    w.show();
    return a.exec();
}
