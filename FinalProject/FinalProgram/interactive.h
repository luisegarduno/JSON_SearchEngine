#ifndef INTERACTIVE_H
#define INTERACTIVE_H


#include <string>
#include <vector>
#include <sstream>
#include <QDialog>
#include <iostream>
#include <QMessageBox>

#include "statistics.h"
#include "searchquery.h"
#include "indexinterface.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::stringstream;

namespace Ui {
    class Interactive;
}

class Interactive : public QDialog{
    Q_OBJECT

    public:
        // Explicit Constructor
        explicit Interactive(QWidget *parent = nullptr);

        // Interactive Class Destructor
        ~Interactive();

    private slots:
        // Closes "Interactive" windows and returns to "Mode" (Main Menu)
        void on_MainMenu_Button_clicked();

        void on_Search_Button_clicked();

        void on_Statistics_clicked();

        void on_IndexMethod_Button_clicked();

private:
        // Interactive UI Pointer
        Ui::Interactive *ui;

        IndexInterface * indexMethod;
        SearchQuery * newQuery;
        Statistics * newStatistics;
};

#endif // INTERACTIVE_H
