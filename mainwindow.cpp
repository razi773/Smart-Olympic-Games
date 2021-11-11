#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "joueurs.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999999,this));
    ui->tableView->setModel(J.afficher());
    Joueurs J;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int age=ui->le_age->text().toInt();
    QString email=ui->le_email->text();
    Joueurs j(id,nom,prenom,age,email);
    bool test1=j.ajouter();
         if(test1)
          {   QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                        QObject::tr("ajout successful.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->tableView->setModel(J.afficher());
                    }

                        else
                            QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                        QObject::tr("ajout failed.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }

void MainWindow::on_supp_id_clicked()
{
    /*Joueurs J1; J1.setid(ui->le_id->text().toInt());
    bool test1=J1.supprimer(J1.getid());
    QMessageBox msgBox;
    if(test1)
        msgBox.setText("suppression avec succes .");

    msgBox.setText("Echec .");
    msgBox.exec();*/
        Joueurs J1;
            J1.setid(ui->supp->text().toInt());
            bool test;
            test=J1.supprimer(J1.getid());
            if(test)
             {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                           QObject::tr("sup successful.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView->setModel(J1.afficher());
            }else
                                  QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                              QObject::tr("sup failed.\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);
   }



/*void MainWindow::on_pushButton_3_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}
*/

void MainWindow::on_pushButton_10_clicked()
{
            int id=ui->le_id->text().toInt();
            QString nom=ui->le_nom->text();
            QString prenom=ui->le_prenom->text();
            int age=ui->le_age->text().toInt();
            QString email=ui->le_email->text();


            Joueurs J1(id,nom,prenom,age,email);

            bool test=J1.modifier(J1.getid(),J1.getnom(),J1.getprenom(),J1.getage(),J1.getemail());

            QMessageBox msgBox;

            if(test)
                {
                    msgBox.setText("Modification avec succes.");
                    ui->tableView->setModel(J1.afficher());
                }
            else
                msgBox.setText("Echec de Modification!!!!!!");
                msgBox.exec();
}


void MainWindow::on_pushButton_12_clicked()
{
    /*trie*/
    Joueurs J1;
      ui->tableView->setModel(J1.trier());



}
