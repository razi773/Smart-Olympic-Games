#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>


class employe
{
public:
    employe();

    employe(int,QString,QString,QString,QString);


            int getid();
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
                        void setnom(QString);
                        void setprenom(QString);
                        void setgrade (QString);
                        void setemail(QString);
                 bool ajouter();
                        QSqlQueryModel * afficher();
                        bool supprimer(int);
                        bool modifierEmploye(int id,QString nom,QString prenom,QString grade,QString email);

                    private:
                        int id;
                        QString nom,prenom,grade,email;
};

#endif // EMPLOYE_H
