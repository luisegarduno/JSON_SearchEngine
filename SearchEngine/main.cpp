#include "mode.h"
#include <cstdio>
#include <QStyle>
#include <QApplication>
#include <QDesktopWidget>
#include <QGuiApplication>

using namespace std;
using namespace rapidjson;

int main(int argc, char *argv[]){
    QApplication theGUI(argc, argv);
    theGUI.setWindowIcon(QIcon("../SearchEngine/Images/icon.png"));
    // Creates new Window on Stack
    Mode selectMode;

    selectMode.setGeometry(
        QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    selectMode.size(),
                    qApp->desktop()->availableGeometry()
                    
        )
    );


    // Display "Mode" (Main Menu)
    selectMode.show();

    return theGUI.exec();
}

