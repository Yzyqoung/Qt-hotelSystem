#include "mainwindow.h"
#include <QApplication>
#include "./SQL_CONFIG/sql_connect.h"
#include "./LOG_CONFIG/log.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(createConnection());
    logSysInit("log.txt");
    //打印日志到文件中
    qDebug("This is a debug message");
    w.show();
    return a.exec();
}
