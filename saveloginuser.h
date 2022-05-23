#ifndef SAVELOGINUSER_H
#define SAVELOGINUSER_H

#include "mainwindow.h"
#include <QString>
class SaveLoginUser
{
public:
    SaveLoginUser();

    void setUserFormation(QString user_num,QString user_name,QString user_type);

    QString getUserNum();

    QString getUserName();

    QString getUserType();
public:
    QString user_num;
    QString user_name;
    QString user_type;
};

#endif // SAVELOGINUSER_H
