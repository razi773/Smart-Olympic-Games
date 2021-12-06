#include "jeux.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include "connection.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QObject"
#include "QGraphicsOpacityEffect"
#include "QPropertyAnimation"
Jeux::Jeux()
{
id=0;nom="";nb_participant=0;
}
Jeux::Jeux(int id,QString nom,int nb_participant)
{
    this->id=id;
    this->nom=nom;
    this->nb_participant=nb_participant;
}
int Jeux::getid_3(){return id;}
QString Jeux::getnom_3(){return nom;}
int Jeux::getnb_participant(){return nb_participant;}
void Jeux::setid_3(int id){this->id=id;}
void Jeux::setnom_3(QString nom){this->nom=nom;}
void Jeux::setnb_participant(int nb_participant){this->nb_participant=nb_participant;}



bool Jeux::ajouter3()

{
    QString id_string=QString::number(id);
    //QString nb_participant_string=QString::number(nb_participant);
    QSqlQuery query;
    query.prepare("INSERT INTO JEUX (ID_JEUX,NOM,NB_PART) "
                  "VALUES (:ID_JEUX, :NOM, :NB_PART)");
    query.bindValue(":ID_JEUX",id);
    query.bindValue(":NOM",nom);
    query.bindValue(":NB_PART",nb_participant);
    return query.exec();
}
QSqlQueryModel* Jeux::afficher()
{

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM Jeux");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_JEUX"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB_PART"));

    return model;
}
bool Jeux::supprimer(int id)
{
     QString id_string=QString::number(id);
    QSqlQuery query;
    query.prepare("delete from JEUX where ID_JEUX=:ID_JEUX");
    query.bindValue(0,id);
    return query.exec();
}
bool Jeux::modifier(int id,QString nom,int nb_participant)
{
    QSqlQuery query;
QString id_string=QString::number(id);
    query.prepare("update JEUX set ID_JEUX=:ID_JEUX, NOM=:nom,NB_PART=:NB_PART WHERE ID_JEUX=:ID_JEUX");
    query.bindValue(":ID_JEUX",id);
    query.bindValue(":NOM",nom);
   query.bindValue(":NB_PART",nb_participant);


    return query.exec();
}

//QSqlQueryModel *Jeux::rechercher(QString nom)
//{
    //QSqlQueryModel *model=new QSqlQueryModel();
    //model->setQuery("select* from JEUX where(NOM='"+nom+"')");
    //model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JEUX"));
    //model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
//model->setHeaderData(2, Qt::Horizontal,QObject::tr("NB_PART"));

//return  model ;

//}
QSqlQueryModel* Jeux::rechercheMulticritere(QString rech){
    QSqlQueryModel* trouve = new QSqlQueryModel();

    trouve->setQuery("SELECT * FROM JEUX WHERE NOM LIKE '"+rech+"%' OR ID_JEUX LIKE '"+rech+"%'OR NB_PART LIKE '"+rech+"%'");
    trouve->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_JEUX"));
    trouve->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    trouve->setHeaderData(2,Qt::Horizontal,QObject::tr("NB_PART"));



    return trouve;
}




QSqlQueryModel *Jeux:: trier(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from JEUX  order by NB_PART");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JEUX"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("NB_PART"));
//QTableView *view=new QTableView;
//view->setModel(model);
//view->show();

return  model ;
}


QSqlQueryModel *Jeux:: trier1(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from JEUX  order by NOM ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JEUX"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("NB_PART"));

return  model ;
}

QSqlQueryModel *Jeux:: trier2(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from JEUX  order by ID_JEUX ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JEUX"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("NB_PART"));


return  model ;
}


/*
QSqlQueryModel *Joueurs::rechercher(QString nom){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Joueurs WHERE(nom='"+nom+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("pays"));
return  model


void fadeIn(){
QGraphicsOpacityEffect* effect=new QGraphicsOpacityEffect();

QPropertyAnimation* a=new QPropertyAnimation(effect,"opacity");
a->setDuration(1000);  // in miliseconds
a->setStartValue(0);
a->setEndValue(1);
a->setEasingCurve(QEasingCurve::InBack);
a->start(QPropertyAnimation::DeleteWhenStopped);
this->label->show();
connect(this->timer,&QTimer::timeout,this,&Notifier::fadeOut);
this->timer->start(2000);
}
void fadeOut(){
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect();
    this->label->setGraphicsEffect(effect);
    QPropertyAnimation *a = new QPropertyAnimation(effect,"opacity");
    a->setDuration(1000); // it will took 1000ms to face out
    a->setStartValue(1);
    a->setEndValue(0);
    a->setEasingCurve(QEasingCurve::OutBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a,SIGNAL(finished()),this->label,SLOT(hide()));
*/
