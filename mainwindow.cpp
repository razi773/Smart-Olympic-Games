#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "notification.h"
#include "joueurs.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>
#include <QPainter>
#include <QPdfWriter>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tableView->setModel(J.afficher());
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
    notification n;
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int age=ui->le_age->text().toInt();
    QString email=ui->le_email->text();
    QString pays=ui->le_pays->text();

    Joueurs j(id,nom,prenom,age,email,pays);
    bool test1=j.ajouter();
         if(test1)
          {   n.notification_ajoute();

             QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
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
        notification n;
            J1.setid(ui->supp->text().toInt());
            bool test;
            test=J1.supprimer(J1.getid());
            if(test)

             {  n.notification_supprimer();
                QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
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
    notification n;

            int id=ui->le_id->text().toInt();
            QString nom=ui->le_nom->text();
            QString prenom=ui->le_prenom->text();
            int age=ui->le_age->text().toInt();
            QString email=ui->le_email->text();
            QString pays=ui->le_pays->text();



            Joueurs J1(id,nom,prenom,age,email,pays);

            bool test=J1.modifier(J1.getid(),J1.getnom(),J1.getprenom(),J1.getage(),J1.getemail(),J1.getpays());

            QMessageBox msgBox;

            if(test)
                {   n.notification_modifier();
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



void MainWindow::on_rech_clicked()
{
    /*chercher*/
       Joueurs J1;
       QString rech=ui->rech_2->text();
       if (rech=="")
        ui->tableView->setModel(J1.afficher());
       else
       ui->tableView->setModel(J1.rechercher(rech));
       ui->tableView->setModel(J1.rechercher1(rech));
       ui->tableView->setModel(J1.rechercher2(rech));




   }


void MainWindow::on_pushButton_8_clicked()
{
    Joueurs J1;
      ui->tableView->setModel(J1.trier1());
}

void MainWindow::on_pushButton_9_clicked()
{
    Joueurs J1;
      ui->tableView->setModel(J1.trier2());
}

void MainWindow::on_pushButton_13_clicked()
{
    {
        QPdfWriter pdf("C:\\Users\\Marwen.M\\Desktop\\Atelier_Connexion\\pdf\\PDF_Joueurs.pdf");

       QPainter painter(&pdf);
       int i = 4000;
              painter.setPen(Qt::red);
              painter.setFont(QFont("Time New Roman", 25));
              painter.drawText(3000,1400,"Liste Des Joueurs");
              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,100,9400,2500); // dimension ta3 rectangle eli fih liste
              painter.drawRect(100,3000,9400,500);
              painter.setFont(QFont("Time New Roman", 9));
              painter.drawText(400,3300,"ID_JOUEUR");
              painter.drawText(1350,3300,"nom");
              painter.drawText(2200,3300,"prenom");
              painter.drawText(3400,3300,"age");
              painter.drawText(4400,3300,"email");
              painter.drawText(6200,3300,"pays");
              painter.drawRect(100,3000,9400,9000);

              QSqlQuery query;
              query.prepare("select * from Joueurs");
              query.exec();
              while (query.next())
              {
                  painter.drawText(400,i,query.value(0).toString());
                  painter.drawText(1350,i,query.value(1).toString());
                  painter.drawText(2300,i,query.value(2).toString());
                  painter.drawText(3400,i,query.value(3).toString());
                  painter.drawText(4400,i,query.value(4).toString());
                  painter.drawText(6200,i,query.value(5).toString());



                 i = i + 350;
              }
              QMessageBox::information(this, QObject::tr("PDF Enregistré"),
              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void MainWindow::on_pushButton_11_clicked()
{

            //ui->stackedWidget_2->setCurrentIndex(1);
               QSqlQueryModel * model= new QSqlQueryModel();
               model->setQuery("select * from Joueurs where age < 18 ");
               float age1=model->rowCount();
               model->setQuery("select * from Joueurs where age  between 18 and 40 ");
               float age2=model->rowCount();
               model->setQuery("select * from Joueurs where age > 40 ");
               float age3=model->rowCount();
               float total=age1+age2+age3;

               QString a=QString("entre 18 et 30 . "+QString::number((age1*100)/total,'f',2)+"%" );
               QString b=QString("entre 30 et 40 age.  "+QString::number((age2*100)/total,'f',2)+"%" );
               QString c=QString("plus de 40 age.   "+QString::number((age3*100)/total,'f',2)+"%" );

               QPieSeries *series = new QPieSeries();//PieSeries object calculates the percentage the actual size of the slice in the chart.
               series->append(a,age1);
               series->append(b,age2);//concatiner 2 chaines
               series->append(c,age3);
               if (age1!=0)
               {QPieSlice *slice = series->slices().at(0);//the percentage the actual slice
                   slice->setLabelVisible();
                   slice->setPen(QPen(Qt::red));}
               if ( age2!=0)
               {
                   // Add label, explode and define brush for 2nd slice
                   QPieSlice *slice1 = series->slices().at(1);
                   //slice1->setExploded();
                   slice1->setLabelVisible();
               }
               if(age3!=0)
               {
                   // Add labels to rest of slices
                   QPieSlice *slice2 = series->slices().at(2);
                   //slice1->setExploded();
                   slice2->setLabelVisible();// Sets the label visibility for all contours in the collection
               }
               // Create the chart widget
               QChart *chart = new QChart();
               // Add data to chart with title and hide legend
               chart->addSeries(series); // widget
               chart->setTitle("liste des Joueurs par age "+ QString::number(total));
               chart->legend()->hide();
               // Used to display the chart
               QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(1000,500);
               chartView->show();

}

void MainWindow::on_pushButton_14_clicked()
{

    QString nomFile=ui->fichier->text();
    QMessageBox msg;
    if(!nomFile.length()){

        msg.setText("entrer le nom du fichier");
        msg.exec();
    }
    else{
    QFile file("C:/Users/Marwen.M/Desktop/Atelier_Connexion/exel"+nomFile+".csv");
    QString finalmsg="fichier modifie avec succes";
     if(!file.exists()){
     finalmsg="fichier cree avec succes";
     }
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream txt(&file);
    for(int i=0;i<100;i++){

    QString ID_JOUEUR= ui->tableView->model()->index(i,0).data().toString();
    QString nom= ui->tableView->model()->index(i,1).data().toString();
    QString prenom= ui->tableView->model()->index(i,2).data().toString();
    QString age= ui->tableView->model()->index(i,3).data().toString();
    QString email= ui->tableView->model()->index(i,4).data().toString();
    QString pays= ui->tableView->model()->index(i,5).data().toString();

    if(ID_JOUEUR.length()){

    txt<< "ID_JOUEUR    '"+ ID_JOUEUR +"' \n";
    txt<< "nom           '"+ nom +"' \n";
    txt<< "prenom        '"+ prenom +"' \n";
    txt<< "age          '"+ age +"' \n";
    txt<< "email          '"+ email +"' \n";
    txt<< "pays         '"+ pays +"' \n \n";
    }
    }
    msg.setText(finalmsg);
    msg.exec();
    file.close();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    Joueurs J1;
    ui->tableView->setModel(J1.rechercher3(arg1));
}
