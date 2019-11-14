#include "interactive.h"
#include "ui_interactive.h"

Interactive::Interactive(QWidget *parent) : QDialog(parent), ui(new Ui::Interactive){
    ui->setupUi(this);
}

void Interactive::on_MainMenu_Button_clicked(){
    // Closes current windows
    this->close();
}


void Interactive::on_Search_Button_clicked(){
    newQuery = new SearchQuery(this);
    newQuery->show();
}

void Interactive::on_IndexMethod_Button_clicked(){
    indexMethod = new IndexInterface(this);
    indexMethod->show();
}

void Interactive::on_Statistics_clicked(){
    newStatistics = new Statistics(this);
    newStatistics->show();
}

Interactive::~Interactive(){
    delete ui;
}

