#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QDir>
#include <string>
#include <vector>
#include <QDebug>
#include <QDialog>
#include <QString>
#include <iostream>
#include <experimental/filesystem>
#include <QMessageBox>
#include <QFileDialog>
#include <QMessageBox>

namespace filesystem = std::experimental::filesystem;

using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace Ui {
    class Maintenance;
}

class Maintenance : public QDialog{
    Q_OBJECT

    public:
        // Explicit Constructor
        explicit Maintenance(QWidget *parent = nullptr);
        vector<string> getFileLocations();

        // Maintenance Class Destructor
        ~Maintenance();

    private slots:
        // Closes "Maintenance" windows and returns to "Mode" (Main Menu)
        void on_MainMenu_Button_clicked();

        // Clears contents in AVL Tree & Hash Table, also ~possibly~ deletes index file
        void on_ClearFile_Button_clicked();

        // Open up local file directory, and User is able to select Folder Directory Path
        void on_AddFolder_Button_clicked();

    private:
        // Maintenance UI Pointer
        Ui::Maintenance *ui;

        vector<string> allFileLocations;

        // iterates through folder and converts each directory path into a string
        vector<string> setFileLocations(string);

};

#endif // MAINTENANCE_H
