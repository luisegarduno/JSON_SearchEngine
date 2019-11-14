#include "indexinterface.h"
#include "ui_indexinterface.h"

IndexInterface::IndexInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IndexInterface)
{
    ui->setupUi(this);
}

IndexInterface::~IndexInterface()
{
    delete ui;
}
