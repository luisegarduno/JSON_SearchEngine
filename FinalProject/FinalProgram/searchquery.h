#ifndef SEARCHQUERY_H
#define SEARCHQUERY_H

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

namespace Ui { class SearchQuery; }

class SearchQuery : public QDialog {
    Q_OBJECT

    public:
        explicit SearchQuery(QWidget *parent = nullptr);
        ~SearchQuery();

private slots:
    void on_Search_Button_clicked();

private:
        // String is split into individual words, pushed into vector
        // once done, that vector is then returned.
        vector<string> getWords(string);

        Ui::SearchQuery *ui;
};

#endif // SEARCHQUERY_H
