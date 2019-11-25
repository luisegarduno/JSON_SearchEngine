#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QDir>
#include <string>
#include <vector>
#include <QDebug>
#include <sstream>
#include <fstream>
#include <QDialog>
#include <QString>
#include <iostream>
#include <algorithm>
#include <QMessageBox>
#include <QFileDialog>
#include <QMessageBox>
#include <unordered_set>
#include "porter2_stemmer.h"
#include "rapidjson/document.h"
#include <experimental/iterator>
#include <experimental/filesystem>
#include "rapidjson/filereadstream.h"

using namespace rapidjson;

namespace filesystem = std::experimental::filesystem;

using std::cout;
using std::endl;
using std::copy;
using std::fopen;
using std::vector;
using std::string;
using std::ifstream;
using std::remove_if;
using std::istringstream;
using std::unordered_set;
using std::ostream_iterator;

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

        size_t getTotalNumValidDocs();

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

        size_t totalNumOfValidDocs;

        // vector containing allFileLocations as string types
        vector<string> allFileLocations;

        // vector containing the name of the files
        vector<string> fileNamesOnly;

        Document parseJSON(string);

        void parse(string);


        // iterates through folder and converts each directory path into a string
        vector<string> setFileLocations(string);

};

#endif // MAINTENANCE_H
