#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include"historique.h"


class employe
{
public:
    employe();

    employe(int,int,QString,QString,QString,QString);


            int getid();
            int getage();
            QString getnom();
            QString getprenom();
            QString getgrade();
            QString getemail();
                 void getid(int);
                 void getnom(QString);
                 void getprenom(QString);
                 void getgrade (QString);
                 void getemail(QString);

                 void setid(int);
                 void setage(int);
                        void setnom(QString);
                        void setprenom(QString);
                        void setgrade (QString);
                        void setemail(QString);
                 bool ajouter();
                        QSqlQueryModel * afficher();
                        bool supprimer(int);
                        bool modifierEmploye(int id,int age,QString nom,QString prenom,QString grade,QString email);
                       int chercheremploye(int id);
                       QSqlQueryModel * trierEmployeParid();
                       QSqlQueryModel * trierEmployeParNom();
                       QSqlQueryModel * trierEmployeParAge();
                        QSqlQueryModel * Recherche(QString);




                               QSqlQueryModel* rechercher(QString nom);


                               bool ajouter_OP(QString,QDate);
                               QSqlQueryModel * afficher_OP();




                    private:
                        int id,age;
                        QString nom,prenom,grade,email;
};

#endif // EMPLOYE_H
