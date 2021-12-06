#include "admin.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <arduino.h>
ADMIN::ADMIN()
{
    mdp=0;
}

ADMIN::ADMIN(int m)
{
    mdp=m;
}

int ADMIN::getmdp(){return mdp;}
void ADMIN::setmdp(int mdp){this->mdp=mdp;}


bool ADMIN::ajouter1()
{
QSqlQuery query;
query.prepare("INSERT INTO ADMIN (MDP)"
              "VALUES (:MDP)");
query.bindValue(0, mdp);
return query.exec();

}

QSqlQueryModel* ADMIN::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM ADMIN ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("MDP"));

          return model;
 }




//select * from admin where mdp=mdp(data);
