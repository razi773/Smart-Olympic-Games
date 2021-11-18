#include "notification.h"

#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification::notification_ajoute()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Joueurs ","nouveau ajouter ",QSystemTrayIcon::Information,15000);
}

void notification::notification_supprimer(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Joueurs ","nouveau supprimer",QSystemTrayIcon::Information,15000);
}


void notification::notification_modifier(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Joueurs ","nouveau modifier",QSystemTrayIcon::Information,15000);
}
