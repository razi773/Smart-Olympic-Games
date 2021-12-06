#ifndef ADMIN_H
#define ADMIN_H
#include<QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
    class ADMIN
    {
    public:
        ADMIN();
        ADMIN (int);
            //getters
            int getmdp();
            void setmdp(int);

            bool ajouter1();
            QSqlQueryModel * afficher();


    private:
        int mdp;
        QByteArray data;

};

#endif // ADMIN_H
