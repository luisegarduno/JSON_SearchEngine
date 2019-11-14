#include "interactive.h"
#include "ui_interactive.h"

Interactive::Interactive(QWidget *parent) : QDialog(parent), ui(new Ui::Interactive){
    ui->setupUi(this);
}

void Interactive::on_MainMenu_Button_clicked(){
    this->close();
}

Interactive::~Interactive(){
    delete ui;
}
