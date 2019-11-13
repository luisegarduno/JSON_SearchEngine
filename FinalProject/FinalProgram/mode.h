#ifndef MODE_H
#define MODE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Mode; }
QT_END_NAMESPACE

class Mode : public QMainWindow
{
    Q_OBJECT

public:
    Mode(QWidget *parent = nullptr);
    ~Mode();

private:
    Ui::Mode *ui;
};
#endif // MODE_H
