#ifndef JOUEURS_H
#define JOUEURS_H
#include<QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>


class Joueurs
{
public:
    Joueurs();
    Joueurs (int,QString,QString,int,QString);
        //getters
        int getid();
        QString getnom();
        QString getprenom();
        int getage();
        QString getemail();

        //settlers

        void setid(int);
        void setnom(QString);
        void setprenom(QString);
        void setage (int);
        void setemail(QString);

        //Fonctionnalités de bd
        bool verifierCin_aj(int);
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int ID_JOUEUR,QString nom,QString prenom,int age,QString email);
        QSqlQueryModel * trier();
        //QSqlQueryModel* rechercher(QString nom);




    private:
        int id,age;
        QString nom,prenom,email;

};

#endif // JOUEURS_H
