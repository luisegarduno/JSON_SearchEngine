#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

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

namespace Ui { class IndexInterface; }

class IndexInterface : public QDialog{
    Q_OBJECT

    public:
        explicit IndexInterface(QWidget *parent = nullptr);
        ~IndexInterface();

    private:
        Ui::IndexInterface *ui;


};

#endif // INDEXINTERFACE_H
