#include "saveloginuser.h"
#include "QDebug"

QString SaveLoginUser::user_name = "";
QString SaveLoginUser::user_num = "";
QString SaveLoginUser::user_type = "";


SaveLoginUser::SaveLoginUser()
{
}

void SaveLoginUser::setUserFormation(QString user_num, QString user_name, QString user_type)
{
    SaveLoginUser::user_num = user_num;
    SaveLoginUser::user_name = user_name;
    SaveLoginUser::user_type = user_type;
}
