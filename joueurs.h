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
        int getid_2();
        QString getnom_2();
        QString getprenom_2();
        int getage_2();
        QString getemail_2();
        QString getpays_2();

        //settlers

        void setid_2(int);
        void setnom_2(QString);
        void setprenom_2(QString);
        void setage_2 (int);
        void setemail_2(QString);
        void setpays_2(QString);


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
