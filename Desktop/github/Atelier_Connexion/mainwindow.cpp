#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>
#include"notification.h"
#include"widget.h"
//#include"ui_camera.h"

#include <QSystemTrayIcon>

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


#include <QSystemTrayIcon>
#include <QDate>

employe j;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView->setModel(j.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //ajout
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

void MainWindow::on_pushButton_5_clicked() //supprimer
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




void MainWindow::on_pushButton_4_clicked() //modifier
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



void MainWindow::on_pushButton_8_clicked()
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

void MainWindow::on_imprimer_clicked()
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

void MainWindow::on_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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
void MainWindow::on_rech_2_textChanged(const QString &arg1)
{
    ui->tableView->setModel(j.Recherche(arg1));
}

void MainWindow::on_comboBox_activated()
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

void MainWindow::on_pushButton_2_clicked()
{
    //ui->tableView_2->setModel(tmphistorique.afficherHistorique());

}
