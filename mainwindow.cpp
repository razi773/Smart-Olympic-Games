#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>
#include"notification.h"
#include"widget.h"
//#include"ui_camera.h"
#include "joueurs.h"
#include "jeux.h"
#include <QSystemTrayIcon>
#include "notification.h"
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QDate>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>
#include "ui_widget.h"
#include"admin.h"

#include "QDebug"

#include <QSystemTrayIcon>
#include <QDate>
#include"joueurs.h"

employe j;
Joueurs J;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView->setModel(j.afficher());
     ui->le_id_2->setValidator(new QIntValidator(0,9999999,this));
     ui->tableView_3->setModel(j.afficher());
     ui->le_id->setValidator(new QIntValidator(0,9999999,this));
     ui->tableView_4->setModel(J.afficher());
         Joueurs J;
         int ret=A1.connect_arduino(); // lancer la connexion à arduino
           switch(ret){
           case(0):qDebug()<< "arduino is available and connected to : "<< A1.getarduino_port_name();
               break;
           case(1):qDebug() << "arduino is available but not connected to :" <<A1.getarduino_port_name();
              break;
           case(-1):qDebug() << "arduino is not available";
           }
            QObject::connect(A1.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer //gamrouha blh
            //le slot update_label suite à la reception du signal readyRead (reception des données).
       }




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //ajout employe
{
    Notification N;
    int id=ui->le_id->text().toUInt();
      QString nom=ui->le_nom->text();
      QString prenom=ui->le_prenom->text();
      QString grade=ui->le_grade->text();
      QString email=ui->le_email->text();
      int age=ui->le_age->text().toUInt();
      ui->le_nom->setMaxLength(5); // max longueur de nom (line_edit)
              ui->le_prenom->setMaxLength(20);
              ui->le_id->setMaxLength(6);
      employe j(id,age,nom,prenom,grade,email);

      bool test=j.ajouter();
      if(test)
      {

          N.notification_ajoutemploye();
          ui->tableView->setModel( j.afficher());
          QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
          j.ajouter_OP("employe ajoute",QDate::currentDate());
      }
      else  QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                     QObject::tr("ajout non effectue\n"
                                                 "click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_5_clicked() //supprimer employe
{

    bool i;
       int id_del;

        Notification N;
       id_del=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();

       i=j.supprimer(id_del);
       if(i)
       {

           N.notification_supprimeremploye();
           ui->tableView->setModel(j.afficher());
           QMessageBox::information(nullptr, QObject::tr("OK"),
                       QObject::tr("suppression effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           j.ajouter_OP("employe supprime",QDate::currentDate());

   }
       else
          { QMessageBox::critical(nullptr, QObject::tr("not OK"),
                       QObject::tr("problème de suppression.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel); }
}



void MainWindow::on_pushButton_4_clicked() //modifier employe
{
    Notification N;
    int id=ui->le_id->text().toInt();
        QString nom=ui->le_nom->text();
        QString prenom=ui->le_prenom->text();
        QString grade=ui->le_grade->text();

        QString email=ui->le_email->text();
          int age=ui->le_age->text().toInt();



        ui->le_nom->setMaxLength(5); // max longueur
                ui->le_prenom->setMaxLength(20);
                ui->le_id->setMaxLength(6);


        employe j(id,age,nom,prenom,grade,email);

        bool test=j.modifierEmploye(j.getid(),j.getage(),j.getnom(),j.getprenom(),j.getgrade(),j.getemail());

        QMessageBox msgBox;

        if(test)
            {
            N.notification_modifieremploye();
                msgBox.setText("Modification avec succes.");
                ui->tableView->setModel(j.afficher());
                 j.ajouter_OP("employe modifie",QDate::currentDate());
            }
        else
            msgBox.setText("Echec de Modification!!!!!!");
            msgBox.exec();

}

void MainWindow::on_pushButton_7_clicked() //chercher
{
    /*chercher
          employe J1;
          QString rech=ui->rech_2->text();
          if (rech=="")
           ui->tableView->setModel(J1.afficher());
          else
              ui->tableView->setModel(J1.rechercher(rech));*/

}



void MainWindow::on_pushButton_8_clicked() //statistique emplye
{


    QSqlQueryModel * model= new QSqlQueryModel();
                         model->setQuery("select * from employe where AGE < 30 ");
                         float age=model->rowCount();
                         model->setQuery("select * from employe where AGE  between 30 and 35 ");
                         float agee=model->rowCount();
                         model->setQuery("select * from employe where AGE >35 ");
                         float ageee=model->rowCount();
                         float total=age+agee+ageee;
                         QString a=QString("moins de 30 ans "+QString::number((age*100)/total,'f',2)+"%" );
                         QString b=QString("entre 30 et 35 Ans"+QString::number((agee*100)/total,'f',2)+"%" );
                         QString c=QString("+35 Ans"+QString::number((ageee*100)/total,'f',2)+"%" );
                         QPieSeries *series = new QPieSeries();
                         series->append(a,age);
                         series->append(b,agee);
                         series->append(c,ageee);
                 if (age!=0)
                 {QPieSlice *slice = series->slices().at(0);
                  slice->setLabelVisible();
                  slice->setPen(QPen());}
                 if ( agee!=0)
                 {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabelVisible();
                 }
                 if(ageee!=0)
                 {
                          // Add labels to rest of slices
                          QPieSlice *slice2 = series->slices().at(2);
                          //slice1->setExploded();
                          slice2->setLabelVisible();
                 }
                         // Create the chart widget
                         QChart *chart = new QChart();
                         // Add data to chart with title and hide legend
                         chart->addSeries(series);
                         chart->setTitle("Pourcentage Par Age :Nombre Des employe "+ QString::number(total));
                         chart->legend()->hide();
                         // Used to display the chart
                         QChartView *chartView = new QChartView(chart);
                         chartView->setRenderHint(QPainter::Antialiasing);
                         chartView->resize(1000,500);
                         chartView->show();

}

void MainWindow::on_imprimer_clicked()//imprime employe
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView->model()->rowCount();
                     const int columnCount = ui->tableView->model()->columnCount();
                     QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                     out <<"<html>\n"
                           "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         << "<title>ERP - COMmANDE LIST<title>\n "
                         << "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                         "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  licence commerciale ******"+TT+" </strong></h1>"
                         "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                           "</br> </br>";
                     // headers
                     out << "<thead><tr bgcolor=#d6e5ff>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView->isColumnHidden(column)) {
                                 QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);

                     QPrinter printer;

                     QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                     if (dialog->exec() == QDialog::Accepted) {
                         document->print(&printer);
                     }

                     delete document;

}

void MainWindow::on_pushButton_9_clicked()
{

   Widget  w ;
    w.setModal(true);
    w.exec();
}

void MainWindow::on_pushbutton_13_clicked()
{
    employe A;
    ui->stackedWidget->setCurrentIndex(1);
   ui->tableView_2->setModel(A.afficher_OP());
}


void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
   /* if(ui->comboBox->currentText()=="Tri par id")
        {
            ui->tableView->setModel(j.trierEmployeParid());
        }else if(ui->comboBox->currentText()=="Tri par Nom")
        {
            ui->tableView->setModel(j.trierEmployeParNom());
        }else
        {
            ui->tableView->setModel(j.trierEmployeParage());
        }*/
}
/*
void MainWindow::on_trie_id_clicked()
{
    employe j;
          ui->tableView->setModel(j.trier());
}

void MainWindow::on_trie_nom_clicked()
{
    employe j;
          ui->tableView->setModel(j.trier1());
}

void MainWindow::on_trie_prenom_clicked()
{
    employe j;
          ui->tableView->setModel(j.trier2());
}

*/
void MainWindow::on_rech_2_textChanged(const QString &arg1)//recherche employe
{
    ui->tableView->setModel(j.Recherche(arg1));
}


void MainWindow::on_comboBox_activated()//trier employe
{
    if (ui->comboBox->currentText()=="Tri Par ID")
    {
        ui->tableView->setModel(j.trierEmployeParid());
    }
    else if(ui->comboBox->currentText()=="Tri Par Nom")
    {
        ui->tableView->setModel(j.trierEmployeParNom());
    }
    else
    {
        ui->tableView->setModel(j.trierEmployeParAge());
    }
}


void MainWindow::on_Push_Button_Afficher_clicked()
{
    ui->tableView->setModel(j.afficher());
}
//trier joueurs





void MainWindow::on_pushButton_15_clicked() //fichier pdf joueurs
{
    QPdfWriter pdf("C:\\Users\\Razi\\Desktop\\marwenn\\PDF_Joueurs.pdf");

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


void MainWindow::on_pushButton_16_clicked()//ficher xl joueurs
{
    QString nomFile=ui->fichier->text();
    QMessageBox msg;
    if(!nomFile.length()){

        msg.setText("entrer le nom du fichier");
        msg.exec();
    }
    else{
    QFile file("C:/Users/Razi/Desktop/marwenn/exel"+nomFile+".csv");
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


void MainWindow::verif_mdp_arduino()
{
    data+= A1.read_from_arduino();
               if (data.length()>=5){
           qDebug() << data<<endl;
           QSqlQueryModel *model=new QSqlQueryModel();
           model->setQuery("select * from ADMIN where MDP="+data);
           if (model->rowCount()==0){
               A1.write_to_arduino("0");
               data="";
           }else{
               QByteArray nom = model->data(model->index(0,1)).toByteArray();
               A1.write_to_arduino("1");

   data="";
           }
   }
}

void MainWindow::on_pushButton_17_clicked()
{
        Notification n;
       int id=ui->le_id_2->text().toInt();
       QString nom=ui->le_nom_2->text();
       QString prenom=ui->le_prenom_2->text();
       int age=ui->le_age_2->text().toInt();
       QString email=ui->le_email_2->text();
       QString pays=ui->le_pays_2->text();

       Joueurs J(id,nom,prenom,age,email,pays);
       bool test1=J.ajouter();
            if(test1)
             {   n.notification_ajoute();

                QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                           QObject::tr("ajout successful.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
                        ui->tableView_4->setModel(J.afficher());
                       }

                           else
                               QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                           QObject::tr("ajout failed.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_supp_id_2_clicked()
{
   /*Joueurs J1; J1.setid(ui->le_id->text().toInt());
        bool test1=J1.supprimer(J1.getid());
        QMessageBox msgBox;
        if(test1)
            msgBox.setText("suppression avec succes .");

        msgBox.setText("Echec .");
        msgBox.exec();*/
            Joueurs J1;
            Notification n;
                J1.setid_2(ui->supp->text().toInt());
                bool test;
                test=J1.supprimer(J1.getid_2());
                if(test)

                 {  n.notification_supprimer();
                    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                               QObject::tr("sup successful.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);

            ui->tableView_4->setModel(J1.afficher());
                }else
                                      QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                                  QObject::tr("sup failed.\n"
                                                              "Click Cancel to exit."), QMessageBox::Cancel);

    }


void MainWindow::on_pushButton_25_clicked()
{
    Notification n;

            int id=ui->le_id_2->text().toInt();
            QString nom=ui->le_nom_2->text();
            QString prenom=ui->le_prenom_2->text();
            int age=ui->le_age_2->text().toInt();
            QString email=ui->le_email_2->text();
            QString pays=ui->le_pays_2->text();



            Joueurs J1(id,nom,prenom,age,email,pays);

            bool test=J1.modifier(J1.getid_2(),J1.getnom_2(),J1.getprenom_2(),J1.getage_2(),J1.getemail_2(),J1.getpays_2());

            QMessageBox msgBox;

            if(test)
                {   n.notification_modifier();
                    msgBox.setText("Modification avec succes.");
                    ui->tableView_4->setModel(J1.afficher());
                }
            else
                msgBox.setText("Echec de Modification!!!!!!");
                msgBox.exec();
}

void MainWindow::on_pushButton_21_clicked()
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



void MainWindow::on_pushButton_22_clicked()
{
        QPdfWriter pdf("C:\\Users\\Marwen.M\\Desktop\\integration\\PDF_Joueurs.pdf");

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




void MainWindow::on_pushButton_19_clicked()
{
    QString nomFile=ui->fichier_2->text();
    QMessageBox msg;
    if(!nomFile.length()){

        msg.setText("entrer le nom du fichier");
        msg.exec();
    }
    else{
    QFile file("C:/Users/Marwen.M/Desktop/integration"+nomFile+".csv");
    QString finalmsg="fichier modifie avec succes";
     if(!file.exists()){
     finalmsg="fichier cree avec succes";
     }
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream txt(&file);
    for(int i=0;i<100;i++){

    QString ID_JOUEUR= ui->tableView_4->model()->index(i,0).data().toString();
    QString nom= ui->tableView_4->model()->index(i,1).data().toString();
    QString prenom= ui->tableView_4->model()->index(i,2).data().toString();
    QString age= ui->tableView_4->model()->index(i,3).data().toString();
    QString email= ui->tableView_4->model()->index(i,4).data().toString();
    QString pays= ui->tableView_4->model()->index(i,5).data().toString();

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


void MainWindow::on_rech_4_clicked()
{
    Joueurs J1;
          QString rech=ui->rech_2->text();
          if (rech=="")
           ui->tableView_4->setModel(J1.afficher());
          else
          ui->tableView_4->setModel(J1.rechercher(rech));
          ui->tableView_4->setModel(J1.rechercher1(rech));
          ui->tableView_4->setModel(J1.rechercher2(rech));

      }


void MainWindow::on_pushButton_24_clicked()
{
    Joueurs J1;
          ui->tableView_4->setModel(J1.trier());
}

void MainWindow::on_pushButton_23_clicked()
{
    Joueurs J1;
          ui->tableView_4->setModel(J1.trier1());
}

void MainWindow::on_pushButton_18_clicked()
{
    Joueurs J1;
          ui->tableView_4->setModel(J1.trier2());
}

void MainWindow::on_rech_5_textEdited(const QString &arg1)
{
    Joueurs J1;
    ui->tableView_4->setModel(J1.rechercher3(arg1));
}

void MainWindow::on_pushButton_38_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_36_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_26_clicked()
{
    int mdp=ui->mdp1->text().toInt();
    ADMIN A (mdp);
    bool test2=A.ajouter1();
         if(test2)
          {
             QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                        QObject::tr("ajout successful.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                    }

                        else
                            QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                        QObject::tr("ajout failed.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_27_clicked()
{
    int id=ui->le_id_4->text().toInt();
        QString nom=ui->le_nom_4->text();
         int nb_participant=ui->le_nb_parti->text().toInt();
         ui->le_id_4->setMaxLength(5); // max longueur de nom (line_edit)
          ui->le_nom_4->setMaxLength(20);
          ui->le_nb_parti->setMaxLength(4);
        Jeux j2(id,nom,nb_participant);
        bool test=j2.ajouter3();
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                        QObject::tr(" successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
                            ui->tableView_5->setModel(j2.afficher());

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("erreur"),
                        QObject::tr(" erreur.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

}



void MainWindow::on_pushButton_31_clicked()
{
    Jeux j2;
    j2.setid_3(ui->le_id_suppri->text().toInt());

          bool test=j2.supprimer(j2.getid_3());
          if (test==true)
          {ui->tableView_5->setModel(j2.afficher());

              QMessageBox::information(nullptr, QObject::tr("supression avec succes"),
                          QObject::tr(" successful.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

          }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("erreur"),
                          QObject::tr(" erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void MainWindow::on_pushButton_41_clicked()
{
    ui->le_id_3->clear();
        ui->le_nom_3->clear();
        ui->le_nb_parti->clear();
        ui->le_id_cherch->clear();
}


void MainWindow::on_pushButton_33_clicked()
{
    int id= ui->le_id_3->text().toInt();//conversion QString to in
            QString nom=ui->le_nom_3->text();
            int nb_participant=ui->le_nb_parti->text().toInt();

                     Jeux j2(id,nom,nb_participant);
                    bool test=j2.modifier(id,nom,nb_participant);//appel a la methode modifier
                    if (test)
                {


                QMessageBox::information(nullptr,QObject::tr("OK"),
                        QObject::tr("Modification effectuée\n"
                                    "Click Cancel non to exit.") , QMessageBox :: Cancel);

                 ui->tableView_5->setModel((j2.afficher()));

                }
                else
                    QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                          QObject::tr("Modification non effectuée.\n"
                                                      "Click Cancel to exit."),QMessageBox::Cancel);
                ui->tableView_5->setModel((j2.afficher()));
        }






void MainWindow::on_le_id_cherch_cursorPositionChanged(int arg1, int arg2)
{
    QString i=ui->le_id_cherch->text();
           ui->tableView_5->setModel(j2.rechercheMulticritere(i));
}



void MainWindow::on_comboBox_6_activated(const QString &arg1)
{
    Jeux J2;
          ui->tableView_5->setModel(J2.trier());
}



void MainWindow::on_pushButton_32_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
           QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("select * from JEUX where NB_PART >2 ");
           float salaire=model->rowCount();
           model->setQuery("select * from EMPLOYE where NB_part=1 ");
           float salairee=model->rowCount();

   float total=salaire+salairee;

   QString a=QString("Plus de 2 joueurs . "+QString::number((salaire*100)/total,'f',2)+"%" );
   QString b=QString("Jeux individuel.  "+QString::number((salairee*100)/total,'f',2)+"%" );

   QPieSeries *series = new QPieSeries();
   series->append(a,salaire);
   series->append(b,salairee);

   if (salaire!=0)
   {QPieSlice *slice = series->slices().at(0);
       slice->setLabelVisible();//AFFICHER slice
       slice->setPen(QPen());}
   if ( salairee!=0)
   {
       // Add label, explode and define brush for 2nd slice
       QPieSlice *slice1 = series->slices().at(1);
       //slice1->setExploded();
       slice1->setLabelVisible();
   }

   // Create the chart widget
   QChart *chart = new QChart();
   // Add data to chart with title and hide legend
   chart->addSeries(series); // widget
   chart->setTitle("STATISTIQUE DES EMPLOYEES SELON AGE  "+ QString::number(total));
   chart->legend()->hide();
   // Used to display the chart
   QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
   chartView->setRenderHint(QPainter::Antialiasing);
   chartView->resize(1000,500);
   chartView->show();
   }



void MainWindow::on_pushButton_29_clicked()
{
    Jeux J2;
        ui->tableView_5->setModel(J2.trier1());
}

void MainWindow::on_pushButton_40_clicked()
{
    Jeux J2;
        ui->tableView_5->setModel(J2.trier2());
}

void MainWindow::on_pushButton_28_clicked()
{
    QString nomFile=ui->fichier_3->text();
        QMessageBox msg;
        if(!nomFile.length()){

            msg.setText("entrer le nom du fichier");
            msg.exec();
        }
        else{
            QFile file("C:/Users/Marwen.M/Desktop/integration"+nomFile+".csv");
            QString finalmsg="fichier modifie avec succes";
            if(!file.exists()){
                finalmsg="fichier crée avec succes";
            }
            file.open(QFile::WriteOnly | QFile::Text);
            QTextStream txt(&file);
            for(int i=0;i<100;i++){

                QString ID_JEUX= ui->tableView_5->model()->index(i,0).data().toString();
                QString NOM= ui->tableView_5->model()->index(i,1).data().toString();
                QString NB_PART= ui->tableView_5->model()->index(i,2).data().toString();


                if(ID_JEUX.length()){

                    txt<< "ID_JEUX    '"+ ID_JEUX +"' \n";
                    txt<< "NOM          '"+ NOM +"' \n";
                    txt<< "NB_PART        '"+ NB_PART +"' \n";

                }
            }
            msg.setText(finalmsg);
            msg.exec();
            file.close();
        }
}

void MainWindow::on_pushButton_39_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_35_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}
