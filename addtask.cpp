#include "addtask.h"
#include "ui_addtask.h"
#include "LinkedList.cpp"
#include"menu.h"
#include <QMessageBox>

LinkedList<task> mo;
LinkedList<task> am;
LinkedList<task> hs;

AddTask::AddTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTask)
{
    ui->setupUi(this);
    //Form's Background should be added here through picture's path on laptop
    //QPixmap bkgnd("C:/Users/Heba Magdy/OneDrive/Desktop/DataStructuresFinalProject/QTBackgrounds/task-management.jpg");
            //bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
            //QPalette palette;
            //palette.setBrush(QPalette::Background, bkgnd);
            //this->setPalette(palette);

}

AddTask::~AddTask()
{
    delete ui;
}
void AddTask::on_pushButton_clicked()
{
    if(mw.linkedname=="Mohamed") {
   task t1;
   t1.TaskTitle = ui->title->text().toStdString();
   t1.Description = ui->Description->text().toStdString();
   t1.PriorityValues = ui->priority->text().toInt();
   t1.AssignedDate = ui->AssignDate->text().toStdString();
   t1.EmployeeName = mw.linkedname.toStdString();
   t1.RequiredEndingDate = ui->ReqEndDate->text().toStdString();
   if(ui->title->text()==NULL ||ui->Description->text()==NULL||ui->priority->text()==NULL||ui->AssignDate->text()==NULL||ui->ReqEndDate->text()==NULL){
       QMessageBox::warning(this,"Missing Info","Please fill the blank fields.");
   }
   if(ui->priority->text().toInt()>10||ui->priority->text().toInt()<1){
       QMessageBox::warning(this,"Invalid Priority Value","Please enter an integer between 1 and 10.");
   }
   if(ui->title->text()!=NULL&&ui->Description->text()!=NULL&&ui->priority->text()!=NULL&&ui->AssignDate->text()!=NULL&&ui->ReqEndDate->text()!=NULL){
       if(ui->priority->text().toInt()<=10&&ui->priority->text().toInt()>=1){
           mo.Append(t1);
           mo.Insert_sorted_descending();
           mo.DateSorting();
       }}


    }else if (mw.linkedname=="Ahmed"){
        task t1;
        t1.TaskTitle = ui->title->text().toStdString();
        t1.Description = ui->Description->text().toStdString();
        t1.PriorityValues = ui->priority->text().toInt();
        t1.AssignedDate = ui->AssignDate->text().toStdString();
        t1.EmployeeName = mw.linkedname.toStdString();
        t1.RequiredEndingDate = ui->ReqEndDate->text().toStdString();
        if(ui->title->text()==NULL ||ui->Description->text()==NULL||ui->priority->text()==NULL||ui->AssignDate->text()==NULL||ui->ReqEndDate->text()==NULL){
            QMessageBox::warning(this,"Missing Info","Please fill the blank fields.");
        }
        if(ui->priority->text().toInt()>10||ui->priority->text().toInt()<1){
            QMessageBox::warning(this,"Invalid Priority Value","Please enter an integer between 1 and 10.");
        }
        if(ui->title->text()!=NULL&&ui->Description->text()!=NULL&&ui->priority->text()!=NULL&&ui->AssignDate->text()!=NULL&&ui->ReqEndDate->text()!=NULL){
            if(ui->priority->text().toInt()<=10&&ui->priority->text().toInt()>=1){
                am.Append(t1);
                am.Insert_sorted_descending();
                am.DateSorting();
            }}


    }else {
        task t1;
        t1.TaskTitle = ui->title->text().toStdString();
        t1.Description = ui->Description->text().toStdString();
        t1.PriorityValues = ui->priority->text().toInt();
        t1.AssignedDate = ui->AssignDate->text().toStdString();
        t1.EmployeeName = mw.linkedname.toStdString();
        t1.RequiredEndingDate = ui->ReqEndDate->text().toStdString();
        if(ui->title->text()==NULL ||ui->Description->text()==NULL||ui->priority->text()==NULL||ui->AssignDate->text()==NULL||ui->ReqEndDate->text()==NULL){
            QMessageBox::warning(this,"Missing Info","Please fill the blank fields.");
        }
        if(ui->priority->text().toInt()>10||ui->priority->text().toInt()<1){
            QMessageBox::warning(this,"Invalid Priority Value","Please enter an integer between 1 and 10.");
        }
        if(ui->title->text()!=NULL&&ui->Description->text()!=NULL&&ui->priority->text()!=NULL&&ui->AssignDate->text()!=NULL&&ui->ReqEndDate->text()!=NULL){
            if(ui->priority->text().toInt()<=10&&ui->priority->text().toInt()>=1){
                hs.Append(t1);
                hs.Insert_sorted_descending();
                hs.DateSorting();

            }}




    }
    ui->title->clear();
    ui->AssignDate->clear();
    ui->ReqEndDate->clear();
    ui->Description->clear();
    ui->priority->clear();
    ui->title->setFocus();

}
menu *mnu;

void AddTask::on_pushButton_2_clicked()
{
    this->hide();
    mnu= new menu(this);
    mnu->show();
}





void AddTask::on_horizontalSlider_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->priority->setText(s);
}

