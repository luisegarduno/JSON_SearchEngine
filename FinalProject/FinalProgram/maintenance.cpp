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
    // Opens local file directory, user is able to navigate to select desired folder
    QString file_name = QFileDialog::getExistingDirectory(this, "Open Folder", QDir::homePath());

    // Information window is displayed containing selected folder
    QMessageBox::information(this, "File Selected", file_name);


    // QString is converted and saved as a standard string
    string fileName = file_name.toStdString();

    // A vector is created containing every path name for each file in folder
    vector<string> allFileLocations = getFileLocations(fileName);

    for(size_t i = 0; i < allFileLocations.size(); i++){
        cout << allFileLocations[i] << endl;
    }
}

vector<string> Maintenance::getFileLocations(string fileName){
    vector<string> allFileLocations;

    filesystem::directory_iterator end;
    for(filesystem::directory_iterator theIterator(fileName) ; theIterator!= end; ++theIterator){
        // directory iterator is first converted to a path
        filesystem::path dirToPath = *theIterator;

        // path is then converted to a string
        string pathToString = dirToPath.string();

        // string is then appended to vector
        allFileLocations.push_back(pathToString);
    }

    return allFileLocations;
}

Maintenance::~Maintenance(){
    delete ui;
}