#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("marouen");//inserer nom de l'utilisateur
db.setPassword("12345");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;



    return  test;
}
