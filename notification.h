#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include<QString>
class notification
{
public:
    notification();
    void notification_ajoute();

    void notification_supprimer();

    void notification_modifier();
};

#endif // NOTIFICATION_H
