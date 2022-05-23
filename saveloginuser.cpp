#include "saveloginuser.h"
#include "QDebug"
SaveLoginUser::SaveLoginUser()
{
}

void SaveLoginUser::setUserFormation(QString user_num, QString user_name, QString user_type)
{
    this->user_num = user_num;
    this->user_name = user_name;
    this->user_type = user_type;
}

QString SaveLoginUser::getUserNum()
{
    return this->user_num;
}

QString SaveLoginUser::getUserName()
{
    return this->user_name;
}

QString SaveLoginUser::getUserType()
{
    return this->user_type;
}
