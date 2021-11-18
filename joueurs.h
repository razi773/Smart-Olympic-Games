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
    Joueurs (int,QString,QString,int,QString,QString);
        //getters
        int getid();
        QString getnom();
        QString getprenom();
        int getage();
        QString getemail();
        QString getpays();

        //settlers

        void setid(int);
        void setnom(QString);
        void setprenom(QString);
        void setage (int);
        void setemail(QString);
        void setpays(QString);


        //Fonctionnalités de bd
        bool verifierCin_aj(int);
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int ID_JOUEUR,QString nom,QString prenom,int age,QString email,QString pays);
        QSqlQueryModel * trier();
        QSqlQueryModel * trier1();
        QSqlQueryModel * trier2();
        QSqlQueryModel* rechercher(QString nom);
        QSqlQueryModel* rechercher1(QString prenom);
        QSqlQueryModel* rechercher2(QString pays);
        QSqlQueryModel* rechercher3(QString a);






    private:
        int id,age;
        QString nom,prenom,email,pays;

};

#endif // JOUEURS_H
