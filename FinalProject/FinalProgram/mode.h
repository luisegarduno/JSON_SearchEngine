#ifndef MODE_H
#define MODE_H

#include <iostream>
#include <QMainWindow>
#include "maintenance.h"
#include "interactive.h"

using std::cout;
using std::endl;

QT_BEGIN_NAMESPACE
    namespace Ui{ class Mode; }
QT_END_NAMESPACE

class Mode : public QMainWindow{
    Q_OBJECT

    public:
        Mode(QWidget *parent = nullptr);
        ~Mode();

    private slots:
        void on_Maintenance_Button_clicked();
        void on_Interactive_Button_clicked();

    private:
        Ui::Mode *ui;
        Maintenance * maintenanceMode;
        Interactive * interactiveMode;
};
#endif // MODE_H
