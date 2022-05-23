#include "mainwindow.h"
#include <QApplication>
#include "./SQL_CONFIG/sql_connect.h"
#include "./LOG_CONFIG/log.h"
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //初始化有顺序，添加初始化需要分析顺序后再添加

    //日志初始化
    //logSysInit("log.txt");

    //数据库初始化
    sql_init();


    MainWindow mainwindow;
    mainwindow.show();

    return a.exec();
}
