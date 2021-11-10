#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->le_id->text().toUInt();
      QString nom=ui->le_nom->text();
      QString prenom=ui->le_prenom->text();
      QString grade=ui->le_grade->text();
      QString email=ui->le_email->text();
      employe j(id,nom,prenom,grade,email);

      bool test=j.ajouter();
      if(test)
      {   ui->tableView->setModel( j.afficher());
          QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
      }
      else  QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                     QObject::tr("ajout non effectue\n"
                                                 "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{

    employe j;
                j.setid(ui->supp->text().toInt());
                bool test;
                test=j.supprimer(j.getid());
                if(test)
                 {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                               QObject::tr("sup successful.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);

            ui->tableView->setModel(j.afficher());

    }else
                    QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                QObject::tr("sup failed.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->le_id->text().toInt();
        QString nom=ui->le_nom->text();
        QString prenom=ui->le_prenom->text();
        QString grade=ui->le_grade->text();

        QString email=ui->le_email->text();


        employe j(id,nom,prenom,grade,email);

        bool test=j.modifierEmploye(j.getid(),j.getnom(),j.getprenom(),j.getgrade(),j.getemail());

        QMessageBox msgBox;

        if(test)
            {
                msgBox.setText("Modification avec succes.");
                ui->tableView->setModel(j.afficher());
            }
        else
            msgBox.setText("Echec de Modification!!!!!!");
            msgBox.exec();

}
