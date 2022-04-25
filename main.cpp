#include "mainwindow.h"
#include <QApplication>
#include "./SQL_CONFIG/sql_connect.h"
#include "./LOG_CONFIG/log.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //数据库初始化
    sql_init();

    //日志初始化
    logSysInit("log.txt");


    w.show();
    return a.exec();
}
