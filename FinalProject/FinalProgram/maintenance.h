#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QDir>
#include <string>
#include <QDebug>
#include <QDialog>
#include <QString>
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <QMessageBox>

using std::string;
using std::cout;
using std::endl;

namespace Ui {
    class Maintenance;
}

class Maintenance : public QDialog{
    Q_OBJECT

    public:
        explicit Maintenance(QWidget *parent = nullptr);
        ~Maintenance();

private slots:
    void on_MainMenu_Button_clicked();

    void on_ClearFile_Button_clicked();

    void on_AddFolder_Button_clicked();

private:
        Ui::Maintenance *ui;
};

#endif // MAINTENANCE_H
