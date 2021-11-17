#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDate>

employe::employe()
{
id=0; nom="";prenom="";grade="";;email="";
}

employe::employe(int i,int ag,QString n,QString p,QString a,QString e)
{
   id=i;
   age=ag;
   nom=n;
   prenom=p;
   grade=a;
   email=e;
}
int employe::getid(){return id;}
int employe::getage(){return age;}
QString employe::getnom(){return nom;}
QString employe::getprenom(){return prenom;}
QString employe::getgrade(){return grade;}
QString employe::getemail(){return email;}

void employe::setid(int id){this->id=id;}
void employe::setage(int age){this->age=age;}
void employe::setnom(QString nom){this->nom=nom;}
void employe::setprenom(QString prenom){this->prenom=prenom;}
void employe::setgrade (QString grade){this->grade=grade;}
void employe::setemail(QString email){this->email=email;}



bool employe::ajouter()
{

QSqlQuery query;
QString id_string= QString::number(id);
query.prepare("INSERT INTO employe (id,nom,prenom,grade,email,age) "
              "VALUES (:id, :nom, :prenom,:grade,:email,:age)");
query.bindValue(0, id_string ); //affecter le valeur dans bd
query.bindValue(1,nom);
query.bindValue(2, prenom);
query.bindValue(3, grade );
query.bindValue(4, email);
query.bindValue(5,age);
return query.exec();

}
QSqlQueryModel * employe::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("grade"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("age"));

    return  model;

}


bool employe::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM employe WHERE ID= :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool employe::modifierEmploye(int id,int age,QString nom,QString prenom,QString grade,QString email)

{



    QSqlQuery query;

    query.prepare("update EMPLOYE set nom=:nom,prenom=:prenom,grade=:grade,email=:email,age=:age where id=:id");

    query.bindValue(":id",id);
    query.bindValue(":age",age);

    query.bindValue(":nom",nom);

    query.bindValue(":prenom",prenom);

    query.bindValue(":grade",grade);



    query.bindValue(":email",email);



    return query.exec();



}






//Trie Par id
QSqlQueryModel * employe::trierEmployeParid()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM EMPLOYE order by id ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par Nom
QSqlQueryModel * employe::trierEmployeParNom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM EMPLOYE order by nom ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par prenom
QSqlQueryModel * employe::trierEmployeParAge()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM EMPLOYE order by age ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


//-------------------------------------------------------------------------

QSqlQueryModel * employe::Recherche(QString a)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe WHERE (ID LIKE '%"+a+"%' OR NOM LIKE '%"+a+"%' OR prenom LIKE '%"+a+"%' OR grade LIKE '%"+a+"%' OR email LIKE '%"+a+"%' OR age LIKE '%"+a+"%' ) ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("grade"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("age"));

    return model;
}

bool employe::ajouter_OP(QString nom, QDate dateaa)
{
    QSqlQuery query;
    query.prepare("INSERT INTO HISTORIQUE(NOM,DATEA)""VALUES (:nom,:datea)");
    query.bindValue(":nom",nom);
    query.bindValue(":datea",dateaa);

    return query.exec();
}

QSqlQueryModel * employe::afficher_OP()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM HISTORIQUE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));


    return model;
}












