#include "maintenance.h"
#include "ui_maintenance.h"

Maintenance::Maintenance(QWidget *parent) :QDialog(parent), ui(new Ui::Maintenance){
    ui->setupUi(this);
}

void Maintenance::on_MainMenu_Button_clicked(){
    this->close();
}


void Maintenance::on_ClearFile_Button_clicked(){
    QMessageBox::StandardButton confirmation;
    confirmation = QMessageBox::warning(this, "Clear", "Are you sure?", QMessageBox::Yes| QMessageBox::No);

    if(confirmation == QMessageBox::Yes){
        QMessageBox::information(this, "Clear", "Index has been cleared");
        this->close();
    }

    else{

    }
}

void Maintenance::on_AddFolder_Button_clicked(){
     QString file_name = QFileDialog::getExistingDirectory(this, "Open Folder", QDir::homePath());
     QMessageBox::information(this, "File Selected", file_name);

     string fileName = file_name.toStdString();
}

Maintenance::~Maintenance(){
    delete ui;
}
