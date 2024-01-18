#include "deletetask.h"
#include "ui_deletetask.h"
#include"menu.h"
#include"mainwindow.h"
#include"addtask.cpp"
#include"LinkedList.h"
deletetask::deletetask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletetask)
{
    ui->setupUi(this);
    //Form's Background should be added here through picture's path on laptop
    //QPixmap bkgnd("C:/Users/Heba Magdy/OneDrive/Desktop/DataStructuresFinalProject/QTBackgrounds/task-management.jpg");
            //bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
            //QPalette palette;
            //palette.setBrush(QPalette::Background, bkgnd);
            //this->setPalette(palette);

    if(mainw.linkedname=="Mohamed"){
        Node<task>* tmp = mo.head;
        for(int i=0;i< mo.count;i++){
            ui->comboBox->addItem(QString::fromStdString (tmp->data.TaskTitle));
            tmp=tmp->next;

        }
    }
    else if(mainw.linkedname=="Ahmed"){
        Node<task>* tmp = am.head;
        for(int i=0;i< am.count;i++){
            ui->comboBox->addItem(QString::fromStdString (tmp->data.TaskTitle));
            tmp=tmp->next;

        }

    }
    else {
        Node<task>* tmp = hs.head;
        for(int i=0;i< hs.count;i++){
            ui->comboBox->addItem(QString::fromStdString (tmp->data.TaskTitle));
            tmp=tmp->next;

        }
}}

deletetask::~deletetask()
{
    delete ui;
}
 menu *mn;
void deletetask::on_pushButton_clicked()
{
    this->hide();
    mn= new menu(this);
    mn->show();
}


void deletetask::on_comboBox_currentTextChanged(const QString &arg1)
{     if(mainw.linkedname=="Mohamed"){
        Node<task>* tmp = mo.head;
        for(int i=0;i< mo.count;i++){
            if(tmp->data.TaskTitle==arg1.toStdString()){
            ui->desc->setText(QString::fromStdString(tmp->data.Description));
            QString s = QString::number(tmp->data.PriorityValues);
            ui->prt->setText(s);
            ui->red->setText(QString::fromStdString(tmp->data.RequiredEndingDate));}
            tmp=tmp->next;
        }
    }

    else if(mainw.linkedname=="Ahmed"){
            Node<task>* tmp = am.head;
            for(int i=0;i< am.count;i++){
                if(tmp->data.TaskTitle==arg1.toStdString()){
                ui->desc->setText(QString::fromStdString(tmp->data.Description));
                QString s = QString::number(tmp->data.PriorityValues);
                ui->prt->setText(s);
                ui->red->setText(QString::fromStdString(tmp->data.RequiredEndingDate));}
                tmp=tmp->next;
            }
        }
    else
     {
        Node<task>* tmp = hs.head;
        for(int i=0;i< hs.count;i++){
            if(tmp->data.TaskTitle==arg1.toStdString()){
          ui->desc->setText(QString::fromStdString(tmp->data.Description));
          QString s = QString::number(tmp->data.PriorityValues);
          ui->prt->setText(s);
          ui->red->setText(QString::fromStdString(tmp->data.RequiredEndingDate));}
          tmp=tmp->next;
      }
    }


}
void deletetask::on_pushButton_2_clicked()
{
    if(mainw.linkedname=="Mohamed"){
        mo.DeleteAt(ui->comboBox->currentIndex());
        if(mo.count!=0){
            mo.Insert_sorted_descending();
            mo.DateSorting();
            ui->comboBox->removeItem(ui->comboBox->currentIndex());
        }
        else{
             QMessageBox::information(this,"Well Done!","You've Successfully Completed All Your Tasks!");
                       this->hide();
                        mn= new menu(this);
                        mn->show();


                }


            if(!mo.Empty()){
            QMessageBox::information(this,"Reminder!",QString::fromStdString(mo.Reminder()));
    }
        }else if(mainw.linkedname=="Ahmed"){
        am.DeleteAt(ui->comboBox->currentIndex());
        if(am.count!=0){
            am.Insert_sorted_descending();
            am.DateSorting();
            ui->comboBox->removeItem(ui->comboBox->currentIndex());
             }
        else{
             QMessageBox::information(this,"Well Done!","You've Successfully Completed All Your Tasks!");

                        this->hide();
                        mn= new menu(this);
                        mn->show();


                }

            if(!am.Empty()){
            QMessageBox::information(this,"Reminder!",QString::fromStdString(am.Reminder()));
    }

        }else{
        hs.DeleteAt(ui->comboBox->currentIndex());
        if(hs.count!=0){
            hs.Insert_sorted_descending();
            hs.DateSorting();
            ui->comboBox->removeItem(ui->comboBox->currentIndex());

            }
        else{
            QMessageBox::information(this,"Well Done!","You've Successfully Completed All Your Tasks!");
            this->hide();
            mn= new menu(this);
            mn->show();}


            if(!hs.Empty()){
            QMessageBox::information(this,"Reminder!",QString::fromStdString(hs.Reminder()));}

    }
}

