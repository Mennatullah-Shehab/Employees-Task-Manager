#include "edittask.h"
#include "ui_edittask.h"
#include"mainwindow.h"
#include"task.h"
#include"addtask.cpp"
#include"LinkedList.h"
edittask::edittask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edittask)
{



}

edittask::~edittask()
{
    delete ui;
}
