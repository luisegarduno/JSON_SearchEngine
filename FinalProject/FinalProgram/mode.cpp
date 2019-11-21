#include "mode.h"
#include "ui_mode.h"

Mode::Mode(QWidget *parent): QMainWindow(parent), ui(new Ui::Mode){
    ui->setupUi(this);
    totalOpinionsInFolder = 0;
}

void Mode::on_Maintenance_Button_clicked(){
    // Create new Maintenance window object on HEAP
    maintenanceMode = new Maintenance(this);
    maintenanceMode->show();
}

void Mode::on_Interactive_Button_clicked(){
    totalOpinionsInFolder = maintenanceMode->getSizeOfFolder();

    if(totalOpinionsInFolder > 0){
        opinionLocations = maintenanceMode->getFileLocations();
        fileNames = maintenanceMode->getFileNamesOnly();

        for(size_t counter = 0; counter < opinionLocations.size(); counter++){
            cout << "[" << counter + 1 << "]: " << opinionLocations[counter] << endl;
            cout << "[" << counter + 1 << "]: " << fileNames[counter] << endl << endl;
        }

        // Create new Interactive window object on HEAP
        interactiveMode = new Interactive(this);
        interactiveMode->show();
    }

    /*else{
        QString noFile = "No opinions added!\n";
        QString tryAgain = "Please select valid path to a folder";
        QMessageBox::warning(this,"Error", noFile + tryAgain);
    }*/
}


Mode::~Mode(){
    delete ui;
}