void deletetask::on_pushButton_3_clicked()
{
    if(mainw.linkedname=="Mohamed"){
                Node<task>* tmp = mo.head;
                for(int i=0;i< mo.count;i++){

                if(QString::fromStdString(tmp->data.TaskTitle) == ui->comboBox->currentText()){
                   tmp->data.Description = ui->desc->text().toStdString();
                   if(ui->prt->text().toInt()>10||ui->prt->text().toInt()<1){
                       QMessageBox::warning(this,"Invalid Priority Value","Please enter an integer between 1 and 10.");
                   }else{

                   tmp->data.PriorityValues = ui->prt->text().toInt();}
                   tmp->data.RequiredEndingDate = ui->red->text().toStdString();
                   mo.Insert_sorted_descending();
                   mo.DateSorting();
                   ui->comboBox->clear();
                   Node<task>* tmp = mo.head;
                   for(int i=0;i< mo.count;i++){
                       ui->comboBox->addItem(QString::fromStdString (tmp->data.TaskTitle));
                       tmp=tmp->next;}
                   QMessageBox::information(this,"Task Edit","Task Edited Successfully");
                   break;
                    }else{
                    tmp=tmp->next;
                }
                }
    }else if(mainw.linkedname=="Ahmed"){
                Node<task>* tmp = am.head;
                for(int i=0;i< am.count;i++){

                if(QString::fromStdString(tmp->data.TaskTitle) == ui->comboBox->currentText()){
                   tmp->data.Description = ui->desc->text().toStdString();
                   if(ui->prt->text().toInt()>10||ui->prt->text().toInt()<1){
                       QMessageBox::warning(this,"Invalid Priority Value","Please enter an integer between 1 and 10.");
                   }else{

                   tmp->data.PriorityValues = ui->prt->text().toInt();}
                   tmp->data.RequiredEndingDate = ui->red->text().toStdString();
                   am.Insert_sorted_descending();
                   am.DateSorting();
                   ui->comboBox->clear();
                   Node<task>* tmp = am.head;
                   for(int i=0;i< am.count;i++){
                       ui->comboBox->addItem(QString::fromStdString (tmp->data.TaskTitle));
                       tmp=tmp->next;}
                   QMessageBox::information(this,"Task Edit","Task Edited Successfully");
                   break;
                    }else{
                    tmp=tmp->next;
                }
                }
    }    else {
            Node<task>* tmp = hs.head;
            for(int i=0;i< hs.count;i++){

            if(QString::fromStdString(tmp->data.TaskTitle) == ui->comboBox->currentText()){
               tmp->data.Description = ui->desc->text().toStdString();
               if(ui->prt->text().toInt()>10||ui->prt->text().toInt()<1){
                   QMessageBox::warning(this,"Invalid Priority Value","Please enter an integer between 1 and 10.");
               }else{
               tmp->data.PriorityValues = ui->prt->text().toInt();}
               tmp->data.RequiredEndingDate = ui->red->text().toStdString();
               hs.Insert_sorted_descending();
               hs.DateSorting();
               ui->comboBox->clear();
               Node<task>* tmp = hs.head;
               for(int i=0;i< hs.count;i++){
                   ui->comboBox->addItem(QString::fromStdString (tmp->data.TaskTitle));
                   tmp=tmp->next;}
               QMessageBox::information(this,"Task Edit","Task Edited Successfully");
               break;
                }else{
                tmp=tmp->next;
            }
            }
    }
}
