#ifndef DELETETASK_H
#define DELETETASK_H
#include"mainwindow.h"
#include <QDialog>

namespace Ui {
class deletetask;
}

class deletetask : public QDialog
{
    Q_OBJECT

public:
    explicit deletetask(QWidget *parent = nullptr);
    ~deletetask();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::deletetask *ui;
    MainWindow mainw;
};

#endif // DELETETASK_H
