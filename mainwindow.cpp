#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Form's Background should be added here through picture's path on laptop
    //QPixmap bkgnd("C:/Users/Heba Magdy/OneDrive/Desktop/DataStructuresFinalProject/QTBackgrounds/task-management.jpg");
            //bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
            //QPalette palette;
            //palette.setBrush(QPalette::Background, bkgnd);
            //this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->usertext->text();
    QString password = ui->passtext->text();

    if(username=="mohamed" && password=="mohamed123"){
          QMessageBox::information(this,"Login","Logged in Successfully");
          QString linkedname = "Mohamed";
          this->hide();
          nu = new menu(this);
          nu->show();

   }else if(username=="ahmed" && password=="ahmed123"){
          QMessageBox::information(this,"Login","Logged in Successfully");
          QString linkedname = "Ahmed";
          this->hide();
          nu = new menu(this);
          nu->show();
   }else if(username=="hassan" && password=="hassan123"){
          QMessageBox::information(this,"Login","Logged in Successfully");
          QString linkedname = "Hassan";
          this->hide();
          nu = new menu(this);
          nu->show();

}else {
        QMessageBox::warning(this,"Login","Incorrect Username or Password");
    }

}
