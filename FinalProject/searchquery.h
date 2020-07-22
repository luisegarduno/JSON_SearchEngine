#ifndef SEARCHQUERY_H
#define SEARCHQUERY_H

#include <string>
#include <vector>
#include <sstream>
#include <QDialog>
#include <iostream>
#include <QCheckBox>
#include <QMessageBox>
#include "index_interface.h"
#include "porter2_stemmer.h"
#include "maintenance.h"

using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::stringstream;
using std::cout, std::endl;

namespace Ui {
    class SearchQuery;
}

class SearchQuery : public QDialog {
    Q_OBJECT

    public:
        explicit SearchQuery(QWidget *parent = nullptr);

        // Declare's IndexMethod using parameter
        void setIndexMethod(string);

        // returns IndexMethod of type string
        string getIndexMethod();

        void setIndex();

        Index_Interface * theIndex;

        // SearchQuery destructor
        ~SearchQuery();

    private slots:
        void on_Search_Button_clicked();

        // Closes SearchQuery window and returned to Main Menu
        void on_MainMenu_Button_clicked();

    private:
        Ui::SearchQuery *ui;

        // contains which indexMethod was selected as type string
        string indexMethod;

        // String is split into individual words, pushed into vector
        // once done, that vector is then returned.
        vector<string> getWords(string);
};

#endif // SEARCHQUERY_H
