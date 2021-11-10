#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>

employe::employe()
{
id=0; nom="";prenom="";grade="";;email="";
}

employe::employe(int i,QString n,QString p,QString a,QString e)
{
   id=i;
   nom=n;
   prenom=p;
   grade=a;
   email=e;
}
int employe::getid(){return id;}
QString employe::getnom(){return nom;}
QString employe::getprenom(){return prenom;}
QString employe::getgrade(){return grade;}
QString employe::getemail(){return email;}

void employe::setid(int id){this->id=id;}
void employe::setnom(QString nom){this->nom=nom;}
void employe::setprenom(QString prenom){this->prenom=prenom;}
void employe::setgrade (QString grade){this->grade=grade;}
void employe::setemail(QString email){this->email=email;}
bool employe::ajouter()
{

QSqlQuery query;
QString id_string= QString::number(id);
query.prepare("INSERT INTO employe (id,nom,prenom,grade,email) "
              "VALUES (:id, :nom, :prenom,:grade,:email)");
query.bindValue(0, id_string );
query.bindValue(1,nom);
query.bindValue(2, prenom);
query.bindValue(3, grade );
query.bindValue(4, email);
return query.exec();

}
QSqlQueryModel * employe::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("grade"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));

    return  model;

}
bool employe::supprimer(int id)
{
   /* QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare(" delete from employe where id=id ");

    query.bindValue(0,id);


    return query.exec();*/

        QSqlQuery query;
        query.prepare("delete from employe where id=:id");
        query.bindValue(0,id);
        return query.exec();

}
bool employe::modifierEmploye(int id,QString nom,QString prenom,QString grade,QString email)

{



    QSqlQuery query;

    query.prepare("update EMPLOYE set nom=:nom,prenom=:prenom,grade=:grade,email=:email where id=:id");

    query.bindValue(":id",id);

    query.bindValue(":nom",nom);

    query.bindValue(":prenom",prenom);

    query.bindValue(":grade",grade);



    query.bindValue(":email",email);



    return query.exec();



}
