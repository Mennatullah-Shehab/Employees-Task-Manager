#include "menu.h"
#include "ui_menu.h"
#include"addtask.h"
#include"mainwindow.h"
#include"deletetask.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    //Form's Background should be added here through picture's path on laptop
    //QPixmap bkgnd("C:/Users/Heba Magdy/OneDrive/Desktop/DataStructuresFinalProject/QTBackgrounds/task-management.jpg");
            //bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
            //QPalette palette;
            //palette.setBrush(QPalette::Background, bkgnd);
            //this->setPalette(palette);
}

menu::~menu()
{
    delete ui;
}

MainWindow *login;
void menu::on_pushButton_4_clicked()
{    this->hide();
     login = new MainWindow(this);
     login->show();
}
AddTask *tsk;

void menu::on_pushButton_clicked()
{
    this->hide();
    tsk = new AddTask(this);
    tsk->show();

}

deletetask *dt;
void menu::on_pushButton_3_clicked()
{
    this->hide();
    dt = new deletetask(this);
    dt->show();
}


