#ifndef EDITTASK_H
#define EDITTASK_H
#include"mainwindow.h"

#include <QDialog>

namespace Ui {
class edittask;
}

class edittask : public QDialog
{
    Q_OBJECT

public:
    explicit edittask(QWidget *parent = nullptr);
    ~edittask();

private:
    Ui::edittask *ui;
    MainWindow mainw;

};

#endif // EDITTASK_H
