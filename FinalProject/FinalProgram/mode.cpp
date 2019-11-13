#include "mode.h"
#include "ui_mode.h"

Mode::Mode(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mode)
{
    ui->setupUi(this);
}

Mode::~Mode()
{
    delete ui;
}

