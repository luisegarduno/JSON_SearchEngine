#include "mode.h"
#include <cstdio>
#include <QStyle>
#include <QApplication>
#include <QDesktopWidget>
#include <QGuiApplication>
#include <QScreen>

using namespace std;
using namespace rapidjson;

int main(int argc, char *argv[]){
    QApplication theGUI(argc, argv);
    theGUI.setWindowIcon(QIcon("../SearchEngine/Images/icon.png"));
    // Creates new Window on Stack
    Mode selectMode;

    // Get the screen where the widget should be centered
    QScreen *screen = QGuiApplication::screenAt(QCursor::pos());
    if (screen) {
        selectMode.setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                selectMode.size(),
                screen->availableGeometry()
                )
            );
    }

    // Display "Mode" (Main Menu)
    selectMode.show();

    return theGUI.exec();
}

