#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <string>
#include <vector>
#include <iomanip>
#include <QDialog>
#include <sstream>
#include <iostream>
#include <QCheckBox>
#include <QMessageBox>
#include "searchquery.h"
#include "maintenance.h"
#include "avltree_index.h"
#include "index_interface.h"
#include "hashtable_index.h"
#include <QDialogButtonBox>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::to_string;
using std::stringstream;

namespace Ui {
    class Interactive;
}

class Interactive : public QDialog{
    Q_OBJECT

    public:
        // Explicit Constructor
        explicit Interactive(QWidget *parent = nullptr);

        // returns Total number of opinions indexed
        int getNumOfOpinions();

        // Returns  the average number of words indexed per opinion
        // (after removal of stop words)
        double getAvgNumIndexWords();

        // avlTreeSelected & hashTableSelected work as boolean getters
        bool avlTreeSelected();
        bool hashTableSelected();

        // numberOfOpinions, avgIndexedWords, & top50Words are outputted when
        // statistics button is clicked
        int numberOfOpinions;
        double avgIndexedWords;
        vector<string> top50Words;

        // Interactive Class Destructor
        ~Interactive();

    private slots:
        // Closes "Interactive" windows and returns to "Mode" (Main Menu)
        void on_MainMenu_Button_clicked();

        // Uses buttons to let user know what type of Data Structure to
        // use when loading in Index
        void on_IndexMethod_Button_clicked();

        // Open search query
        void on_Search_Button_clicked();

        // When called, it displays a window containing basic statistics
        void on_Statistics_clicked();



private:
        // Interactive UI Pointer
        Ui::Interactive *ui;

        SearchQuery * newQuery;

        Index_Interface * indexInterface;

        // avlTreeFlag & hashTableFlag are type boolean and work
        // as a way to tell which Index method has been chosen
        // Ex 1: (avlTreeFlag == true && hashTableFlag == false) --> AVL Tree
        // Ex 2: (avlTreeFlag == false && hashTableFlag == true) --> Hash Map
        // Ex 3: (avlTreeFlag == false && hashTableFlag == false) --> None selected
        bool avlTreeFlag;
        bool hashTableFlag;

        vector<string> fileDirectory;
        void setFileDirectory(vector<string>);
};

#endif // INTERACTIVE_H
