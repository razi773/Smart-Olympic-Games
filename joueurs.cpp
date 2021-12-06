#include "joueurs.h"
#include "notification.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Joueurs::Joueurs()
{
id=0; nom="";prenom="";age=0;;email="";pays="";
}



Joueurs::Joueurs(int i,QString n,QString p,int a,QString e,QString y)
{
   id=i;
   nom=n;
   prenom=p;
   age=a;
   email=e;
   pays=y;
}



int Joueurs::getid_2() {return id;}
QString Joueurs::getnom_2(){return nom;}
QString Joueurs::getprenom_2(){return prenom;}
int Joueurs::getage_2(){return age;}
QString Joueurs::getemail_2(){return email;}
QString Joueurs::getpays_2(){return pays;}

void Joueurs::setid_2(int id){this->id=id;}
void Joueurs::setnom_2(QString nom){this->nom=nom;}
void Joueurs::setprenom_2(QString prenom){this->prenom=prenom;}
void Joueurs::setage_2 (int age){this->age=age;}
void Joueurs::setemail_2(QString email){this->email=email;}
void Joueurs::setpays_2(QString pays){this->pays=pays;}


/*bool Joueurs::verifierCin_aj(int id)
{
    QSqlQuery query;
    bool test=true;
    QString identifiant_J_string=QString::number(id);
    query.prepare("select * from joueurs where identifiant=id");
    query.bindValue(":identifiant_J",identifiant_J_string);

    if (query.exec()&&query.next())
    {
        test=false;
        return test;
    }
    return test;
}*/
bool Joueurs::ajouter()
{

QSqlQuery query;
QString id_string= QString::number(id);
QString age_string= QString::number(age);
query.prepare("INSERT INTO joueurs (ID_JOUEUR,nom,prenom,age,email,pays) "
              "VALUES (:id, :nom, :prenom,:age,:email,:pays)");
query.bindValue(0, id_string );
query.bindValue(1,nom);
query.bindValue(2, prenom);
query.bindValue(3, age_string );
query.bindValue(4, email);
query.bindValue(5, pays);

return query.exec();

}

bool Joueurs::supprimer(int ID_JOUEUR)
{
   /* QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare(" delete from Joueurs where id=id ");

    query.bindValue(0,id);


    return query.exec();*/

        QSqlQuery query;
        query.prepare("delete from JOUEURS where ID_JOUEUR=:ID_JOUEUR");
        query.bindValue(0,ID_JOUEUR);
        return query.exec();

}

QSqlQueryModel* Joueurs::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM Joueurs");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("pays"));


          return model;
 }


bool Joueurs::modifier(int ID_JOUEUR,QString nom,QString prenom,int age,QString email,QString pays)

{

    QSqlQuery query;

    query.prepare("update Joueurs set nom=:nom,prenom=:prenom,age=:age,email=:email,pays=:pays where ID_JOUEUR=:ID_JOUEUR");

    query.bindValue(":ID_JOUEUR",ID_JOUEUR);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":email",email);
    query.bindValue(":pays",pays);


    return query.exec();

}


QSqlQueryModel *Joueurs:: trier(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Joueurs  order by ID_JOUEUR desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("pays"));

return  model ;
}


QSqlQueryModel *Joueurs:: trier1(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Joueurs  order by nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("pays"));

return  model ;
}

QSqlQueryModel *Joueurs:: trier2(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Joueurs  order by prenom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("pays"));

return  model ;
}



QSqlQueryModel *Joueurs::rechercher(QString nom){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Joueurs WHERE(nom='"+nom+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("pays"));
return  model ;

}


QSqlQueryModel *Joueurs::rechercher1(QString prenom){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Joueurs WHERE(prenom='"+prenom+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("pays"));
return  model ;

}


QSqlQueryModel *Joueurs::rechercher2(QString pays){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Joueurs WHERE(pays='"+pays+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("pays"));
return  model ;

}

QSqlQueryModel *Joueurs::rechercher3(QString a)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Joueurs WHERE (ID_JOUEUR LIKE '%"+a+"%' OR nom LIKE '%"+a+"%' OR prenom LIKE '%"+a+"%' OR age LIKE '%"+a+"%' OR email LIKE '%"+a+"%' OR pays LIKE '%"+a+"%' ) ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_JOUEUR"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("pays"));

    return model;
}
