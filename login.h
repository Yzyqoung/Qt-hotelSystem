#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QWidget>
#include <QMessageBox>
#include <QStackedWidget>
#include <QSqlTableModel>
#include "SQL_CONFIG/sql_connect.h"
#include "mainwindow.h"
#include "saveloginuser.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    //保存当前的用户和密码
    void WriteCurrentUser(QString username,QString userpwd );

    //检查表是有内容
    int FindTableIsEmpty(QString tablename);

    //删除表中内容
    void DeleteTableContent(QString tablename);

    void saveLoginUser(QString user_num);

protected:
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下移动
private slots:
    void on_btnLogin_clicked();

    void on_btn_close_clicked();

    void on_btn_min_clicked();

private:
    Ui::Login *ui;
    QPoint p;
    int total;

    QSqlDatabase db;
    QSqlQuery *query;
    QRect location;
    QPoint mousePoint;
    bool mousePressed;
};

#endif // LOGIN_H
