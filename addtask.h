#ifndef ADDTASK_H
#define ADDTASK_H
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AddTask;
}

class AddTask : public QDialog
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = nullptr);
    ~AddTask();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_title_cursorPositionChanged(int arg1, int arg2);

    void on_horizontalSlider_actionTriggered(int action);

    void on_horizontalSlider_rangeChanged(int min, int max);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::AddTask *ui;
    MainWindow mw;

};

#endif // ADDTASK_H
