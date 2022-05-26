#ifndef SAVELOGINUSER_H
#define SAVELOGINUSER_H

#include "mainwindow.h"
#include <QString>
class SaveLoginUser
{
public:
    SaveLoginUser();

    void setUserFormation(QString user_num,QString user_name,QString user_type);

public:
    static QString user_num;
    static QString user_name;
    static QString user_type;
};

#endif // SAVELOGINUSER_H
