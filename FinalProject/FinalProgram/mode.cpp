#include "mode.h"
#include "ui_mode.h"

Mode::Mode(QWidget *parent): QMainWindow(parent), ui(new Ui::Mode){
    ui->setupUi(this);
}

void Mode::on_Maintenance_Button_clicked(){
    // Create new Maintenance window object on HEAP
    maintenanceMode = new Maintenance(this);
    maintenanceMode->show();
}

void Mode::on_Interactive_Button_clicked(){
    // Create new Interactive window object on HEAP
    interactiveMode = new Interactive(this);
    interactiveMode->show();
}


Mode::~Mode(){
    delete ui;
}

