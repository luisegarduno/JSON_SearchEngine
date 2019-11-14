#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include <vector>
#include <sstream>
#include <QDialog>
#include <iostream>
#include <QMessageBox>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::stringstream;

namespace Ui {
class Statistics;
}

class Statistics : public QDialog
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
