#include "mode.h"
#include "ui_mode.h"

Mode::Mode(QWidget *parent): QMainWindow(parent), ui(new Ui::Mode){
    ui->setupUi(this);
}

void Mode::on_Maintenance_Button_clicked(){
    maintenanceMode = new Maintenance(this);
    maintenanceMode->show();
}

void Mode::on_Interactive_Button_clicked(){
    interactiveMode = new Interactive(this);
    interactiveMode->show();
}


Mode::~Mode(){
    delete ui;
}

