/***************************************************************
 *文件名称：数据库连接
 *简要描述：用于数据库的连接配置
 *
 *当前版本：V1.0
 *作者：Young
 *创作日期：2022/4/22
 *说明：Email:578706463@qq.com
*****************************************************************/
#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
/*
 *函数功能：创建数据表并链接
 *说明：此函数可以进行链接数据库，若链接不上，给出最后的错误提示
*/
static bool sql_init()
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL"); //创建一个数据库

    db.setHostName("127.0.0.1");                            //本地地址（若要远程链接，输入相应的地址）
    db.setPort(3306);                                       //设置端口号
    db.setDatabaseName("hotel");                            //设置数据库的名字
    db.setUserName("root");                                 //设置用户名字
    db.setPassword("123456");                               //设置密码
    if(!db.open())
    {
        qCritical("Can't open database: %s(%s)",
                  db.lastError().text().toLocal8Bit().data(),
                  qt_error_string().toLocal8Bit().data());
        return false;
    }
    qDebug()<<"Open database success!";
    return true;
}

/*
 *函数功能：断开数据库链接
*/
static bool sql_close()
{
    Q_UNUSED(sql_close())
    QSqlDatabase::database().close();
    qDebug()<<"close database!";
    return 1;
}

#endif // CONNECTION_H
