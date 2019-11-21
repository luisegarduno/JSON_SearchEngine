#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QDir>
#include <string>
#include <vector>
#include <QDebug>
#include <QDialog>
#include <QString>
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <QMessageBox>
#include <experimental/filesystem>

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

        // Vectors containing all strings
        vector<string> getFileLocations();
        vector<string> getFileNamesOnly();

        size_t getSizeOfFolder();

        // Maintenance Class Destructor
        ~Maintenance();

    private slots:

        // Clears contents in AVL Tree & Hash Table, also ~possibly~ deletes index file
        void on_ClearFile_Button_clicked();

        // Open up local file directory, and User is able to select Folder Directory Path
        void on_AddFolder_Button_clicked();

        // Closes "Maintenance" windows and returns to "Mode" (Main Menu)
        void on_MainMenu_Button_clicked();

    private:
        // Maintenance UI Pointer
        Ui::Maintenance *ui;

        size_t totalFilesInFolder;

        // vector containing allFileLocations as string types
        vector<string> allFileLocations;

        // vector containing the name of the files
        vector<string> fileNamesOnly;

        // iterates through folder and converts each directory path into a string
        vector<string> setFileLocations(string);

        // erases the file path to only leave the file name.Then pushed to vector
        void setFileNames(string);

};

#endif // MAINTENANCE_H
