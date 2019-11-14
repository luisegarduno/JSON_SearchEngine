#ifndef INTERACTIVE_H
#define INTERACTIVE_H


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
    class Interactive;
}

class Interactive : public QDialog{
    Q_OBJECT

    public:
        // Explicit Constructor
        explicit Interactive(QWidget *parent = nullptr);

        // String is split into individual words, pushed into vector
        // once done, that vector is then returned.
        vector<string> getWords(string);

        // Interactive Class Destructor
        ~Interactive();

    private slots:
        // Closes "Interactive" windows and returns to "Mode" (Main Menu)
        void on_MainMenu_Button_clicked();

        void on_Search_Button_clicked();

private:
        // Interactive UI Pointer
        Ui::Interactive *ui;
};

#endif // INTERACTIVE_H
