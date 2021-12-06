#ifndef JEUX_H
#define JEUX_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QVariant>
#include "connection.h"
class Jeux
{
public:
    Jeux();
    Jeux(int,QString,int);
    int getid_3();
    QString getnom_3();
    int getnb_participant();
                     void getid_3(int);
                     void getnom_3(QString);
                     void getnb_participant(int);

                     void setid_3(int);
                      void setnom_3(QString);
                       void setnb_participant(int);
    bool ajouter3();
  bool modifier(int id,QString nom,int nb_participant);
    bool supprimer(int);
     QSqlQueryModel * rechercheMulticritere(QString rech);
     QSqlQueryModel * trier();
    QSqlQueryModel * trier1();
    QSqlQueryModel * trier2();
     void fadeIn();
     void fadeOut();
//QSqlQueryModel* rechercher(QString nom);
    QSqlQueryModel* afficher();
private:
    int id;
    QString nom;
    int nb_participant;
    QString rech;
};

#endif // JEUX_H
