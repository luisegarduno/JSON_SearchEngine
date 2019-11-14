#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <QDialog>

namespace Ui {
    class Interactive;
}

class Interactive : public QDialog{
    Q_OBJECT

    public:
        explicit Interactive(QWidget *parent = nullptr);
        ~Interactive();

private slots:
    void on_MainMenu_Button_clicked();

private:
        Ui::Interactive *ui;
};

#endif // INTERACTIVE_H
