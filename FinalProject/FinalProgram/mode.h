#ifndef MODE_H
#define MODE_H

#include <QStyle>
#include <iostream>
#include <QMainWindow>
#include "maintenance.h"
#include "interactive.h"
#include <QDesktopWidget>

QT_BEGIN_NAMESPACE
    namespace Ui{ class Mode; }
QT_END_NAMESPACE

class Mode : public QMainWindow{
    Q_OBJECT

    public:
        friend class Maintenance;

        // Constructor
        Mode(QWidget *parent = nullptr);

        // Mode Class Destructor
        ~Mode();

    private slots:
        // If pressed, will go to "Maintenance" class, and open new window
        void on_Maintenance_Button_clicked();

        // If pressed, will go to "Interactive" class, and open new windows
        void on_Interactive_Button_clicked();

    private:
        // Mode UI Pointer
        Ui::Mode *ui;

        // Maintenance Object Pointer
        Maintenance * maintenanceMode;

        // vectors containing paths & file names
        vector<string> opinionLocations;

        // Interactive Object Pointer
        Interactive * interactiveMode;
};
#endif // MODE_H
