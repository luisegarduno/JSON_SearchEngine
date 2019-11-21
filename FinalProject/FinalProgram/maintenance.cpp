#include "maintenance.h"
#include "ui_maintenance.h"

Maintenance::Maintenance(QWidget *parent) :QDialog(parent), ui(new Ui::Maintenance){
    ui->setupUi(this);
}

void Maintenance::on_MainMenu_Button_clicked(){
    // Closes current window.
    this->close();
}


void Maintenance::on_ClearFile_Button_clicked(){
    QMessageBox::StandardButton confirmation;

    // Warning window is displayed to confirm user selection
    confirmation = QMessageBox::warning(this, "Clear", "Are you sure?", QMessageBox::Yes| QMessageBox::No);

    // If user selects "Yes", AVL Tree & Hash Table & ~possibly~ index file is cleared
    if(confirmation == QMessageBox::Yes){
        QMessageBox::information(this, "Clear", "Index has been cleared");
        this->close();
    }

    else{

    }
}

void Maintenance::on_AddFolder_Button_clicked(){
    QString file_name;
    // Opens local file directory, user is able to navigate to select desired folder
    //file_name = QFileDialog::getExistingDirectory(this, "Open Folder", QDir::homePath());
    file_name = QFileDialog::getExistingDirectory(this,"Open Folder","/home/student/Desktop/MyProjects/CSE2341-F19-Luis-Garduno/FinalProject/build-FinalProgram-Desktop_Qt_5_10_0_GCC_64bit-Debug/");

    // If no file was selected, display warning message
    if(file_name == ""){
        QString noFile = "Nothing was selected!\n";
        QString tryAgain = "Please select valid path to a folder";
        QMessageBox::warning(this,"Error", noFile + tryAgain);
    }
    else{
        // Information window is displayed containing selected folder
        QMessageBox::information(this, "File Selected", file_name);

        // QString is converted and saved as a standard string
        string fileName = file_name.toStdString();

        // A vector is created containing every path name for each file in folder
        allFileLocations = setFileLocations(fileName);
    }
}

vector<string> Maintenance::setFileLocations(string fileName){
    vector<string> allFileLocations;

    filesystem::directory_iterator end;
    for(filesystem::directory_iterator theIterator(fileName) ; theIterator!= end; ++theIterator){
        // directory iterator is first converted to a path
        filesystem::path dirToPath = *theIterator;

        // path directory is converted to a string
        string pathToString = dirToPath.string();

        // string is appended to end of vector
        allFileLocations.push_back(pathToString);

        // string is parsed to filename, and added to vector
        setFileNames(pathToString);
        totalFilesInFolder++;
    }

    return allFileLocations;
}

void Maintenance::setFileNames(string fileName){
    fileName.erase(0,137);

    fileNamesOnly.push_back(fileName);
}

// returns vector of strings containing file locations
vector<string> Maintenance::getFileNamesOnly(){
    return fileNamesOnly;
}

// returns vector of strings containing file locations
vector<string> Maintenance::getFileLocations(){
    return allFileLocations;
}

size_t Maintenance::getSizeOfFolder(){

    if(totalFilesInFolder > 0){
        return totalFilesInFolder;
    }

    return 0;
}

// Destructor
Maintenance::~Maintenance(){
    delete ui;
}
