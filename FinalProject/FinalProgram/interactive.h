#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <QDialog>
#include <iostream>

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

    private:
        // Interactive UI Pointer
        Ui::Interactive *ui;
};

#endif // INTERACTIVE_H
